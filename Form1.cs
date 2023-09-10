using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Numberfind
{
    public partial class Form1 : Form
    {
        private int findNumber = 0;
        private int chance = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void startclicked(object sender, EventArgs e)
        {
            var rand = new Random();
            findNumber = rand.Next(1, 21);
            chance = 10;
            display.Text = "맞출 숫자를 입력하세요.";
        }

        private void inputclicked(object sender, EventArgs e)
        {
            int inputNumber = Int32.Parse(textBox1.Text);
            if(inputNumber==findNumber)
            {
                display.Text = "승리했습니다!";
            }
            else
            {
                chance--;
                display.Text = "기회는 " + chance + "번 남았습니다.";
            }

            if(chance<=0)
            {
                display.Text = "실패했습니다!";
            }
        }
    }
}
