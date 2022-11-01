
namespace _0518
{
    partial class ArraryDataForm
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
            this.dgDay = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.colDay1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colDay7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dgDay)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "매장 방문 수";
            // 
            // dgDay
            // 
            this.dgDay.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgDay.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colDay1,
            this.colDay2,
            this.colDay3,
            this.colDay4,
            this.colDay5,
            this.colDay6,
            this.colDay7});
            this.dgDay.Location = new System.Drawing.Point(12, 64);
            this.dgDay.Name = "dgDay";
            this.dgDay.RowHeadersWidth = 62;
            this.dgDay.RowTemplate.Height = 30;
            this.dgDay.Size = new System.Drawing.Size(1415, 174);
            this.dgDay.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 268);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(243, 102);
            this.button1.TabIndex = 2;
            this.button1.Text = "일주일간";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(288, 268);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(240, 102);
            this.button2.TabIndex = 2;
            this.button2.Text = "이주일간";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // colDay1
            // 
            this.colDay1.HeaderText = "월";
            this.colDay1.MinimumWidth = 8;
            this.colDay1.Name = "colDay1";
            this.colDay1.Width = 150;
            // 
            // colDay2
            // 
            this.colDay2.HeaderText = "화";
            this.colDay2.MinimumWidth = 8;
            this.colDay2.Name = "colDay2";
            this.colDay2.Width = 150;
            // 
            // colDay3
            // 
            this.colDay3.HeaderText = "수";
            this.colDay3.MinimumWidth = 8;
            this.colDay3.Name = "colDay3";
            this.colDay3.Width = 150;
            // 
            // colDay4
            // 
            this.colDay4.HeaderText = "목";
            this.colDay4.MinimumWidth = 8;
            this.colDay4.Name = "colDay4";
            this.colDay4.Width = 150;
            // 
            // colDay5
            // 
            this.colDay5.HeaderText = "금";
            this.colDay5.MinimumWidth = 8;
            this.colDay5.Name = "colDay5";
            this.colDay5.Width = 150;
            // 
            // colDay6
            // 
            this.colDay6.HeaderText = "토";
            this.colDay6.MinimumWidth = 8;
            this.colDay6.Name = "colDay6";
            this.colDay6.Width = 150;
            // 
            // colDay7
            // 
            this.colDay7.HeaderText = "일";
            this.colDay7.MinimumWidth = 8;
            this.colDay7.Name = "colDay7";
            this.colDay7.Width = 150;
            // 
            // ArraryDataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1439, 591);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dgDay);
            this.Controls.Add(this.label1);
            this.Name = "ArraryDataForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ArraryDataForm";
            ((System.ComponentModel.ISupportInitialize)(this.dgDay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dgDay;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay1;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay2;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay3;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay4;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay5;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay6;
        private System.Windows.Forms.DataGridViewTextBoxColumn colDay7;
    }
}