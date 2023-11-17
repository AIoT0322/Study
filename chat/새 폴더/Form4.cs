using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;


namespace chat  
{
    public partial class list_Form : Form
    {
        private Point mousePoint;
        private List<string> friendNames = new List<string>();

        public list_Form()
        {
            InitializeComponent();
            string name = login_Form.streamReader.ReadLine();
            user_label.Text = name;

            string receivedJson = login_Form.streamReader.ReadLine(); // 바로 문자열로 읽어오기

            // JSON 데이터 역직렬화하여 List<string>으로 변환
            friendNames = JsonConvert.DeserializeObject<List<string>>(receivedJson);
            friendNames.Remove(name);

            foreach (string f_name in friendNames)
            {
                friend_list1.Add_name(f_name);
            }
        }

        private void list_Form_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int x = mousePoint.X - e.X;
                int y = mousePoint.Y - e.Y;
                Location = new Point(this.Left - x, this.Top - y);
            }
        }

        private void list_Form_MouseDown(object sender, MouseEventArgs e)
        {
            mousePoint = new Point(e.X, e.Y); //지금 윈도우의 좌표저장
        }
    }
}
