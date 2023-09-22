using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SQLite;
using System.Configuration;


namespace stock
{
    class SQLiteClass : Interface //인터페이스 상속
    {
        SQLiteConnection sqliteConnection;
        string sqliteConnectionString;

        public SQLiteClass(string connectionString)
        {
            // SQLite 데이터베이스 연결 문자열 가져오기
            sqliteConnectionString = ConfigurationManager.ConnectionStrings["SQLite"].ConnectionString;
            sqliteConnection = new SQLiteConnection(sqliteConnectionString);
        }

        public void createTable()
        {
            // SQLite 데이터베이스에 연결
            using (SQLiteConnection sqliteConnection = new SQLiteConnection(sqliteConnectionString))
            {
                try
                {
                    sqliteConnection.Open();
                    System.Diagnostics.Debug.WriteLine("SQLite 데이터베이스에 연결되었습니다.");

                    string createProductTableSQL = "CREATE TABLE IF NOT EXISTS Products (" +
                    "code TEXT PRIMARY KEY," +
                    "name TEXT NOT NULL," +
                    "cost INT," +
                    "price INT," +
                    "category TEXT," +
                    "sales_rate TEXT )";

                    SQLiteCommand createProductTableCommand = new SQLiteCommand(createProductTableSQL, sqliteConnection);
                    createProductTableCommand.ExecuteNonQuery();

                    System.Diagnostics.Debug.WriteLine("상품테이블이 성공적으로 생성되었습니다.");

                    string createStockTableSQL = "CREATE TABLE IF NOT EXISTS Stock (" +
                   "idx INTEGER PRIMARY KEY AUTOINCREMENT," +
                   "date TEXT NOT NULL," +
                   "product_code TEXT," +
                   "exp_day TEXT," +
                   "type TEXT," +
                   "count INT )";

                    SQLiteCommand createStockTableCommand = new SQLiteCommand(createStockTableSQL, sqliteConnection);
                    createStockTableCommand.ExecuteNonQuery();

                    System.Diagnostics.Debug.WriteLine("재고테이블이 성공적으로 생성되었습니다.");
                }
            
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
                }
                finally
                {
                    sqliteConnection.Close();
                }
            }
        }

