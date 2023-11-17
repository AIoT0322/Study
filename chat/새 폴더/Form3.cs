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
using System.Threading;
using System.Net; // 추가
using System.Net.Sockets; // 추가
using System.IO; // 추가

namespace chat     
{                 
    public partial class chat_Form : Form
    {
        private Thread receiveThread;
        private bool receivingMessages = true; // 메시지 수신 여부 체크
        private bool closingForm = false;
        private Point mousePoint;
        private Friend friend;
        string my_name;

        public chat_Form(string friendName)
        {
            InitializeComponent();
            friend = new Friend(friendName);
            my_name =login_Form.streamReader.ReadLine();
        }  

        private void send_button_Click(object sender, EventArgs e) // 채팅 보내기 버튼 클릭 시
        {
            string friendName = friend.Name;
            string chat = send_textbox.Text;
            login_Form.streamWriter.WriteLine(my_name + "/" + chat + "/" + friendName);
            chat_list1.Add_mychat(chat);
            send_textbox.Text = string.Empty;  //채팅 한번 보내면 텍스트창 비워줌
        }

        private void EnterKey(object sender, KeyEventArgs e) // 엔터키 누르면 send버튼 클릭되도록
        {
            if (e.KeyCode == Keys.Enter)
            {
                e.SuppressKeyPress = true;
                send_button_Click(sender, e);
            }
        }     

        private void ReceiveMessages()
        {
            try
            {
                while (!closingForm) // 폼이 닫힐 때까지 반복
                {
                    string msg = login_Form.streamReader.ReadLine();
                    string[] Msg = msg.Split('/');
                    string chat = Msg[0];
                    string name = Msg[1];
                    string friendName = friend.Name;
                    
                    if (!string.IsNullOrEmpty(msg))
                    {
                       if(name == friendName) // 현재 채팅하는 친구의 메시지만 출력되게 함
                        {
                            this.Invoke((MethodInvoker)delegate
                            {
                                chat_list1.Add_chat(friendName, chat);
                            });
                        }
                        
                    }
                }
            }
            catch (IOException ex)
            {
                // 소켓이 닫혔거나 통신 오류가 발생한 경우
                MessageBox.Show("서버와의 연결이 끊어졌습니다.");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void chat_Form_Load(object sender, EventArgs e)
        {
            receiveThread = new Thread(ReceiveMessages);
            receiveThread.Start();
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            base.OnFormClosing(e);
            closingForm = true; // 폼을 닫는 플래그 설정
            receivingMessages = false; // 메시지 수신 중단
            if (receiveThread != null && receiveThread.IsAlive)
            {
                receiveThread.Join(); // 스레드 종료 대기
            }
        }

        private void button1_Click(object sender, EventArgs e) //채팅방 닫기 버튼 누르면
        {
            Task.Run(() => // 백그라운드 스레드에서 작업 실행
            {
                // 필요한 작업 수행
                // UI 요소 업데이트를 위해 Invoke 사용
                this.Invoke((MethodInvoker)delegate
                {
                    this.Hide(); // UI 업데이트는 UI 스레드에서 실행
                });
            });
        }

        private void chat_Form_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }

        private void chat_Form_MouseMove(object sender, MouseEventArgs e)
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
