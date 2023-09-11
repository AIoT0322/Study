using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace form2
{
    public partial class UserControl1 : UserControl
    {
        private List<Panel> _panels = new List<Panel>();

        public UserControl1()
        {
            InitializeComponent();

            _panels.Add(panel1);
            _panels.Add(panel2);
            _panels.Add(panel3);
            _panels.Add(panel4);
            _panels.Add(panel5);
        }

        public void UpdateChart(ValueModelColloction coll)
        {
            for(int i=0; i<5; i++)
            {
                var value = coll[i];
                var panel = _panels[i];

                panel.Width = value.Value;

                var label = panel.Controls[0];
                label.Text = value.ToString();
            }
        }
    }
}
