#include <stdio.h>

#include <math.h>

int main(void)

{
    //202020300 �ڻ�õ
    // ���� ����

    double x1, x2, x3, y1, y2, y3;

    double a, b, c, d, e, result, err;

    double f, g, h, i, j, result2;

    int x_1, x_2, x_3, y_1, y_2, y_3;

    //��� 1: ��ǥ�� �Է�

    printf("ù ��° ��ǥ: ");

    scanf_s("%lf %lf", &x1, &y1);

    printf("�� ��° ��ǥ: ");

    scanf_s("%lf %lf", &x2, &y2);

    printf("�� ��° ��ǥ: ");

    scanf_s("%lf %lf", &x3, &y3);

    //��� 2: ���� ��� �� ���

    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

    c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    e = (a + b + c) / 2;

    result = sqrt(e * (e - a) * (e - b) * (e - c)); //����� �������� �ﰢ���� ���� 

    printf("�ﰢ�� ���̴�: %lf\n", result);

    d = result * result;

    printf("�ﰢ�� ������ ����: %lf\n", d);

    //��� 3: ��ǥ ������ ������ ��ȯ
    x_1 = (int)x1;

    x_2 = (int)x2;

    x_3 = (int)x3;

    y_1 = (int)y1;

    y_2 = (int)y2;

    y_3 = (int)y3;

    //��� 4: ���� ���
    f = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));

    g = sqrt((x_3 - x_2) * (x_3 - x_2) + (y_3 - y_2) * (y_3 - y_2));

    h = sqrt((x_3 - x_1) * (x_3 - x_1) + (y_3 - y_1) * (y_3 - y_1));

    i = (f + g + h) / 2;

    result2 = sqrt(i * (i - f) * (i - g) * (i - h));

    printf("������ ��ȯ�� ��ǥ�� �ﰢ�� ���̴�: %f \n", result2);

    //���� �� ��ȯ �� �ﰢ�� ������ ���� ���
    j = result2 * result2;

    printf("��ǥ�� ���� ��ȯ�� �ﰢ�� ������ ����: %f \n", j);

    //���� ���
    err = d - j;

    printf("������ ���� ������ ����: %f\n", err);

    return 0;

}