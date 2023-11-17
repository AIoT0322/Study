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
using System.Net; 
using System.Net.Sockets; 
using System.IO;
using MySql.Data.MySqlClient;
using Newtonsoft.Json;

namespace serwinform
{
    public partial class Form1 : Form
    {
        private MySqlConnectionStringBuilder _sb = new MySqlConnectionStringBuilder();
        private TcpListener tcpListener1;
        private List<StreamWriter> clientWriters = new List<StreamWriter>();
        private List<ClientInfo> clients = new List<ClientInfo>();
        private object clientLock = new object();
        List<string> id_list = new List<string>();
        List<string> name_list = new List<string>();
        DataSet ds = new DataSet();

        public Form1()
        {
            InitializeComponent();
            CreateMessageFile();

            try
            {
                string connStr = "Server = localhost;Database=userData;Uid=root;Pwd=1234;";

                using (MySqlConnection conn = new MySqlConnection(connStr))
                {
                    string sql = "SELECT id, pw, name FROM user";
                    MySqlDataAdapter adpt = new MySqlDataAdapter(sql, conn);
                    adpt.Fill(ds, "Tab1");
                }
            }
            catch (Exception ex)
            {  
                MessageBox.Show(ex.Message);
            }

            Thread thread1 = new Thread(StartServer); // Thread 객채 생성, Form과는 별도 쓰레드 실행됨.
            thread1.Start(); // thread1 시작.
        }  

        private void StartServer()
        {
            try
            {
                tcpListener1 = new TcpListener(IPAddress.Parse("127.0.0.1"), 9999);
                tcpListener1.Start();

                writeRichTextbox("서버 준비... 클라이언트 기다리는 중...");

                while (true)
                {
                    TcpClient tcpClient1 = tcpListener1.AcceptTcpClient();
                    writeRichTextbox("클라이언트 연결됨...");

                    NetworkStream clientStream = tcpClient1.GetStream();
                    StreamWriter clientWriter = new StreamWriter(clientStream) { AutoFlush = true };

                    lock (clientLock)
                    {
                        clientWriters.Add(clientWriter);
                    }

                    Thread clientThread = new Thread(() => HandleClient(tcpClient1, clientWriter));
                    clientThread.Start();
                }
            }
            catch (Exception ex)
            {
                writeRichTextbox("서버 오류: " + ex.Message);
            }
        }

        private void id_list_data() // id데이터 리스트로 가져오기
        {
            foreach (DataRow r in ds.Tables[0].Rows)
            {
                string id = r["id"].ToString();
                id_list.Add(id);
            }
        }

        private void name_list_data() // name데이터 리스트로 가져오기
        {
            foreach (DataRow r in ds.Tables[0].Rows)
            {
                string name = r["name"].ToString();
                name_list.Add(name);
            }
        }

