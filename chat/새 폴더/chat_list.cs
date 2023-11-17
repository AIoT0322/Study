using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace chat
{
    public partial class chat_list : UserControl
    {
        public chat_list()
        {
            InitializeComponent();
        }

        public void Add_chat(string name, string msg)
        {
            var chat = new friend_chat(name, msg);
            chat.Dock = DockStyle.Top;
            // 패널의 자식 컨트롤을 배열로 가져와서 새로운 메시지를 추가한 다음 다시 패널에 할당
            Control[] controls = panel1.Controls.Cast<Control>().ToArray();
            panel1.Controls.Clear();
            panel1.Controls.Add(chat);
            panel1.Controls.AddRange(controls);
            panel1.VerticalScroll.Value = panel1.VerticalScroll.Maximum;
            // 패널 스크롤을 아래로 이동하여 최신 메시지가 보이도록 함
            panel1.VerticalScroll.Value = panel1.VerticalScroll.Maximum;
        }

        public void Add_mychat(string msg)
        {
            var mychat = new my_chat(msg);
            mychat.Dock = DockStyle.Top;
            // 패널의 자식 컨트롤을 배열로 가져와서 새로운 메시지를 추가한 다음 다시 패널에 할당
            Control[] controls = panel1.Controls.Cast<Control>().ToArray();
            panel1.Controls.Clear();
            panel1.Controls.Add(mychat);
            panel1.Controls.AddRange(controls);
            panel1.VerticalScroll.Value = panel1.VerticalScroll.Maximum;
            // 패널 스크롤을 아래로 이동하여 최신 메시지가 보이도록 함
            panel1.VerticalScroll.Value = panel1.VerticalScroll.Maximum;
        }
    }
}