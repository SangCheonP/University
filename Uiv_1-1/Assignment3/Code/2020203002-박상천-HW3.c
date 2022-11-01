#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int SDT[50];

	int i = 0;

	for (i = 0; i < 50; i++) 
		SDT[i] = rand()%101;

	for (i = 0; i < 50; i++)
		printf("학생 %d의 점수는 %d이다. \n", i+1, SDT[i]);

	int temp;
	for (i = 0; i < 50; i++) {
		for (int j = 0; j < 50 - i - 1; j++) {
			if (SDT[j] > SDT[j + 1]) {
				temp = SDT[j];
				SDT[j] = SDT[j + 1];
				SDT[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 50; i++) {
		printf("%d \n", SDT[i]);
	}

	return 0;
}