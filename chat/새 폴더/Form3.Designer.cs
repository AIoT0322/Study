
namespace chat
{
    partial class chat_Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.send_textbox = new System.Windows.Forms.RichTextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.send_button = new System.Windows.Forms.Button();
            this.chat_list1 = new chat.chat_list();
            this.SuspendLayout();
            // 
            // send_textbox
            // 
            this.send_textbox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.send_textbox.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.send_textbox.Location = new System.Drawing.Point(7, 478);
            this.send_textbox.Name = "send_textbox";
            this.send_textbox.Size = new System.Drawing.Size(269, 31);
            this.send_textbox.TabIndex = 6;
            this.send_textbox.Text = "";
            this.send_textbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.EnterKey);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.Window;
            this.panel1.Location = new System.Drawing.Point(0, 472);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(283, 40);
            this.panel1.TabIndex = 7;
            // 
            // button1
            // 
            this.button1.FlatAppearance.BorderSize = 0;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Image = global::chat.Properties.Resources.x1;
            this.button1.Location = new System.Drawing.Point(317, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(15, 15);
            this.button1.TabIndex = 8;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // send_button
            // 
            this.send_button.Cursor = System.Windows.Forms.Cursors.Hand;
            this.send_button.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.send_button.FlatAppearance.BorderSize = 0;
            this.send_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.send_button.Image = global::chat.Properties.Resources.버튼;
            this.send_button.Location = new System.Drawing.Point(283, 472);
            this.send_button.Name = "send_button";
            this.send_button.Size = new System.Drawing.Size(51, 39);
            this.send_button.TabIndex = 5;
            this.send_button.UseVisualStyleBackColor = true;
            this.send_button.Click += new System.EventHandler(this.send_button_Click);
            // 
            // chat_list1
            // 
            this.chat_list1.AutoScroll = true;
            this.chat_list1.Location = new System.Drawing.Point(0, 21);
            this.chat_list1.Name = "chat_list1";
            this.chat_list1.Size = new System.Drawing.Size(334, 451);
            this.chat_list1.TabIndex = 11;
            // 
            // chat_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.ClientSize = new System.Drawing.Size(334, 511);
            this.Controls.Add(this.chat_list1);
            this.Controls.Add(this.send_textbox);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.send_button);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "chat_Form";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.chat_Form_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.chat_Form_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.chat_Form_MouseMove);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox send_textbox;
        private System.Windows.Forms.Button send_button;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button1;
        private chat_list chat_list1;
    }
}