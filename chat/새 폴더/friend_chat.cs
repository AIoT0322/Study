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
    public partial class friend_chat : UserControl
    {
        public string Message
        {
            get
            {
                return label1.Text;
            }
            set
            {
                label1.Text = value;
            }
        }

        public string sender_name
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

        public friend_chat()
        {
            InitializeComponent();
            
        }

        public friend_chat(string name, string msg) : this()
        {
            sender_name = name;
            Message = msg;
        }
    }
}
