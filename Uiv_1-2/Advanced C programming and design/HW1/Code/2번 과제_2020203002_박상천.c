#include<stdio.h>

int main(void)
{
	float num1, num2, num3, num4;
	float sum;
	float avg;

	printf("ù��° ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%f", &num1);
	printf("�ι�° ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%f", &num2);
	printf("����° ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%f", &num3);
	printf("�׹�° ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%f", &num4);

	sum = num1 + num2 + num3 + num4;
	avg = sum / 4;

	printf("%f, %f, %f, %f�� ����� %f�̴�. \n", num1, num2, num3, num4, avg);
	return 0;
}