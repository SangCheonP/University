#include<stdio.h>

int main(void)
{
	int high = 100, low = 1;
	int srt = (high + low) / 2;
	int num;

	printf("%d이 생각한 숫자인가요? \n", srt);
	printf("맞는 번호를 고르시오. \n");
	printf("1) 더 크다 2) 더 작다 3) 생각한 숫자이다. : ", srt, srt);

	do
	{
		scanf_s("%d", &num);
		printf("\n");
		if (num == 1)
		{
			low = srt + 1;
			srt = (high + low) / 2;
			printf("작게 말했군요, %d인가요? : ", srt);
		}
		else if (num == 2)
		{
			high = srt - 1;
			srt = (high + low) / 2;
			printf("크게 말했군요, %d인가요? : ", srt);
		}
		else if (num == 3)
		{
			printf("정답 %d를 맞췄습니다. 축합니다!", srt);
		}
		else
		{
			printf("다시 입력해주세요. : ");
		}
	} while (num != 3);

	return 0;
}
