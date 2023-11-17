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
    public partial class join_Form : Form
    {
        private Point mousePoint;

        public join_Form()
        { 
            InitializeComponent();            
        }
    
        private void ducheck_button_Click(object sender, EventArgs e) //중복체크 버튼 클릭시
        {
            string sendid = "idcheck/" + id_textBox.Text;
            login_Form.streamWriter.WriteLine(sendid);
            string idcheck =login_Form.streamReader.ReadLine();
            if (idcheck == "OK")
            {
                MessageBox.Show("사용 가능한 ID입니다.");
            }
            else if (idcheck == "NO")
            {
                MessageBox.Show("중복된 ID입니다.");
            }
        }

        private void join_button_Click(object sender, EventArgs e) //회원가입버튼 클릭시
        {           
            try //실행 코드
            {
                string id = id_textBox.Text;
                string pw = pw_textBox.Text;
                string name = name_textBox.Text;
                string phone = phone_textBox.Text;
                string user_data = "join/" + id + "/" + pw + "/" + name + "/" + phone;

                if (pw_textBox.Text != pwcheck_textBox.Text) //비밀번호 일치하지 않으면 창 안 꺼지게
                {
                    throw new Exception("비밀번호가 일치하지 않습니다");
                }
                if (id=="" || pw=="" || name=="" || phone=="")
                {
                    MessageBox.Show("빈 곳을 입력해주세요.");
                }
                else
                {
                    login_Form.streamWriter.WriteLine(user_data);
                    MessageBox.Show("회원가입이 완료되었습니다.");

                    this.Close();
                    //로그인창 다시 나오게
                    login_Form form1 = new login_Form();
                    form1.Show();
                }
            }

            catch(Exception) //예외 발생
            {
                MessageBox.Show("비밀번호를 확인하세요!"); //pw일치하지 않는데 회원가입 버튼 클릭하면 오류 메시지 출력
            }
        }

        private void pwcheck_button_Click(object sender, EventArgs e) //pw확인 버튼 클릭시
        {
            if (pw_textBox.Text == pwcheck_textBox.Text) //두 텍스트박스 비교해서 메시지박스 출력
            {
                if (pw_textBox.Text == "" || pwcheck_textBox.Text == "")
                {
                    MessageBox.Show("PW를 입력하세요.");
                }
                else
                {
                    MessageBox.Show("PW 일치");
                }
            }
            else
            {
                MessageBox.Show("PW 불일치");
            }
        }

        private void join_Form_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }

        private void join_Form_MouseMove(object sender, MouseEventArgs e)
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
