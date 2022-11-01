using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonFor_Click(object sender, EventArgs e)
        {
            textBoxResult.Text = string.Empty;
            StringBuilder sb = new StringBuilder();
            int iResult = 0;

            for(int i=1; i<=10; i++)
            {
                iResult = iResult + i;
                sb.Append(string.Format("1에서 {0}까지 더하면 {1} \r\n", i, iResult));
            }
            textBoxResult.Text = sb.ToString();
        }

        private void buttonForeach_Click(object sender, EventArgs e)
        {
            textBoxResult.Text = String.Empty;
            StringBuilder sb = new StringBuilder();

            string[] strArray = { "나연", "정연", "모모", "사나", "지효", "미나", "다현", "쯔위", "채영" };
            int i = 65;
            foreach(string str in strArray) {
                sb.Append(string.Format("{0} 교수 강의는 {1}반 입니다.\r\n", str, (char)i++));
            }
            textBoxResult.Text = sb.ToString().Trim();
        }

        private void buttonWhile_Click(object sender, EventArgs e)
        {
            textBoxResult.Text = String.Empty;
            StringBuilder sb = new StringBuilder();
            int n1 = 2;
            int n2 = 1;
            sb.Append("2단\r\n");
            while(n2 < 10)
            {
                sb.Append(string.Format("{0} * {1} = {2}\r\n", n1, n2, n1 * n2));
                n2++;
            }
            textBoxResult.Text = sb.ToString();
        }
    }
}
