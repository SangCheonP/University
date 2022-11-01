#include<stdio.h>

int main(void)
{
	int arr1[3][2] = { 1,2,3,4,5,6 };
	int arr2[2][3];
	int i, j;

	/*배열 교체하기*/
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr2[i][j] = arr1[j][i];
		}
	}

	/*3x2배열 출력하기*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	/*2x3배열 출력하기*/
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	return 0;
}