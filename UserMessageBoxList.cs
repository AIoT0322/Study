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
    public partial class UserMessageBoxList : UserControl
    {
        public UserMessageBoxList()
        {
            InitializeComponent();
        }

        public void AddMessage(int num, string msg)
        {
            var msgBox = new UserMessageBox(num.ToString(), msg);
            msgBox.Dock = DockStyle.Top;
            panel.Controls.Add(msgBox);
        }

        public void ClearMessages()
        {
            panel.Controls.Clear();
        }
    }
}
