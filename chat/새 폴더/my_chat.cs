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
    public partial class my_chat : UserControl
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
        public my_chat()
        {
            InitializeComponent();
        }

        public my_chat(string msg) : this()
        {
            Message = msg;
        }
    }
}
