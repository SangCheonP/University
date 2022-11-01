#include<stdio.h>

int main(void)
{
	int dan = 0;

	for (dan = 1; dan < 10; dan++)
	{
		if (dan % 2 == 0)
		{
			printf("%d´Ü \n", dan);
			for (int i = 1; i < 10; i++)
			{
				printf("%d X %d = %d \n", dan, i, dan * i);
			}
			printf("\n");
		}
		else
		{
			continue;
		}
	}
	return 0;
}