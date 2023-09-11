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
    public partial class Form1 : Form
    {
        private ValueModelColloction _coll = new ValueModelColloction();


        public Form1() //생성자 객체가 생성될 때 딱 1번만 실행
        {
            InitializeComponent();

            _coll.Add(new ValueModel("A", 12));
            _coll.Add(new ValueModel("B", 23));
            _coll.Add(new ValueModel("C", 42));
            _coll.Add(new ValueModel("D", 66));
            _coll.Add(new ValueModel("E", 164));

            UpdatelistBox();
            userControl11.UpdateChart(_coll);
        }

        public void UpdatelistBox()
        {
            if (baselistBox.Items.Count > 0)
                baselistBox.Items.Clear();

            foreach(var item in _coll)
            {
                baselistBox.Items.Add(item);
            }

            userControl11.UpdateChart(_coll);
        }
        /// <summary>
        /// 리스트박스 출력시 값 출력
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void baselistBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            var index = baselistBox.SelectedIndex;
            if (index < 0) return;
            
            var value = baselistBox.Items[index] as ValueModel; //바꿀 수 있는 경우에만 바꿈 바꿀 수 없으면 리턴값 널나옴
            if (value == null) return;

            textBox1.Text = value.Value.ToString();
            textBox1.Focus();
        }

        /// <summary>
        /// 값 변경 적용
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            EditAp();
        }

        private void EditAp()
        {
            try
            {
                var text = textBox1.Text;

                var index = baselistBox.SelectedIndex;
                if (index < 0) return;

                var value = baselistBox.Items[index] as ValueModel;
                if (value == null) return;

                value.Value = int.Parse(text);

                textBox1.Text = string.Empty;
                UpdatelistBox();
            }
            catch
            {
                MessageBox.Show("입력값이 잘못되었습니다");
            }
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                EditAp();
            }
        }
    }
    }