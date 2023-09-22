using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using MySql.Data.MySqlClient;
using System.Data.SQLite;
using System.Globalization;
using System.Windows.Forms.DataVisualization.Charting;



namespace stock
{
    public partial class Form2 : Form
    {
        private Point mousePoint;
        private List<Label> menws;
        private List<Color> menw_colors;
        string mysqlConnectionString = ConfigurationManager.ConnectionStrings["MySQL"].ConnectionString;
        string sqliteConnectionString = ConfigurationManager.ConnectionStrings["SQLite"].ConnectionString;
        private string connectionString; // 연결 문자열을 저장할 변수

        public Form2(string connectionString)
        {
            InitializeComponent();
            // Form2의 생성자에서 연결 문자열을 받아 저장합니다.
            this.connectionString = connectionString;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // DataGridView에 데이터 바인딩
            BindData();
            BindStockData();

            menws = new List<Label>();
            menws.Add(btn_Menu1);
            menws.Add(btn_Menu2);
            menws.Add(btn_Menu3);
            menws.Add(btn_Menu4);

            menw_colors = new List<Color>();
            menw_colors.Add(Color.FromArgb(53, 124, 225));
            menw_colors.Add(Color.DarkOrange);
            menw_colors.Add(Color.FromArgb(177, 70, 194));
            menw_colors.Add(Color.LimeGreen);

            //시작 TabPage 설정
            Tab_Main.SelectedIndex = 0;

            if (connectionString == mysqlConnectionString)
            {
                // MySQL 데이터베이스 정보 저장
                ConfigurationManager.AppSettings["SelectedDatabase"] = "MySQL";

                // MySQL 데이터베이스에 연결하는 코드

                // 선택한 날짜를 설정
                string selectedDateStr = ConfigurationManager.AppSettings["MySQLSelectedDate"];
                if (DateTime.TryParseExact(selectedDateStr, "yyyy-MM-dd", CultureInfo.InvariantCulture, DateTimeStyles.None, out DateTime selectedDate))
                {
                    date_label.Text = selectedDate.ToString("yyyy-MM-dd");
                }
            }
            else
            {
                // SQLite 데이터베이스 정보 저장
                ConfigurationManager.AppSettings["SelectedDatabase"] = "SQLite";

                // SQLite 데이터베이스에 연결하는 코드

                // 선택한 날짜를 설정
                string selectedDateStr = ConfigurationManager.AppSettings["SQLiteSelectedDate"];
                if (DateTime.TryParseExact(selectedDateStr, "yyyy-MM-dd", CultureInfo.InvariantCulture, DateTimeStyles.None, out DateTime selectedDate))
                {
                    date_label.Text = selectedDate.ToString("yyyy-MM-dd");
                }
            }
        }

        private void setMenuChange(int index)
        {
            if (Tab_Main.SelectedIndex != index)
            {
                menws[Tab_Main.SelectedIndex].ForeColor = Color.FromArgb(111, 111, 111);
                menws[index].ForeColor = menw_colors[index];
                Tab_Menu_Select_Bar.BackColor = menw_colors[index];
                Tab_Menu_Select_Bar.Location = new Point(menws[index].Location.X, 46);
                Tab_Main.SelectedIndex = index;
            }
        }

        private void btn_Menu1_Click(object sender, EventArgs e)
        {
            setMenuChange(0);
        }

        private void btn_Menu2_Click(object sender, EventArgs e)
        {
            setMenuChange(1);
        }

        private void btn_Menu3_Click(object sender, EventArgs e)
        {
            setMenuChange(2);
        }