        List<string> Productlist()
        {
            List<string> productCodes = new List<string>();

            using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
            {
                connection.Open();
                try
                {
                    // 상품 코드를 가져오는 SQL 쿼리
                    string query = "SELECT code FROM Products";

                    // 쿼리 실행
                    using (SQLiteCommand command = new SQLiteCommand(query, connection))
                    {
                        using (SQLiteDataReader reader = command.ExecuteReader())
                        {
                            // 결과에서 상품 코드 읽기
                            while (reader.Read())
                            {
                                string productCode = reader["code"].ToString();
                                productCodes.Add(productCode);
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
                }
            }

            return productCodes;
        }

        private int GetStockCount(string productCode)
        {
            int currentStock = 0;

            using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
            {
                connection.Open();
                try
                {
                    // 특정 상품 코드에 대한 현재 재고 개수를 가져오는 SQL 쿼리
                    string query = "SELECT SUM(count) AS total FROM Stock WHERE product_code = @productCode";

                    // 쿼리 실행
                    using (SQLiteCommand command = new SQLiteCommand(query, connection))
                    {
                        command.Parameters.AddWithValue("@productCode", productCode);

                        // 결과에서 현재 재고 개수 읽기
                        object result = command.ExecuteScalar();
                        if (result != null && result != DBNull.Value)
                        {
                            currentStock = Convert.ToInt32(result);
                        }
                    }
                }
                catch (Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
                }
            }

            return currentStock;
        }

        public void RandomSale(string currentDate)
        {
            List<string> productCodes = Productlist();

            Random random = new Random();

            using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
            {
                connection.Open();
                using (SQLiteTransaction transaction = connection.BeginTransaction())
                {
                    try
                    {
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

                        // 트랜잭션 커밋
                        transaction.Commit();
                    }
                    catch (Exception ex)
                    {
                        transaction.Rollback();
                        System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
                    }
                }
            }
        }

        public void DisposeItem(string form2Date)
        {
            try
            {
                using (SQLiteConnection connection = new SQLiteConnection(sqliteConnectionString))
                {
                    connection.Open();

                    // 폐기할 제품 선택
                    string selectQuery = "SELECT product_code, SUM(count) AS stock FROM Stock WHERE exp_day < @form2Date GROUP BY product_code";

                    using (SQLiteCommand selectCommand = new SQLiteCommand(selectQuery, connection))
                    {
                        selectCommand.Parameters.AddWithValue("@form2Date", form2Date);

                        using (SQLiteDataReader reader = selectCommand.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                string productCode = reader["product_code"].ToString();
                                int currentStock = Convert.ToInt32(reader["stock"]);

                                // 폐기 데이터 삽입
                                string insertQuery = "INSERT INTO Stock (product_code, count, type, date) " +
                                                     "VALUES (@product_code, @count, @type, @form2Date)";

                                using (SQLiteCommand insertCommand = new SQLiteCommand(insertQuery, connection))
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


        void Interface.RegisterItem(string code, string name, int cost, int price, string category)
        {
            try
            {
                sqliteConnection.Open();
                System.Diagnostics.Debug.WriteLine("SQLite에 연결되었습니다.");

                // 데이터를 삽입할 SQL 명령문
                string insertDataSQL = "INSERT INTO Products (code, name, cost, price, category) " +
                    "VALUES (@code, @name, @cost, @price, @category)";

                SQLiteCommand insertCommand = new SQLiteCommand(insertDataSQL, sqliteConnection);
                insertCommand.Parameters.AddWithValue("@code", code);
                insertCommand.Parameters.AddWithValue("@name", name);
                insertCommand.Parameters.AddWithValue("@cost", cost);
                insertCommand.Parameters.AddWithValue("@price", price);
                insertCommand.Parameters.AddWithValue("@category", category);

                int rowsAffected = insertCommand.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    System.Diagnostics.Debug.WriteLine("데이터가 성공적으로 삽입되었습니다.");
                }
                else
                {
                    System.Diagnostics.Debug.WriteLine("데이터 삽입에 실패했습니다.");
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
            }
            finally
            {
                sqliteConnection.Close();
            }
        }

        public void OrderItem(string date, string code, string exp, string type, int count)
        {
            try
            {
                sqliteConnection.Open();
                System.Diagnostics.Debug.WriteLine("SQLite에 연결되었습니다.");

                // 데이터를 삽입할 SQL 명령문
                string insertDataSQL = "INSERT INTO Stock (date, product_code, exp_day, type, count) " +
                    "VALUES (@date, @product_code, @exp_day, @type, @count)";

                SQLiteCommand insertCommand = new SQLiteCommand(insertDataSQL, sqliteConnection);
                insertCommand.Parameters.AddWithValue("@date", date);
                insertCommand.Parameters.AddWithValue("@product_code", code);
                insertCommand.Parameters.AddWithValue("@exp_day", exp);
                insertCommand.Parameters.AddWithValue("@type", type);
                insertCommand.Parameters.AddWithValue("@count", count);

                int rowsAffected = insertCommand.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    System.Diagnostics.Debug.WriteLine("데이터가 성공적으로 삽입되었습니다.");
                }
                else
                {
                    System.Diagnostics.Debug.WriteLine("데이터 삽입에 실패했습니다.");
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
            }
            finally
            {
                sqliteConnection.Close();
            }
        }

        public void SaleItem(string date, string code, string type, int count)
        {
            try
            {
                sqliteConnection.Open();
                System.Diagnostics.Debug.WriteLine("SQLite에 연결되었습니다.");

                // 데이터를 삽입할 SQL 명령문
                string insertDataSQL = "INSERT INTO Stock (date, product_code, type, count) " +
                    "VALUES (@date, @product_code, @type, @count)";

                SQLiteCommand insertCommand = new SQLiteCommand(insertDataSQL, sqliteConnection);
                insertCommand.Parameters.AddWithValue("@date", date);
                insertCommand.Parameters.AddWithValue("@product_code", code);
                insertCommand.Parameters.AddWithValue("@type", type);
                insertCommand.Parameters.AddWithValue("@count", count);

                int rowsAffected = insertCommand.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    System.Diagnostics.Debug.WriteLine("데이터가 성공적으로 삽입되었습니다.");
                }
                else
                {
                    System.Diagnostics.Debug.WriteLine("데이터 삽입에 실패했습니다.");
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine("SQLite 오류: " + ex.Message);
            }
            finally
            {
                sqliteConnection.Close();
            }
        }
    }
}
