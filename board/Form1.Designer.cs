
namespace board
{
    partial class Form1
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
            this.userMessageBoxList = new board.UserMessageBoxList();
            this.textBox = new System.Windows.Forms.TextBox();
            this.submitbutton = new System.Windows.Forms.Button();
            this.refreshbutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // userMessageBoxList
            // 
            this.userMessageBoxList.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.userMessageBoxList.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.userMessageBoxList.Location = new System.Drawing.Point(0, 0);
            this.userMessageBoxList.Name = "userMessageBoxList";
            this.userMessageBoxList.Size = new System.Drawing.Size(799, 412);
            this.userMessageBoxList.TabIndex = 0;
            // 
            // textBox
            // 
            this.textBox.Location = new System.Drawing.Point(0, 411);
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(799, 21);
            this.textBox.TabIndex = 1;
            // 
            // submitbutton
            // 
            this.submitbutton.Location = new System.Drawing.Point(724, 432);
            this.submitbutton.Name = "submitbutton";
            this.submitbutton.Size = new System.Drawing.Size(75, 23);
            this.submitbutton.TabIndex = 2;
            this.submitbutton.Text = "확인";
            this.submitbutton.UseVisualStyleBackColor = true;
            this.submitbutton.Click += new System.EventHandler(this.submitbutton_Click);
            // 
            // refreshbutton
            // 
            this.refreshbutton.Location = new System.Drawing.Point(0, 432);
            this.refreshbutton.Name = "refreshbutton";
            this.refreshbutton.Size = new System.Drawing.Size(75, 23);
            this.refreshbutton.TabIndex = 3;
            this.refreshbutton.Text = "새로고침";
            this.refreshbutton.UseVisualStyleBackColor = true;
            this.refreshbutton.Click += new System.EventHandler(this.refreshbutton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 457);
            this.Controls.Add(this.refreshbutton);
            this.Controls.Add(this.submitbutton);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.userMessageBoxList);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private UserMessageBoxList userMessageBoxList;
        private System.Windows.Forms.TextBox textBox;
        private System.Windows.Forms.Button submitbutton;
        private System.Windows.Forms.Button refreshbutton;
    }
}

