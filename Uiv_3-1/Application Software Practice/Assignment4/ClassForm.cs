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
    public partial class ClassForm : Form
    {
        struct structPlayer{
            public int iCount;
            public int iSun;
            public int iMoon;
            public int iStar;

            public int iCardSum;

            public int CardSum(int iSun, int iMoon, int iStar) => iSun + iMoon + iStar;

            public string ResultText() => string.Format("{0}회) 해:{1}, 달:{2}, 별:{3} => 합계는 {4}입니다.", iCount, iSun, iMoon, iStar, iCardSum);
        }

        structPlayer structPlayer1;
        structPlayer structPlayer2;

        Random rd = new Random();

        public ClassForm()
        {
            InitializeComponent();
        }
        
        private void pboxSun_Click(object sender, EventArgs e)
        {
            int iNumber = rd.Next(1, 21);

            if (rdoPlayer1.Checked)
                structPlayer1.iSun = iNumber;
            else
                structPlayer2.iSun = iNumber;
            Result();
        }

        private void pboxMoon_Click(object sender, EventArgs e)
        {
            int iNumber = rd.Next(1, 21);

            if (rdoPlayer1.Checked)
                structPlayer1.iMoon = iNumber;
            else
                structPlayer2.iMoon = iNumber;
            Result();
        }

        private void pboxStar_Click(object sender, EventArgs e)
        {
            int iNumber = rd.Next(1, 21);

            if (rdoPlayer1.Checked)
                structPlayer1.iStar = iNumber;
            else
                structPlayer2.iStar = iNumber;
            Result();
        }
        private void pboxNone_Click(object sender, EventArgs e)
        {
            Result();
        }
        
        private void Result()
        {
            string strResult = string.Empty;

            if (rdoPlayer1.Checked)
            {
                structPlayer1.iCount++;
                structPlayer1.iCardSum += structPlayer1.CardSum(structPlayer1.iSun, structPlayer1.iMoon, structPlayer1.iStar);
                strResult = structPlayer1.ResultText();

                listBoxResult1.Items.Add(strResult);
            }
            else
            {
                structPlayer2.iCount++;
                structPlayer2.iCardSum += structPlayer2.CardSum(structPlayer2.iSun, structPlayer2.iMoon, structPlayer2.iStar);
                strResult = structPlayer2.ResultText();

                listBoxResult2.Items.Add(strResult);
            }
            iCheckChange();

            if(structPlayer1.iCount >= 5 && structPlayer2.iCount >= 5)
            {
                if (structPlayer1.iCardSum > structPlayer2.iCardSum)
                    MessageBox.Show("Player1이 이겼습니다.");
                else if (structPlayer1.iCardSum < structPlayer2.iCardSum)
                    MessageBox.Show("Player2이 이겼습니다.");
                else
                    MessageBox.Show("비겼습니다.");
            }
        }

        private void iCheckChange()
        {
            if (rdoPlayer1.Checked)
                rdoPlayer2.Checked = true;
            else
                rdoPlayer1.Checked = true;
        }

    }
}
