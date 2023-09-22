using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using MySql.Data.MySqlClient;
using System.Configuration;

namespace stock
{
    class MySQLClass : Interface //인터페이스 상속
    {
        MySqlConnection mysqlConnection;
        string mysqlConnectionString;

        public MySQLClass(string connectionString)
        {
            // MySQL 데이터베이스 연결 문자열 가져오기
            mysqlConnectionString = ConfigurationManager.ConnectionStrings["MySQL"].ConnectionString;
            mysqlConnection = new MySqlConnection(mysqlConnectionString);
            mysqlConnection.Open();

        }

        public void createTable()
        {
            // MySQL 데이터베이스에 연결
            using (MySqlConnection mysqlConnection = new MySqlConnection(mysqlConnectionString))
            {
                mysqlConnection.Open();
                try
                {
                    string createProductsTableQuery = @"
                    CREATE TABLE IF NOT EXISTS Products (
                        code VARCHAR(6) PRIMARY KEY,
                        name VARCHAR(20),
                        cost INT,
                        price INT,
                        category VARCHAR(10),
                        sales_rate VARCHAR(10)
                    )";

                    // 쿼리 실행
                    using (MySqlCommand cmd = new MySqlCommand(createProductsTableQuery, mysqlConnection))
                    {
                        cmd.ExecuteNonQuery();
                        System.Diagnostics.Debug.WriteLine("상품테이블이 성공적으로 생성되었습니다.");
                    }

                    string createStockTableQuery = @"
                    CREATE TABLE IF NOT EXISTS Stock (
                        idx INT AUTO_INCREMENT PRIMARY KEY,
                        datetime DATE, 
                        product_code VARCHAR(6),
                        exp_day DATE,
                        type VARCHAR(10),
                        count INT
                    )"; 

                    // 쿼리 실행
                    using (MySqlCommand cmd = new MySqlCommand(createStockTableQuery, mysqlConnection))
                    {
                        cmd.ExecuteNonQuery();
                        System.Diagnostics.Debug.WriteLine("재고테이블이 성공적으로 생성되었습니다.");
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("MySQL 오류: " + ex.Message);
                }
            }
        }

        List<string> Productlist()
        {
            List<string> productCodes = new List<string>();

            using (MySqlConnection connection = new MySqlConnection(mysqlConnectionString))
            {
                connection.Open();
                try
                {
                    // 상품 코드를 가져오는 SQL 쿼리
                    string query = "SELECT code FROM Products";

                    // 쿼리 실행
                    MySqlCommand command = new MySqlCommand(query, connection);
                    using (MySqlDataReader reader = command.ExecuteReader())
                    {
                        // 결과에서 상품 코드 읽기
                        while (reader.Read())
                        {
                            string productCode = reader["code"].ToString();
                            productCodes.Add(productCode);
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("MySQL 오류: " + ex.Message);
                }
            }

            return productCodes;
        }

        private int GetStockCount(string productCode)
        {
            int currentStock = 0;

            using (MySqlConnection connection = new MySqlConnection(mysqlConnectionString))
            {
                connection.Open();
                try
                {
                    // 특정 상품 코드에 대한 현재 재고 개수를 가져오는 SQL 쿼리
                    string query = "SELECT SUM(count) AS total FROM Stock WHERE product_code = @productCode";

                    // 쿼리 실행
                    MySqlCommand command = new MySqlCommand(query, connection);
                    command.Parameters.AddWithValue("@productCode", productCode);

                    // 결과에서 현재 재고 개수 읽기
                    object result = command.ExecuteScalar();
                    if (result != null && result != DBNull.Value)
                    {
                        currentStock = Convert.ToInt32(result);
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("MySQL 오류: " + ex.Message);
                }
            }

            return currentStock;
        }

        public void RandomSale(DateTime currentDate)
        {
            List<string> productCodes = Productlist();

            Random random = new Random();

            // 각 상품의 재고를 조회하고 랜덤하게 판매
            foreach (string selectedProductCode in productCodes)
            {
                int currentStock = GetStockCount(selectedProductCode);

                if (currentStock > 0)
                {
                    int randomSaleCount = random.Next(0, currentStock + 1);

                    // 판매 데이터 삽입
                    SaleItem(currentDate, selectedProductCode, "판매", -randomSaleCount);

                    // 판매 후에 폐기 실행
                    DisposeItem(currentDate);
                }
            }
        }


        void Interface.RegisterItem(string code, string name, int cost, int price, string category)
        {
            string insertDataQuery = @"
                INSERT INTO Products (code, name, cost, price, category)
                VALUES (@code, @name, @cost, @price, @category)";

            // 데이터 삽입을 위한 매개 변수 설정
            using (MySqlCommand insertCmd = new MySqlCommand(insertDataQuery, mysqlConnection))
            {
                insertCmd.Parameters.AddWithValue("@code", code);
                insertCmd.Parameters.AddWithValue("@name", name);
                insertCmd.Parameters.AddWithValue("@cost", cost);
                insertCmd.Parameters.AddWithValue("@price", price);
                insertCmd.Parameters.AddWithValue("@category", category);
                //insertCmd.Parameters.AddWithValue("@sales_rate", sales);

                // 데이터 삽입 쿼리 실행
                insertCmd.ExecuteNonQuery();
                System.Diagnostics.Debug.WriteLine("데이터가 상품테이블에 삽입되었습니다.");
            }
        }

        public void OrderItem(DateTime date, string code, DateTime exp, string type, int count)
        {
            string insertDataQuery = @"
                INSERT INTO Stock (datetime, product_code, exp_day, type, count)
                VALUES (@datetime, @product_code, @exp_day, @type, @count)";

            // 데이터 삽입을 위한 매개 변수 설정
            using (MySqlCommand insertCmd = new MySqlCommand(insertDataQuery, mysqlConnection))
            {
                insertCmd.Parameters.AddWithValue("@datetime", date);
                insertCmd.Parameters.AddWithValue("@product_code", code);
                insertCmd.Parameters.AddWithValue("@exp_day", exp);
                insertCmd.Parameters.AddWithValue("@type", type);
                insertCmd.Parameters.AddWithValue("@count", count);

                // 데이터 삽입 쿼리 실행
                insertCmd.ExecuteNonQuery();
                System.Diagnostics.Debug.WriteLine("데이터가 재고테이블에 삽입되었습니다.");
            }
        }

        public void SaleItem(DateTime date, string code, string type, int count)
        {
            string insertDataQuery = @"
                INSERT INTO Stock (datetime, product_code, type, count)
                VALUES (@datetime, @product_code, @type, @count)";

            // 데이터 삽입을 위한 매개 변수 설정
            using (MySqlCommand insertCmd = new MySqlCommand(insertDataQuery, mysqlConnection))
            {
                insertCmd.Parameters.AddWithValue("@datetime", date);
                insertCmd.Parameters.AddWithValue("@product_code", code);
                insertCmd.Parameters.AddWithValue("@type", type);
                insertCmd.Parameters.AddWithValue("@count", count);

                // 데이터 삽입 쿼리 실행
                insertCmd.ExecuteNonQuery();
                System.Diagnostics.Debug.WriteLine("데이터가 재고테이블에 삽입되었습니다.");
            }
        }

        public void DisposeItem(DateTime form2Date)
        {
            try
            {
                using (MySqlConnection connection = new MySqlConnection(mysqlConnectionString))
                {
                    connection.Open();

                    // 폐기할 제품 선택
                    string selectQuery = "SELECT product_code, SUM(count) AS stock FROM Stock WHERE exp_day < @form2Date GROUP BY product_code";

                    using (MySqlCommand selectCommand = new MySqlCommand(selectQuery, connection))
                    {
                        selectCommand.Parameters.AddWithValue("@form2Date", form2Date);

                        using (MySqlDataReader reader = selectCommand.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                string productCode = reader.GetString("product_code");
                                int currentStock = reader.GetInt32("stock");

                                // 폐기 데이터 삽입
                                string insertQuery = "INSERT INTO Stock (product_code, count, type, date) " +
                                                     "VALUES (@product_code, @count, @type, @form2Date)";

                                using (MySqlCommand insertCommand = new MySqlCommand(insertQuery, connection))
                                {
                                    insertCommand.Parameters.AddWithValue("@product_code", productCode);
                                    insertCommand.Parameters.AddWithValue("@count", -currentStock);
                                    insertCommand.Parameters.AddWithValue("@type", "폐기");
                                    insertCommand.Parameters.AddWithValue("@form2Date", form2Date);

                                    int rowsAffected = insertCommand.ExecuteNonQuery();
                                    if (rowsAffected > 0)
                                    {
                                        // 폐기 데이터를 삽입한 경우
                                        System.Diagnostics.Debug.WriteLine($"제품 코드 {productCode}의 폐기 데이터가 삽입되었습니다.");
                                    }
                                }
                            }
                            reader.Close();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("오류 발생: " + ex.Message);
            }
        }
    }
}