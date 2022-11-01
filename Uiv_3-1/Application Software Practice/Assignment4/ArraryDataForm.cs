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
    public partial class ArraryDataForm : Form
    {
        public ArraryDataForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int[] iTest = { 10, 51, 30, 4, 15, 22, 18 };

            string iname;

            for(int i = 0; i < iTest.Length; i++)
            {
                iname = "colDay" + string.Format("{0}", i + 1); //윈폼은 모두 string이라서
                dgDay[iname, 0].Value = iTest[i]; //colDay1등등 에 iTest의 값을 넣음
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int[,] iTest = {{10, 5, 30, 4, 15, 22, 18 },
                            { 11, 15, 25, 14, 7, 5, 29}};

            dgDay.Rows.Add();
            string iname;
            //string iname = string.Empty;

            for(int i = 0; i < iTest.GetLength(1); i++) //
            {
                iname = "colDay" + string.Format("{0}", i + 1);
                dgDay[iname, 0].Value = iTest[0, i];//iTest는 0행 i열
                dgDay[iname, 1].Value = iTest[1, i];
            }
        }
    }
}