        private void HandleClient(TcpClient client, StreamWriter clientWriter)
        {
            StreamReader clientReader = new StreamReader(client.GetStream());
            string clientMessage;  

            while (true)
            {
                try
                {
                    clientMessage = clientReader.ReadLine();
                    if (clientMessage == null)
                        break;

                    writeRichTextbox(clientMessage);


                    if (clientMessage.StartsWith("login/")) // 클라이언트에서 로그인할 때
                    {
                        string[] login_data = clientMessage.Split('/');
                        string login_id = login_data[1];
                        string login_pw = login_data[2];
                        bool login_success = false; // 로그인 성공 여부

                        foreach (DataRow row in ds.Tables["Tab1"].Rows)
                        {
                            string idFromTable = row["id"].ToString();
                            string pwFromTable = row["pw"].ToString();
                            string nameFormTable = row["name"].ToString();

                            if (idFromTable == login_id)
                            {
                                if (pwFromTable == login_pw)  // id와 pw가 맞는 경우 처리
                                {                                      
                                    writeRichTextbox("로그인 성공");
                                    clientWriter.WriteLine("OK");
                                    clientWriter.Flush();
                                    login_success = true; 
                                    clientWriter.WriteLine(nameFormTable); // 사용자 이름 전송
                                    clientWriter.Flush();

                                    name_list_data();
                                    string nameListJson = JsonConvert.SerializeObject(name_list);
                                    clientWriter.WriteLine(nameListJson);
                                    clientWriter.Flush();

                                    clientWriter.WriteLine(nameFormTable); // 사용자 이름 전송
                                    clientWriter.Flush();
                                    clients.Add(new ClientInfo   // 클라이언트 정보 저장
                                    {
                                        ClientSocket = client,
                                        Name = nameFormTable
                                    });

                                    foreach (var clientInfo in clients)
                                    {
                                        writeRichTextbox($"Client Name: {clientInfo.Name}");
                                        writeRichTextbox($"Client Port: {((IPEndPoint)clientInfo.ClientSocket.Client.RemoteEndPoint).Port}");
                                        writeRichTextbox("--------------");
                                    }
                                    break;
                                }
                                else  // pw가 틀린 경우 처리
                                {  
                                    clientWriter.WriteLine("NO");
                                    clientWriter.Flush();
                                    login_success = true;
                                }
                            }
                        }

                        if(!login_success)
                        {
                            clientWriter.WriteLine("None");
                            clientWriter.Flush();
                        }
                    }

                    else if(clientMessage.StartsWith("idcheck/"))  //클라이언트에서 id중복체크할 때
                    {
                        string[] input_id = clientMessage.Split('/');
                        string idcheck = input_id[1];

                        id_list_data();

                        if(id_list.Contains(idcheck)==true)
                        {
                            clientWriter.WriteLine("NO");
                            clientWriter.Flush();
                        }
                        else if(id_list.Contains(idcheck) == false)
                        {
                            clientWriter.WriteLine("OK");
                            clientWriter.Flush();
                        }
                    }

                    else if (clientMessage.StartsWith("join/")) //클라이언트에서 회원가입할 때
                    {
                        string[] user_data = clientMessage.Split('/');
                        
                        string id = user_data[1];
                        string pw = user_data[2];
                        string name = user_data[3];
                        string phone = user_data[4];           

                        try
                        {
                            using (var conn = new MySqlConnection("Server = localhost;Database=userData;Uid=root;Pwd=1234;"))
                            {
                                conn.Open();
                                writeRichTextbox("파일 오픈");
                                var sql = $"INSERT INTO user(id, pw, name, phone) VALUES('{id}', '{pw}', '{name}', '{phone}')";
                            
                                using (var cmd = new MySqlCommand(sql, conn))
                                {
                                    cmd.ExecuteNonQuery(); //가져오는 값이 없을 때
                                }
                            }
                        }

                        catch (Exception ex)
                        {
                            MessageBox.Show(ex.Message);
                        }
                    }

                    else
                    {
                        string[] msg = clientMessage.Split('/');
                        string s_name = msg[0];
                        string chat = msg[1];
                        string r_name = msg[2];


                        SaveMessageToFile(clientMessage);

                        // 상대방의 이름을 기반으로 상대 클라이언트 식별
                        var targetClient = clients.FirstOrDefault(clientInfo => clientInfo.Name == r_name);

                        if (targetClient != null)
                        {
                            // 메시지를 상대 클라이언트에게만 전송
                            StreamWriter targetWriter = new StreamWriter(targetClient.ClientSocket.GetStream()) { AutoFlush = true };
                            targetWriter.WriteLine(chat + "/" + s_name);
                        }
                        else
                        {
                            // 상대 클라이언트를 찾지 못한 경우 처리
                            clientWriter.WriteLine("상대방을 찾을 수 없습니다.");
                            clientWriter.Flush();
                        }
                    }
                }
                catch (Exception ex)
                {
                    writeRichTextbox("클라이언트 오류: " + ex.Message);
                    break;
                }
            }

            lock (clientLock)
            {
                clientWriters.Remove(clientWriter);
                clientWriter.Close();
                clientReader.Close();
                client.Close();
                writeRichTextbox("클라이언트 연결 해제됨.");
            }
        }

        private void SaveMessageToFile(string message)
        {
            writeRichTextbox("메시지 저장");
            try
            {
                string filePath = "messages.txt";
                using (StreamWriter writer = new StreamWriter(filePath, true))
                {
                    writer.WriteLine(message);
                }
            }
            catch (Exception ex)
            {
                writeRichTextbox("메시지 저장 오류: " + ex.Message);
            }
        }

        private void CreateMessageFile()
        {
            writeRichTextbox("파일 생성");
            try
            {
                string filePath = "messages.txt";
                if (!File.Exists(filePath))
                {
                    File.Create(filePath).Close();
                }
            }
            catch (Exception ex)
            {
                writeRichTextbox("파일 생성 오류: " + ex.Message);
            }
        }


        /*private void BroadcastToClients(string message, StreamWriter senderWriter)
        {
            lock (clientLock)
            {
                foreach (var writer in clientWriters)
                {
                    if (writer != senderWriter)
                    {
                        writer.WriteLine(message);
                        writer.Flush();
                    }
                }
            }
        }*/

        private void writeRichTextbox(string str)
        {
            if (richTextBox1.InvokeRequired)
            { // 현재 스레드가 UI 스레드인지 확인하고, UI 스레드가 아니면 Invoke를 사용하여 writeRichTextbox 메서드를 다시 호출
                richTextBox1.Invoke((MethodInvoker)delegate { writeRichTextbox(str); });
            }
            else
            {
                richTextBox1.AppendText(str + "\r\n");
                richTextBox1.ScrollToCaret();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            tcpListener1.Stop();
        }
    }
}