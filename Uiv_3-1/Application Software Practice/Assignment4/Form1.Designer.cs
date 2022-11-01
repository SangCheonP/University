
namespace _0518
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.winFormExToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cBasicToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.arrayDataGridViewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.classToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureViewerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.winFormExToolStripMenuItem,
            this.cBasicToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1409, 33);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // winFormExToolStripMenuItem
            // 
            this.winFormExToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.pictureViewerToolStripMenuItem});
            this.winFormExToolStripMenuItem.Name = "winFormExToolStripMenuItem";
            this.winFormExToolStripMenuItem.Size = new System.Drawing.Size(118, 29);
            this.winFormExToolStripMenuItem.Text = "WinFormEx";
            // 
            // cBasicToolStripMenuItem
            // 
            this.cBasicToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.arrayDataGridViewToolStripMenuItem,
            this.classToolStripMenuItem});
            this.cBasicToolStripMenuItem.Name = "cBasicToolStripMenuItem";
            this.cBasicToolStripMenuItem.Size = new System.Drawing.Size(97, 29);
            this.cBasicToolStripMenuItem.Text = "C# Basic";
            // 
            // arrayDataGridViewToolStripMenuItem
            // 
            this.arrayDataGridViewToolStripMenuItem.Name = "arrayDataGridViewToolStripMenuItem";
            this.arrayDataGridViewToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.arrayDataGridViewToolStripMenuItem.Text = "ArrayDataGridView";
            this.arrayDataGridViewToolStripMenuItem.Click += new System.EventHandler(this.arrayDataGridViewToolStripMenuItem_Click);
            // 
            // classToolStripMenuItem
            // 
            this.classToolStripMenuItem.Name = "classToolStripMenuItem";
            this.classToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.classToolStripMenuItem.Text = "Class";
            this.classToolStripMenuItem.Click += new System.EventHandler(this.classToolStripMenuItem_Click);
            // 
            // pictureViewerToolStripMenuItem
            // 
            this.pictureViewerToolStripMenuItem.Name = "pictureViewerToolStripMenuItem";
            this.pictureViewerToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.pictureViewerToolStripMenuItem.Text = "PictureViewer";
            this.pictureViewerToolStripMenuItem.Click += new System.EventHandler(this.pictureViewerToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1409, 914);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem winFormExToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cBasicToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem arrayDataGridViewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem classToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pictureViewerToolStripMenuItem;
    }
}

