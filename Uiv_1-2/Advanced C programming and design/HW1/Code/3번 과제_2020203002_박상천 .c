#include<stdio.h>

int main(void)
{
	int high = 100, low = 1;
	int srt = (high + low) / 2;
	int num;

	printf("%d�� ������ �����ΰ���? \n", srt);
	printf("�´� ��ȣ�� ���ÿ�. \n");
	printf("1) �� ũ�� 2) �� �۴� 3) ������ �����̴�. : ", srt, srt);

	do
	{
		scanf_s("%d", &num);
		printf("\n");
		if (num == 1)
		{
			low = srt + 1;
			srt = (high + low) / 2;
			printf("�۰� ���߱���, %d�ΰ���? : ", srt);
		}
		else if (num == 2)
		{
			high = srt - 1;
			srt = (high + low) / 2;
			printf("ũ�� ���߱���, %d�ΰ���? : ", srt);
		}
		else if (num == 3)
		{
			printf("���� %d�� ������ϴ�. ���մϴ�!", srt);
		}
		else
		{
			printf("�ٽ� �Է����ּ���. : ");
		}
	} while (num != 3);

	return 0;
}
