using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0518
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void arrayDataGridViewToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new ArraryDataForm().ShowDialog();
        }

        private void classToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new ClassForm().ShowDialog();
        }

        private void pictureViewerToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new PictureViewer().ShowDialog();
        }
    }
}
