#include<stdio.h>

int main(void)
{
    int i, num, cnt = 0;
    int c;
    int max = 0, min = 100;

    for (i = 0; cnt < 10; i++)
    {
        printf("�� �ڸ� ������ �ڿ����� �Է����ּ��� : ");
        scanf_s("%d", &num);
        if (cnt == 0 && num == 99)
        {
            printf("�Էµ� ���� �����Ƿ�, �ִ�/�ּڰ��� �������� �ʽ��ϴ�.");
            c = 1;
            break;
        }
        if (num > 99)
        {
            printf("100���� ���� ������ �Է��ϼ���.\n");
            continue;
        }
        else if (num <= 0)
        {
            printf("0���� ū ������ �Է��ϼ���.\n");
            continue;
        }
        else if (num == 99)
        {
            break;
        }
        else
        {
            if (max < num)
            {
                max = num;
            }
            if (min > num)
            {
                min = num;
            }
            c = 0;
            cnt += 1;
        }
    }
    if (c == 0)
    {
        printf("�ִ��� %d, �ּڰ��� %d�̴�.", max, min);
    }
    return 0;
}