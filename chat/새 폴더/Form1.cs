using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Net.Sockets;
using System.Net;
using System.IO;
using MySql.Data.MySqlClient;

namespace chat
{
    public partial class login_Form : Form
    {
        private TcpClient tcpClient;
        public static StreamReader streamReader;
        public static StreamWriter streamWriter;

        private Point mousePoint;
      
        public login_Form()
        {
            InitializeComponent();
            ConnectToServer();
        }
       
        private void ConnectToServer()
        {
            try
            {
                tcpClient = new TcpClient();
                tcpClient.Connect("127.0.0.1", 9999);
                streamReader = new StreamReader(tcpClient.GetStream());
                streamWriter = new StreamWriter(tcpClient.GetStream()) { AutoFlush = true };

               Console.WriteLine("서버 연결됨...");
            }
            catch (Exception ex)
            {
                MessageBox.Show("서버에 연결할 수 없습니다: " + ex.Message);
            }
        }

       

        private void login_Form_FormClosing(object sender, FormClosingEventArgs e)
        {
            DisconnectFromServer();
        }

        private void DisconnectFromServer()
        {
            if (streamWriter != null)
                streamWriter.Close();
            if (streamReader != null)
                streamReader.Close();
            if (tcpClient != null)
                tcpClient.Close();
        }

        private void login_button_Click(object sender, EventArgs e)
        {
            string strID = id_textBox.Text;
            string strPW = pw_textBox.Text;

            if(strID == "" || strPW == "")
            {
                MessageBox.Show("ID와 PW를 입력해주세요.");
            }
            else
            {
                string sendData1 = "login/" + strID + "/" + strPW;  
                streamWriter.WriteLine(sendData1);   // 스트림라이터를 통해 데이타를 전송

                string receivelogin = streamReader.ReadLine();

                if (receivelogin == "OK")  //서버에서 ok 받으면 친구목록창 뜨기
                {
                    this.Hide();
                    list_Form list = new list_Form();
                    list.Show();
                }
                else if(receivelogin == "NO")
                {
                    MessageBox.Show("PW가 일치하지 않습니다.");
                }
                else if (receivelogin == "None")
                {
                    MessageBox.Show("존재하지 않는 ID입니다.");
                }
            }
        }

        private void join_button_Click(object sender, EventArgs e) //join버튼 누르면 회원가입창 뜨기
        {
            this.Hide();
            join_Form form = new join_Form();
            form.Show();
        }

        private void login_Form_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }

        private void login_Form_MouseMove(object sender, MouseEventArgs e)
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
