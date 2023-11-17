
namespace chat
{
    partial class login_Form
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.join_button = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.id_textBox = new System.Windows.Forms.TextBox();
            this.pw_textBox = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.login_button = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // join_button
            // 
            this.join_button.BackColor = System.Drawing.SystemColors.Window;
            this.join_button.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.join_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.join_button.Font = new System.Drawing.Font("맑은 고딕", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.join_button.ForeColor = System.Drawing.Color.Gray;
            this.join_button.Location = new System.Drawing.Point(136, 425);
            this.join_button.Name = "join_button";
            this.join_button.Size = new System.Drawing.Size(61, 22);
            this.join_button.TabIndex = 5;
            this.join_button.Text = "회원가입";
            this.join_button.UseVisualStyleBackColor = false;
            this.join_button.Click += new System.EventHandler(this.join_button_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label1.Location = new System.Drawing.Point(25, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 17);
            this.label1.TabIndex = 9;
            this.label1.Text = "User ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label2.Location = new System.Drawing.Point(24, 10);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 17);
            this.label2.TabIndex = 10;
            this.label2.Text = "PassWord";
            // 
            // id_textBox
            // 
            this.id_textBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.id_textBox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.id_textBox.Location = new System.Drawing.Point(82, 9);
            this.id_textBox.Name = "id_textBox";
            this.id_textBox.Size = new System.Drawing.Size(150, 20);
            this.id_textBox.TabIndex = 11;
            // 
            // pw_textBox
            // 
            this.pw_textBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.pw_textBox.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.pw_textBox.Location = new System.Drawing.Point(94, 9);
            this.pw_textBox.Name = "pw_textBox";
            this.pw_textBox.PasswordChar = '*';
            this.pw_textBox.Size = new System.Drawing.Size(140, 20);
            this.pw_textBox.TabIndex = 12;
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.id_textBox);
            this.panel1.Controls.Add(this.pictureBox2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(46, 260);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(240, 40);
            this.panel1.TabIndex = 13;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = global::chat.Properties.Resources.사용자2;
            this.pictureBox2.Location = new System.Drawing.Point(4, 8);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(18, 23);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 7;
            this.pictureBox2.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.pw_textBox);
            this.panel2.Controls.Add(this.pictureBox3);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Location = new System.Drawing.Point(46, 307);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(240, 40);
            this.panel2.TabIndex = 14;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = global::chat.Properties.Resources.자물쇠;
            this.pictureBox3.Location = new System.Drawing.Point(3, 6);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(20, 23);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 8;
            this.pictureBox3.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::chat.Properties.Resources.톡이미지1;
            this.pictureBox1.Location = new System.Drawing.Point(108, 105);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(113, 100);
            this.pictureBox1.TabIndex = 6;
            this.pictureBox1.TabStop = false;
            // 
            // login_button
            // 
            this.login_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.login_button.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.login_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.login_button.Image = global::chat.Properties.Resources.로그인;
            this.login_button.Location = new System.Drawing.Point(45, 378);
            this.login_button.Name = "login_button";
            this.login_button.Size = new System.Drawing.Size(242, 40);
            this.login_button.TabIndex = 2;
            this.login_button.UseVisualStyleBackColor = true;
            this.login_button.Click += new System.EventHandler(this.login_button_Click);
            // 
            // login_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(334, 511);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.join_button);
            this.Controls.Add(this.login_button);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "login_Form";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Login";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.login_Form_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.login_Form_MouseMove);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button login_button;
        private System.Windows.Forms.Button join_button;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox id_textBox;
        private System.Windows.Forms.TextBox pw_textBox;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
    }
}