        private void btn_Menu4_Click(object sender, EventArgs e)
        {
            setMenuChange(3);

            Dictionary<string, double> productAverageDailySales = GetDataFromDatabase();

            // Chart 컨트롤에 데이터 바인딩
            chart1.Series.Clear(); // 기존의 시리즈를 지우고 새로운 시리즈 생성
            chart1.Series.Add("평균판매수");

            chart1.Series["평균판매수"].ChartType = SeriesChartType.Column;
            chart1.Series["평균판매수"].Points.DataBind(productAverageDailySales, "Key", "Value", "");

            // 차트의 제목 설정
            chart1.Titles.Clear(); // 기존의 제목을 지우고 새로운 제목 추가
            Title title = new Title();
            title.Text = "최근 7일 판매량";
            chart1.Titles.Add(title);
        }

        private void closebutton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Tab_Menu_Back_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }

        private void Tab_Menu_Back_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int x = mousePoint.X - e.X;
                int y = mousePoint.Y - e.Y;
                Location = new Point(this.Left - x, this.Top - y);
            }
        }

        private Dictionary<string, double> GetDataFromDatabase()
        {
            Dictionary<string, double> productAverageDailySales = new Dictionary<string, double>();

            if (connectionString == mysqlConnectionString)
            {
                using (MySqlConnection connection = new MySqlConnection(connectionString))
                {
                    connection.Open();

                    // 최근 7일 동안의 판매 데이터를 가져오는 SQL 쿼리
                    string query = @"
                    SELECT product_code, SUM(count) AS total_sales
                    FROM Stock
                    WHERE type = '판매'
                    AND datetime >= DATE_SUB(@selectedDate, INTERVAL 7 DAY)  -- 최근 7일 조건 추가
                    GROUP BY product_code";

                    using (MySqlCommand command = new MySqlCommand(query, connection))
                    {
                        // @selectedDate 매개 변수 설정
                        command.Parameters.AddWithValue("@selectedDate", date_label.Text);

                        using (MySqlDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                string productCode = reader.GetString("product_code");
                                double totalSales = reader.GetDouble("total_sales");

                                // 평균 하루 판매수 계산 
                                double averageDailySales = -totalSales / 7.0;

                                // 결과를 Dictionary에 추가
                                productAverageDailySales.Add(productCode, averageDailySales);
                            }
                        }
                    }
                }
            }
            else
            { //sqlite 
                using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
                {
                    connection.Open();

                    // 최근 7일 동안의 판매 데이터를 가져오는 SQL 쿼리
                    string query = @"
                    SELECT product_code, SUM(count) AS total
                    FROM Stock
                    WHERE type = '판매'
                    AND date >= DATE(@selectedDate, '-7 days')  -- 최근 7일 조건 추가
                    GROUP BY product_code";

                    using (SQLiteCommand command = new SQLiteCommand(query, connection))
                    {
                        // @selectedDate 매개 변수 설정 (SQLite에서는 ISO 8601 형식의 날짜 문자열을 사용)
                        command.Parameters.AddWithValue("@selectedDate", DateTime.Parse(date_label.Text).ToString("yyyy-MM-dd"));

                        using (SQLiteDataReader reader = command.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                string productCode = reader["product_code"].ToString();
                                int total = Convert.ToInt32(reader["total"]);

                                // 평균 하루 판매수 계산 (예: 7일 기준)
                                double averageDailySales = -total / 7.0;

                                // 결과를 Dictionary에 추가
                                productAverageDailySales.Add(productCode, averageDailySales);
                            }
                        }
                    }
                }

            }

            return productAverageDailySales;
        }

        private void BindData()
        {
            if (connectionString == mysqlConnectionString)
            {
                try
                {
                    string mysqlConnectionString = ConfigurationManager.ConnectionStrings["MySQL"].ConnectionString;

                    using (MySqlConnection connection = new MySqlConnection(mysqlConnectionString))
                    {
                        connection.Open();

                        string query = "SELECT code, name, cost, price, category FROM Products";
                        using (MySqlCommand command = new MySqlCommand(query, connection))
                        {
                            using (MySqlDataAdapter adapter = new MySqlDataAdapter(command))
                            {
                                DataSet dataSet = new DataSet();
                                adapter.Fill(dataSet, "Products");
                                dataGridView1.DataSource = dataSet.Tables["Products"];
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("데이터를 가져오는 중 오류 발생: " + ex.Message);
                }
            }
            else
            {
                try
                {
                    // SQLite 데이터베이스 연결 문자열 가져오기
                    string sqliteConnectionString = ConfigurationManager.ConnectionStrings["SQLite"].ConnectionString;

                    // SQLite 데이터베이스 연결
                    using (SQLiteConnection sqliteConnection = new SQLiteConnection(sqliteConnectionString))
                    {
                        sqliteConnection.Open();

                        string query = "SELECT code, name, cost, price, category FROM Products"; // 원하는 필드만 선택

                        using (SQLiteCommand command = new SQLiteCommand(query, sqliteConnection))
                        {
                            using (SQLiteDataAdapter adapter = new SQLiteDataAdapter(command))
                            {
                                DataSet dataSet = new DataSet();
                                adapter.Fill(dataSet, "Products");
                                dataGridView1.DataSource = dataSet.Tables["Products"];
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("데이터를 가져오는 중 오류 발생: " + ex.Message);
                }
            }
        }

        private void BindStockData()
        {
            if (connectionString == mysqlConnectionString)
            {
                try
                {
                    string mysqlConnectionString = ConfigurationManager.ConnectionStrings["MySQL"].ConnectionString;

                    using (MySqlConnection connection = new MySqlConnection(mysqlConnectionString))
                    {
                        connection.Open();

                        string query = "SELECT s.product_code, SUM(s.count) AS stock, p.name, p.cost, p.price " +
                                        "FROM Stock s " +
                                        "INNER JOIN Products p ON s.product_code = p.code " +
                                        "GROUP BY s.product_code, p.name, p.cost, p.price";
                        using (MySqlCommand command = new MySqlCommand(query, connection))
                        {
                            using (MySqlDataAdapter adapter = new MySqlDataAdapter(command))
                            {
                                DataSet dataSet = new DataSet();
                                adapter.Fill(dataSet, "Stock");


                                dataGridView2.DataSource = dataSet.Tables["Stock"];
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("데이터를 가져오는 중 오류 발생: " + ex.Message);
                }
            }
            else
            {
                try
                {
                    // SQLite 데이터베이스 연결 문자열 가져오기
                    string sqliteConnectionString = ConfigurationManager.ConnectionStrings["SQLite"].ConnectionString;

                    // SQLite 데이터베이스 연결
                    using (SQLiteConnection sqliteConnection = new SQLiteConnection(sqliteConnectionString))
                    {
                        sqliteConnection.Open();

                        string query = "SELECT s.product_code, SUM(s.count) AS current_stock, p.name, p.cost, p.price " +
                                        "FROM Stock s " +
                                        "INNER JOIN Products p ON s.product_code = p.code " +
                                        "GROUP BY s.product_code, p.name, p.cost, p.price";

                        using (SQLiteCommand command = new SQLiteCommand(query, sqliteConnection))
                        {
                            using (SQLiteDataAdapter adapter = new SQLiteDataAdapter(command))
                            {
                                DataSet dataSet = new DataSet();
                                adapter.Fill(dataSet, "Products");
                                dataGridView2.DataSource = dataSet.Tables["Products"];
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("데이터를 가져오는 중 오류 발생: " + ex.Message);
                }
            }
        }

        private void register_button_Click_1(object sender, EventArgs e)
        {
            string code = code_textbox.Text;
            string name = name_textbox.Text;
            int cost = Convert.ToInt32(cost_textbox.Text);
            int price = Convert.ToInt32(price_textbox.Text);
            string category = category_textbox.Text;

            if (connectionString == mysqlConnectionString)
            {
                try
                {
                    MySQLClass mySQLInstance = new MySQLClass(mysqlConnectionString);
                    Interface stockItemInstance = mySQLInstance;
                    stockItemInstance.RegisterItem(code, name, cost, price, category);
                    System.Diagnostics.Debug.WriteLine("데이터가 상품테이블에 삽입되었습니다.");
                    MessageBox.Show("상품등록 완료");
                    BindData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 삽입 중 오류 발생: " + ex.Message);
                }
            }
            else
            {
                try
                {
                    SQLiteClass sqliteInstance = new SQLiteClass(sqliteConnectionString);
                    Interface stockItemInstance = sqliteInstance;
                    stockItemInstance.RegisterItem(code, name, cost, price, category);
                    System.Diagnostics.Debug.WriteLine("데이터가 상품테이블에 삽입되었습니다.");
                    MessageBox.Show("상품등록 완료");
                    BindData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 삽입 중 오류 발생: " + ex.Message);
                }
            }
            code_textbox.Clear();
            name_textbox.Clear();
            cost_textbox.Clear();
            price_textbox.Clear();
            category_textbox.Clear();
        }

        private void next_date_Click(object sender, EventArgs e)
        {
            if (DateTime.TryParseExact(date_label.Text, "yyyy-MM-dd", CultureInfo.InvariantCulture, DateTimeStyles.None, out DateTime currentDate))
            {
                currentDate = currentDate.AddDays(1);
                date_label.Text = currentDate.ToString("yyyy-MM-dd");

                System.Diagnostics.Debug.WriteLine("다음 날짜 클릭: " + currentDate.ToString());

                // 설정에 선택한 날짜 저장
                Configuration config = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

                if (connectionString == mysqlConnectionString)
                {
                    config.AppSettings.Settings["MySQLSelectedDate"].Value = currentDate.ToString("yyyy-MM-dd");
                    MySQLClass mySQLInstance = new MySQLClass(mysqlConnectionString);
                    mySQLInstance.RandomSale(currentDate);
                }
                else
                {
                    string sqliteDate = currentDate.ToString("yyyy-MM-dd"); // SQLite에서 사용할 형식으로 날짜를 문자열로 변환
                    config.AppSettings.Settings["SQLiteSelectedDate"].Value = sqliteDate;
                    SQLiteClass sqliteInstance = new SQLiteClass(sqliteConnectionString);
                    sqliteInstance.RandomSale(sqliteDate); // 날짜를 문자열로 변환
                }

                config.Save(ConfigurationSaveMode.Modified);
                ConfigurationManager.RefreshSection("appSettings");

                if (connectionString != mysqlConnectionString)
                {
                    using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
                    {
                        connection.Close();
                    }
                }

                BindStockData();
            }
            else
            {
                MessageBox.Show("날짜 형식이 올바르지 않습니다.");
            }
        }

        private void order_button_Click(object sender, EventArgs e)
        {
            string code = code_order_textbox.Text;
            string type = "구매";
            int count = Convert.ToInt32(cnt_order_textbox.Text);

            if (connectionString == mysqlConnectionString)
            {
                DateTime date = Convert.ToDateTime(date_label.Text);
                DateTime exp = Convert.ToDateTime(exp_order_textbox.Text);
                try
                {
                    MySQLClass mySQLInstance = new MySQLClass(mysqlConnectionString);
                    mySQLInstance.OrderItem(date, code, exp, type, count);
                    System.Diagnostics.Debug.WriteLine("데이터가 재고테이블에 삽입되었습니다.");
                    MessageBox.Show("주문완료");
                    BindStockData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 삽입 중 오류 발생: " + ex.Message);
                }
            }
            else
            {
                string date = date_label.Text;
                string exp = exp_order_textbox.Text;
                try
                {
                    SQLiteClass sqliteInstance = new SQLiteClass(sqliteConnectionString);
                    sqliteInstance.OrderItem(date, code, exp, type, count);
                    MessageBox.Show("주문완료");
                    BindStockData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("데이터 삽입 중 오류 발생: " + ex.Message);

                }
            }

            code_order_textbox.Clear();
            name_order_textbox.Clear();
            exp_order_textbox.Clear();
            cost_order_textbox.Clear();
            cnt_order_textbox.Clear();
        }
    }
}