using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0511_2
{
    public partial class Form1 : Form
    {

        Random random = new Random(); //수를 랜덤하게 뽑음
        public int[] lot = new int[6]; //뽑은 번호를 저장할 배열
        public int[] WinningLot = new int[6]; //당첨 번호를 저장할 배열

        public Form1()
        {
            InitializeComponent();
        }

        private void SelectNumber_Click(object sender, EventArgs e)
        {
            int n;

            for (int i = 0; i < 6; i++) //처음 배열에 모드 -1로 저장
            {
                lot[i] = -1;
            }

            for (int i = 0; i < 6; i++)  //각 배열마다 1~45까지의 번호를 넣고 중복이 없게 넣음
            {
                while (true)
                {
                    n = random.Next(1, 46);
                    if (!lot.Contains(n))
                    {
                        lot[i] = n;
                        break;
                    }
                }
            }

            Array.Sort(lot); //오름차순으로 배열을 정리

            N1.Text = lot[0].ToString();  //각 label에 수를 string 형태로 출력
            N2.Text = lot[1].ToString();
            N3.Text = lot[2].ToString();
            N4.Text = lot[3].ToString();
            N5.Text = lot[4].ToString();
            N6.Text = lot[5].ToString();
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Close(); //종료함수
        }

        private void WinningResult_Click(object sender, EventArgs e)
        {
            int n;
            int count = 0;

            for (int i = 0; i < 6; i++) //처음 배열에 모드 -1로 저장
            {
                WinningLot[i] = -1;
            }

            for (int i = 0; i < 6; i++)  //각 배열마다 1~45까지의 번호를 넣고 중복이 없게 넣음
            {
                while (true)
                {
                    n = random.Next(1, 46);
                    if (!WinningLot.Contains(n))
                    {
                        WinningLot[i] = n;
                        break;
                    }
                }
            }

            Array.Sort(WinningLot); //오름차순으로 배열을 정리

            W1.Text = WinningLot[0].ToString();  //각 label에 수를 string 형태로 출력
            W2.Text = WinningLot[1].ToString();
            W3.Text = WinningLot[2].ToString();
            W4.Text = WinningLot[3].ToString();
            W5.Text = WinningLot[4].ToString();
            W6.Text = WinningLot[5].ToString();

            for (int i = 0; i < 6; i++) //뽑은 번호와 당첨 번호가 당첨확인 버튼을 누를때마다 체크하여 count에 같은 수의 갯수를 저장
            {
                if (lot[i] == WinningLot[i])
                {
                    count++;
                }
            }

            string a = String.Format("당첨된 번호 갯수는 {0} 개 입니다!", count.ToString()); //당첨된 번호 갯수를 textbox에 출력
            tboxResult.Text = a;
        }
    }
}
