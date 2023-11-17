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
    public partial class Friend_list : UserControl
    {
        public Friend_list()
        {
            InitializeComponent();
        }

        public void Add_name(string name1)
        {
            var friend = new Friend(name1);
            friend.Dock = DockStyle.Top;
            panel1.Controls.Add(friend);
        }
    }
}
