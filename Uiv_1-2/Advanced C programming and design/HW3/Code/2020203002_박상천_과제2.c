#include<stdio.h>

int main(void)
{
	int arr1[3][3] = {
		{1,1,1},
		{2,2,2},
		{3,3,3}
	};
	int arr2[3][3] = {
		{1,2,3},
		{1,2,3},
		{1,2,3}
	};
	int arr3[3][3] = { 0 };
	int p, i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (p = 0; p < 3; p++)
			{
				arr3[i][j] += arr1[i][p] * arr2[p][j];
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}