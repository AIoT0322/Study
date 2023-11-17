
namespace chat
{
    partial class friend_chat
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
            this.label1 = new System.Windows.Forms.Label();
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
            this.panel.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.panel.Controls.Add(this.label1);
            this.panel.Controls.Add(this.f1_pictureBox);
            this.panel.Controls.Add(this.name_label);
            this.panel.Location = new System.Drawing.Point(0, 0);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(310, 50);
            this.panel.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.Window;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(58, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(30, 15);
            this.label1.TabIndex = 6;
            this.label1.Text = "chat";
            // 
            // f1_pictureBox
            // 
            this.f1_pictureBox.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.f1_pictureBox.Image = global::chat.Properties.Resources.프사_removebg_preview;
            this.f1_pictureBox.Location = new System.Drawing.Point(4, 2);
            this.f1_pictureBox.Name = "f1_pictureBox";
            this.f1_pictureBox.Size = new System.Drawing.Size(45, 46);
            this.f1_pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.f1_pictureBox.TabIndex = 4;
            this.f1_pictureBox.TabStop = false;
            // 
            // name_label
            // 
            this.name_label.AutoSize = true;
            this.name_label.Cursor = System.Windows.Forms.Cursors.Hand;
            this.name_label.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.name_label.Location = new System.Drawing.Point(53, 9);
            this.name_label.Name = "name_label";
            this.name_label.Size = new System.Drawing.Size(38, 15);
            this.name_label.TabIndex = 5;
            this.name_label.Text = "친구1";
            // 
            // friend_chat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panel);
            this.Name = "friend_chat";
            this.Size = new System.Drawing.Size(310, 50);
            this.panel.ResumeLayout(false);
            this.panel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.f1_pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel;
        private System.Windows.Forms.PictureBox f1_pictureBox;
        private System.Windows.Forms.Label name_label;
        private System.Windows.Forms.Label label1;
    }
}
