#include<stdio.h>

int main(void)
{
	float num1, num2, num3, num4;
	float sum;
	float avg;

	printf("첫번째 숫자를 입력하시오 : ");
	scanf_s("%f", &num1);
	printf("두번째 숫자를 입력하시오 : ");
	scanf_s("%f", &num2);
	printf("세번째 숫자를 입력하시오 : ");
	scanf_s("%f", &num3);
	printf("네번째 숫자를 입력하시오 : ");
	scanf_s("%f", &num4);

	sum = num1 + num2 + num3 + num4;
	avg = sum / 4;

	printf("%f, %f, %f, %f의 평균은 %f이다. \n", num1, num2, num3, num4, avg);
	return 0;
}