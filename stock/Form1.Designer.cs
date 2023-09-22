
namespace stock
{
    partial class MainForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.closebutton = new System.Windows.Forms.Button();
            this.MySQL_button = new MetroFramework.Controls.MetroRadioButton();
            this.SQLite_button = new MetroFramework.Controls.MetroRadioButton();
            this.start_button = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(167, 162);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(364, 65);
            this.label1.TabIndex = 0;
            this.label1.Text = "재고관리시스템";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.HotTrack;
            this.panel1.Controls.Add(this.closebutton);
            this.panel1.Location = new System.Drawing.Point(-1, -1);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(702, 159);
            this.panel1.TabIndex = 1;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            // 
            // closebutton
            // 
            this.closebutton.FlatAppearance.BorderSize = 0;
            this.closebutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closebutton.Image = global::stock.Properties.Resources.x;
            this.closebutton.Location = new System.Drawing.Point(663, 2);
            this.closebutton.Name = "closebutton";
            this.closebutton.Size = new System.Drawing.Size(23, 18);
            this.closebutton.TabIndex = 6;
            this.closebutton.UseVisualStyleBackColor = true;
            this.closebutton.Click += new System.EventHandler(this.closebutton_Click);
            // 
            // MySQL_button
            // 
            this.MySQL_button.AutoSize = true;
            this.MySQL_button.Checked = true;
            this.MySQL_button.ForeColor = System.Drawing.Color.Black;
            this.MySQL_button.Location = new System.Drawing.Point(73, 17);
            this.MySQL_button.Name = "MySQL_button";
            this.MySQL_button.Size = new System.Drawing.Size(61, 15);
            this.MySQL_button.TabIndex = 3;
            this.MySQL_button.TabStop = true;
            this.MySQL_button.Text = "MySQL";
            this.MySQL_button.UseSelectable = true;
            // 
            // SQLite_button
            // 
            this.SQLite_button.AutoSize = true;
            this.SQLite_button.Location = new System.Drawing.Point(213, 17);
            this.SQLite_button.Name = "SQLite_button";
            this.SQLite_button.Size = new System.Drawing.Size(57, 15);
            this.SQLite_button.TabIndex = 4;
            this.SQLite_button.Text = "SQLite";
            this.SQLite_button.UseSelectable = true;
            // 
            // start_button
            // 
            this.start_button.BackColor = System.Drawing.Color.White;
            this.start_button.FlatAppearance.BorderColor = System.Drawing.Color.LightGray;
            this.start_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.start_button.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.start_button.ForeColor = System.Drawing.SystemColors.ControlText;
            this.start_button.Location = new System.Drawing.Point(315, 370);
            this.start_button.Name = "start_button";
            this.start_button.Size = new System.Drawing.Size(82, 30);
            this.start_button.TabIndex = 5;
            this.start_button.Text = "시작하기";
            this.start_button.UseVisualStyleBackColor = false;
            this.start_button.Click += new System.EventHandler(this.start_button_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.MySQL_button);
            this.groupBox1.Controls.Add(this.SQLite_button);
            this.groupBox1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.groupBox1.Location = new System.Drawing.Point(180, 270);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(363, 44);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(700, 500);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.start_button);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "재고관리";
            this.panel1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private MetroFramework.Controls.MetroRadioButton MySQL_button;
        private MetroFramework.Controls.MetroRadioButton SQLite_button;
        private System.Windows.Forms.Button closebutton;
        private System.Windows.Forms.Button start_button;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

