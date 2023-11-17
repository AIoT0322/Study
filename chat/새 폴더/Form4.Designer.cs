
namespace chat
{
    partial class list_Form
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
            this.friend_label = new System.Windows.Forms.Label();
            this.user_label = new System.Windows.Forms.Label();
            this.user_pictureBox = new System.Windows.Forms.PictureBox();
            this.friend_list1 = new chat.Friend_list();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.user_pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // friend_label
            // 
            this.friend_label.AutoSize = true;
            this.friend_label.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.friend_label.Location = new System.Drawing.Point(27, 146);
            this.friend_label.Name = "friend_label";
            this.friend_label.Size = new System.Drawing.Size(60, 17);
            this.friend_label.TabIndex = 0;
            this.friend_label.Text = "친구목록";
            // 
            // user_label
            // 
            this.user_label.AutoSize = true;
            this.user_label.Font = new System.Drawing.Font("맑은 고딕", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.user_label.Location = new System.Drawing.Point(87, 78);
            this.user_label.Name = "user_label";
            this.user_label.Size = new System.Drawing.Size(89, 20);
            this.user_label.TabIndex = 2;
            this.user_label.Text = "사용자 이름";
            // 
            // user_pictureBox
            // 
            this.user_pictureBox.BackColor = System.Drawing.SystemColors.Window;
            this.user_pictureBox.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.user_pictureBox.Image = global::chat.Properties.Resources.프사;
            this.user_pictureBox.Location = new System.Drawing.Point(29, 59);
            this.user_pictureBox.Name = "user_pictureBox";
            this.user_pictureBox.Size = new System.Drawing.Size(55, 55);
            this.user_pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.user_pictureBox.TabIndex = 3;
            this.user_pictureBox.TabStop = false;
            // 
            // friend_list1
            // 
            this.friend_list1.Location = new System.Drawing.Point(12, 166);
            this.friend_list1.Name = "friend_list1";
            this.friend_list1.Size = new System.Drawing.Size(310, 333);
            this.friend_list1.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 12.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(13, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 23);
            this.label1.TabIndex = 5;
            this.label1.Text = "친구";
            // 
            // label3
            // 
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label3.Location = new System.Drawing.Point(14, 131);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(300, 2);
            this.label3.TabIndex = 32;
            // 
            // list_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(334, 511);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.friend_list1);
            this.Controls.Add(this.user_pictureBox);
            this.Controls.Add(this.user_label);
            this.Controls.Add(this.friend_label);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "list_Form";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form4";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.list_Form_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.list_Form_MouseMove);
            ((System.ComponentModel.ISupportInitialize)(this.user_pictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label friend_label;
        private System.Windows.Forms.Label user_label;
        private System.Windows.Forms.PictureBox user_pictureBox;
        private Friend_list friend_list1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
    }
}