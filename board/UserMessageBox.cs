using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace board
{
    public partial class UserMessageBox : UserControl
    {
        public string Number 
        { get
          {
                return groupBox.Text;
            }
                
            set
            {
                groupBox.Text = value;
            }
        }
        public string Message 
        {
            get
            {
                return msgLabel.Text;
            }
            set
            {
                msgLabel.Text = value;
            }
        }
        public UserMessageBox()
        {
            InitializeComponent();
        }

        public UserMessageBox(string num, string msg): this()
        {
            Number = num;
            Message = msg;
        }
    }
}
