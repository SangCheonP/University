namespace WindowsFormsApp3
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
            this.textBoxResult = new System.Windows.Forms.TextBox();
            this.buttonFor = new System.Windows.Forms.Button();
            this.buttonForeach = new System.Windows.Forms.Button();
            this.buttonWhile = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxResult
            // 
            this.textBoxResult.Location = new System.Drawing.Point(17, 18);
            this.textBoxResult.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxResult.Multiline = true;
            this.textBoxResult.Name = "textBoxResult";
            this.textBoxResult.Size = new System.Drawing.Size(381, 391);
            this.textBoxResult.TabIndex = 0;
            // 
            // buttonFor
            // 
            this.buttonFor.Location = new System.Drawing.Point(449, 45);
            this.buttonFor.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonFor.Name = "buttonFor";
            this.buttonFor.Size = new System.Drawing.Size(194, 84);
            this.buttonFor.TabIndex = 1;
            this.buttonFor.Text = "for 문";
            this.buttonFor.UseVisualStyleBackColor = true;
            this.buttonFor.Click += new System.EventHandler(this.buttonFor_Click);
            // 
            // buttonForeach
            // 
            this.buttonForeach.Location = new System.Drawing.Point(449, 165);
            this.buttonForeach.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonForeach.Name = "buttonForeach";
            this.buttonForeach.Size = new System.Drawing.Size(194, 84);
            this.buttonForeach.TabIndex = 2;
            this.buttonForeach.Text = "foreach 문 ";
            this.buttonForeach.UseVisualStyleBackColor = true;
            this.buttonForeach.Click += new System.EventHandler(this.buttonForeach_Click);
            // 
            // buttonWhile
            // 
            this.buttonWhile.Location = new System.Drawing.Point(449, 292);
            this.buttonWhile.Margin = new System.Windows.Forms.Padding(4);
            this.buttonWhile.Name = "buttonWhile";
            this.buttonWhile.Size = new System.Drawing.Size(194, 84);
            this.buttonWhile.TabIndex = 3;
            this.buttonWhile.Text = "while 문 ";
            this.buttonWhile.UseVisualStyleBackColor = true;
            this.buttonWhile.Click += new System.EventHandler(this.buttonWhile_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(686, 454);
            this.Controls.Add(this.buttonWhile);
            this.Controls.Add(this.buttonForeach);
            this.Controls.Add(this.buttonFor);
            this.Controls.Add(this.textBoxResult);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxResult;
        private System.Windows.Forms.Button buttonFor;
        private System.Windows.Forms.Button buttonForeach;
        private System.Windows.Forms.Button buttonWhile;
    }
}

