#include <stdio.h>

int get_integer(void);
int permutation(int n, int r);
int factorial(int n);

int main(void)
{
    int a, b;

    a = get_integer();
    b = get_integer();

    printf("P(%d, %d) = %d \n", a, b, permutation(a, b));
    return 0;
}

int permutation(int n, int r)
{
    int num = n - r;
    int sum = 1;
    for (int i = 0; i < num; i++)
    {
        sum *= (i + 1);
    }
    return factorial(n) / sum;
}

int get_integer(void)
{
    int num;
    scanf_s("%d", &num);
    return num;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}