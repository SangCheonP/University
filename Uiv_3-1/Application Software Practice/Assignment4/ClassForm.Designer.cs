
namespace _0518
{
    partial class ClassForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.pboxNone = new System.Windows.Forms.PictureBox();
            this.pboxStar = new System.Windows.Forms.PictureBox();
            this.pboxMoon = new System.Windows.Forms.PictureBox();
            this.pboxSun = new System.Windows.Forms.PictureBox();
            this.rdoPlayer1 = new System.Windows.Forms.RadioButton();
            this.rdoPlayer2 = new System.Windows.Forms.RadioButton();
            this.listBoxResult1 = new System.Windows.Forms.ListBox();
            this.listBoxResult2 = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.pboxNone)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxStar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxMoon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxSun)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(409, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "- Player는 한번씩 돌아가면서 그림을 선택합니다.";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(559, 18);
            this.label2.TabIndex = 1;
            this.label2.Text = "- 각 10회 진행 후 과일의 숫자의 합이 가장 높은 사람이 승리합니다.";
            // 
            // pboxNone
            // 
            this.pboxNone.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.pboxNone.Location = new System.Drawing.Point(632, 82);
            this.pboxNone.Name = "pboxNone";
            this.pboxNone.Size = new System.Drawing.Size(197, 193);
            this.pboxNone.TabIndex = 5;
            this.pboxNone.TabStop = false;
            this.pboxNone.Click += new System.EventHandler(this.pboxNone_Click);
            // 
            // pboxStar
            // 
            this.pboxStar.Image = global::_0518.Properties.Resources.별;
            this.pboxStar.Location = new System.Drawing.Point(429, 82);
            this.pboxStar.Name = "pboxStar";
            this.pboxStar.Size = new System.Drawing.Size(197, 193);
            this.pboxStar.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pboxStar.TabIndex = 4;
            this.pboxStar.TabStop = false;
            this.pboxStar.Click += new System.EventHandler(this.pboxStar_Click);
            // 
            // pboxMoon
            // 
            this.pboxMoon.Image = global::_0518.Properties.Resources.달;
            this.pboxMoon.Location = new System.Drawing.Point(226, 82);
            this.pboxMoon.Name = "pboxMoon";
            this.pboxMoon.Size = new System.Drawing.Size(197, 193);
            this.pboxMoon.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pboxMoon.TabIndex = 3;
            this.pboxMoon.TabStop = false;
            this.pboxMoon.Click += new System.EventHandler(this.pboxMoon_Click);
            // 
            // pboxSun
            // 
            this.pboxSun.Image = global::_0518.Properties.Resources.해;
            this.pboxSun.Location = new System.Drawing.Point(23, 82);
            this.pboxSun.Name = "pboxSun";
            this.pboxSun.Size = new System.Drawing.Size(197, 193);
            this.pboxSun.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pboxSun.TabIndex = 2;
            this.pboxSun.TabStop = false;
            this.pboxSun.Click += new System.EventHandler(this.pboxSun_Click);
            // 
            // rdoPlayer1
            // 
            this.rdoPlayer1.AutoSize = true;
            this.rdoPlayer1.Location = new System.Drawing.Point(179, 326);
            this.rdoPlayer1.Name = "rdoPlayer1";
            this.rdoPlayer1.Size = new System.Drawing.Size(93, 22);
            this.rdoPlayer1.TabIndex = 6;
            this.rdoPlayer1.TabStop = true;
            this.rdoPlayer1.Text = "Player1";
            this.rdoPlayer1.UseVisualStyleBackColor = true;
            // 
            // rdoPlayer2
            // 
            this.rdoPlayer2.AutoSize = true;
            this.rdoPlayer2.Location = new System.Drawing.Point(572, 326);
            this.rdoPlayer2.Name = "rdoPlayer2";
            this.rdoPlayer2.Size = new System.Drawing.Size(93, 22);
            this.rdoPlayer2.TabIndex = 6;
            this.rdoPlayer2.TabStop = true;
            this.rdoPlayer2.Text = "Player2";
            this.rdoPlayer2.UseVisualStyleBackColor = true;
            // 
            // listBoxResult1
            // 
            this.listBoxResult1.FormattingEnabled = true;
            this.listBoxResult1.ItemHeight = 18;
            this.listBoxResult1.Location = new System.Drawing.Point(24, 376);
            this.listBoxResult1.Name = "listBoxResult1";
            this.listBoxResult1.Size = new System.Drawing.Size(402, 400);
            this.listBoxResult1.TabIndex = 7;
            // 
            // listBoxResult2
            // 
            this.listBoxResult2.FormattingEnabled = true;
            this.listBoxResult2.ItemHeight = 18;
            this.listBoxResult2.Location = new System.Drawing.Point(432, 376);
            this.listBoxResult2.Name = "listBoxResult2";
            this.listBoxResult2.Size = new System.Drawing.Size(402, 400);
            this.listBoxResult2.TabIndex = 8;
            // 
            // ClassForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(870, 808);
            this.Controls.Add(this.listBoxResult2);
            this.Controls.Add(this.listBoxResult1);
            this.Controls.Add(this.rdoPlayer2);
            this.Controls.Add(this.rdoPlayer1);
            this.Controls.Add(this.pboxNone);
            this.Controls.Add(this.pboxStar);
            this.Controls.Add(this.pboxMoon);
            this.Controls.Add(this.pboxSun);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "ClassForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ClassForm";
            ((System.ComponentModel.ISupportInitialize)(this.pboxNone)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxStar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxMoon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pboxSun)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox pboxSun;
        private System.Windows.Forms.PictureBox pboxMoon;
        private System.Windows.Forms.PictureBox pboxStar;
        private System.Windows.Forms.PictureBox pboxNone;
        private System.Windows.Forms.RadioButton rdoPlayer1;
        private System.Windows.Forms.RadioButton rdoPlayer2;
        private System.Windows.Forms.ListBox listBoxResult1;
        private System.Windows.Forms.ListBox listBoxResult2;
    }
}