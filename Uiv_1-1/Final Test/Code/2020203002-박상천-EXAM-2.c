#include<stdio.h>

int main(void)
{
    int i, num, cnt = 0;
    int c;
    int max = 0, min = 100;

    for (i = 0; cnt < 10; i++)
    {
        printf("두 자리 이하의 자연수를 입력해주세여 : ");
        scanf_s("%d", &num);
        if (cnt == 0 && num == 99)
        {
            printf("입력된 값이 없으므로, 최대/최솟값은 존재하지 않습니다.");
            c = 1;
            break;
        }
        if (num > 99)
        {
            printf("100보다 작은 정수를 입력하세요.\n");
            continue;
        }
        else if (num <= 0)
        {
            printf("0보다 큰 정수를 입력하세요.\n");
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
        printf("최댓값은 %d, 최솟값은 %d이다.", max, min);
    }
    return 0;
}