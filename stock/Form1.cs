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

namespace stock
{
    public partial class MainForm : Form
    {
        string mysqlConnectionString = ConfigurationManager.ConnectionStrings["MySQL"].ConnectionString;
        string sqliteConnectionString = ConfigurationManager.ConnectionStrings["SQLite"].ConnectionString;
        private Point mousePoint;

        public MainForm()
        {
            InitializeComponent();
        }

        private void closebutton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void start_button_Click(object sender, EventArgs e)
        {
            if (MySQL_button.Checked)
            {
                //MySQL클래스 실행
                Form2 _form = new Form2(mysqlConnectionString);
                this.Hide();
                _form.Show();
                MySQLClass mySQLInstance = new MySQLClass(mysqlConnectionString);
                mySQLInstance.createTable();
            }
            else if (SQLite_button.Checked)
            {
                //SQLite 클래스 실행
                Form2 _form = new Form2(sqliteConnectionString);
                this.Hide();
                _form.Show();
                SQLiteClass sqliteInstance = new SQLiteClass(sqliteConnectionString);
                sqliteInstance.createTable();
            }
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int x = mousePoint.X - e.X;
                int y = mousePoint.Y - e.Y;
                Location = new Point(this.Left - x, this.Top - y);
            }
        }
    }
}
