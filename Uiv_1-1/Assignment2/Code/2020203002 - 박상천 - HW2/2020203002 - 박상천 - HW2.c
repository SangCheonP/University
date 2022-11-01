#include <stdio.h>

int main(void)
{
	unsigned long long input;
	int memory[4] = { 0 };  

	printf("Address Field [8Byte] 값을 입력하세요 : ");
	scanf_s("%lld", &input); 
	int bit = 1; 
	for (int i = 0; i < 16; i++) {
		bit *= 2;
	}
	bit -= 1;

	for (int i = 0; i < 4; i++) {
		memory[i] = bit & input;
		for (int i = 0; i < 16; i++) {
			input /= 2;
		}
	}

	printf("Destination PAN ID(2byte)  : 16진수 = %4x, 10진수 = %5d\n", memory[3], memory[3]);
	printf("Destination Address(2byte) : 16진수 = %4x, 10진수 = %5d\n", memory[2], memory[2]);
	printf("Source PAN ID(2byte)       : 16진수 = %4x, 10진수 = %5d\n", memory[1], memory[1]);
	printf("Source Address(2byte)      : 16진수 = %4x, 10진수 = %5d\n", memory[0], memory[0]);

	return 0;
}