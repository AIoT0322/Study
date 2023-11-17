using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace board
{
    public partial class Form1 : Form
    {
        private MySqlConnectionStringBuilder _sb = new MySqlConnectionStringBuilder();

        public Form1()
        {
            InitializeComponent();

            _sb.Server = "10.10.20.32";
            _sb.Port = 3306;
            _sb.Database = "cs";
            _sb.UserID = "cs";
            _sb.Password = "q1w2e3r4";

        }

        public void InsertMessage(string msg)
        {
            try
            {
                using (var conn = new MySqlConnection(_sb.ConnectionString))
                {
                    var sql = $"INSERT INTO Messages (MSG) VALUES('{msg}')";
                    conn.Open();
                    using (var cmd = new MySqlCommand(sql, conn))
                    {
                        cmd.ExecuteNonQuery(); //가져오는 값이 없을 때
                    }

                    conn.Close(); //using 문으로 하면 자동을 닫혀서 써도 되고 안써도 됨
                }
            }

            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public DataTable SelectMessages()
        {
            try
            {
                using (var conn = new MySqlConnection(_sb.ConnectionString))
                {
                    var sql = @"SELECT * FROM Messages ORDER BY IDX DESC LIMIT 10";
                    
                    conn.Open();

                    using (var cmd = new MySqlCommand(sql, conn))
                    {
                        var rdr = cmd.ExecuteReader(); //데이터 읽어오기
                        var dt = new DataTable();
                        dt.Load(rdr);
                        return dt;
                    }

                    //conn.Close(); //using 문으로 하면 자동을 닫혀서 써도 되고 안써도 됨
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return null;
            }
        }

        public void Add(int num, string msg)
        {
            userMessageBoxList.AddMessage(num, msg);
        }

        public void RefreshList()
        {
            userMessageBoxList.ClearMessages();

            var dt = SelectMessages();
            
            foreach(DataRow row in dt.Rows)
            {
                Add(int.Parse(row["IDX"].ToString()), row["MSG"].ToString());
            }
        }

        public void Submit(string msg)
        {
            InsertMessage(msg);
            RefreshList();
        }

        private void refreshbutton_Click(object sender, EventArgs e)
        {
            RefreshList();
        }

        private void submitbutton_Click(object sender, EventArgs e)
        {
            var msg = textBox.Text;
            Submit(msg);
            textBox.Text = string.Empty;
        }
    }
}
