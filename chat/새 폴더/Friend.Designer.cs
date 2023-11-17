
namespace chat
{
    partial class Friend
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

        #region 구성 요소 디자이너에서 생성한 코드

        /// <summary> 
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel = new System.Windows.Forms.Panel();
            this.f1_pictureBox = new System.Windows.Forms.PictureBox();
            this.name_label = new System.Windows.Forms.Label();
            this.panel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.f1_pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // panel
            // 
            this.panel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel.BackColor = System.Drawing.SystemColors.Window;
            this.panel.Controls.Add(this.f1_pictureBox);
            this.panel.Controls.Add(this.name_label);
            this.panel.Location = new System.Drawing.Point(0, 0);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(310, 85);
            this.panel.TabIndex = 10;
            // 
            // f1_pictureBox
            // 
            this.f1_pictureBox.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.f1_pictureBox.Image = global::chat.Properties.Resources.프사;
            this.f1_pictureBox.Location = new System.Drawing.Point(14, 14);
            this.f1_pictureBox.Name = "f1_pictureBox";
            this.f1_pictureBox.Size = new System.Drawing.Size(45, 46);
            this.f1_pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.f1_pictureBox.TabIndex = 4;
            this.f1_pictureBox.TabStop = false;
            this.f1_pictureBox.Click += new System.EventHandler(this.f1_pictureBox_Click);
            // 
            // name_label
            // 
            this.name_label.AutoSize = true;
            this.name_label.Cursor = System.Windows.Forms.Cursors.Hand;
            this.name_label.Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.name_label.Location = new System.Drawing.Point(65, 31);
            this.name_label.Name = "name_label";
            this.name_label.Size = new System.Drawing.Size(41, 17);
            this.name_label.TabIndex = 5;
            this.name_label.Text = "친구1";
            this.name_label.Click += new System.EventHandler(this.name_label_Click);
            // 
            // Friend
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panel);
            this.Name = "Friend";
            this.Size = new System.Drawing.Size(310, 85);
            this.panel.ResumeLayout(false);
            this.panel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.f1_pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel;
        private System.Windows.Forms.PictureBox f1_pictureBox;
        private System.Windows.Forms.Label name_label;
    }
}
