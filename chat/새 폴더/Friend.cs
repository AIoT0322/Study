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
    public partial class Friend : UserControl
    {
        public string Name
        {
            get
            {
                return name_label.Text;
            }
            set
            {
                name_label.Text = value;
            }
        }
     
        public Friend()
        {
            InitializeComponent();
        }

        public Friend(string name) : this()
        {
            Name = name;
        }

        private void name_label_Click(object sender, EventArgs e)
        {
            string recv_name = name_label.Text;
            chat_Form chat = new chat_Form(recv_name);
            chat.Show();
        }

        private void f1_pictureBox_Click(object sender, EventArgs e)
        {
            string recv_name = name_label.Text;
            chat_Form chat = new chat_Form(recv_name);
            chat.Show();
        }
    }
}
