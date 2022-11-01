#include <stdio.h>

#include <math.h>

int main(void)

{
    //202020300 박상천
    // 변수 선언

    double x1, x2, x3, y1, y2, y3;

    double a, b, c, d, e, result, err;

    double f, g, h, i, j, result2;

    int x_1, x_2, x_3, y_1, y_2, y_3;

    //기능 1: 좌표값 입력

    printf("첫 번째 좌표: ");

    scanf_s("%lf %lf", &x1, &y1);

    printf("두 번째 좌표: ");

    scanf_s("%lf %lf", &x2, &y2);

    printf("세 번째 좌표: ");

    scanf_s("%lf %lf", &x3, &y3);

    //기능 2: 넓이 계산 및 출력

    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

    c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    e = (a + b + c) / 2;

    result = sqrt(e * (e - a) * (e - b) * (e - c)); //헤론의 공식으로 삼각형의 면적 

    printf("삼각형 넓이는: %lf\n", result);

    d = result * result;

    printf("삼각형 넓이의 제곱: %lf\n", d);

    //기능 3: 좌표 변수의 정수형 변환
    x_1 = (int)x1;

    x_2 = (int)x2;

    x_3 = (int)x3;

    y_1 = (int)y1;

    y_2 = (int)y2;

    y_3 = (int)y3;

    //기능 4: 오차 출력
    f = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));

    g = sqrt((x_3 - x_2) * (x_3 - x_2) + (y_3 - y_2) * (y_3 - y_2));

    h = sqrt((x_3 - x_1) * (x_3 - x_1) + (y_3 - y_1) * (y_3 - y_1));

    i = (f + g + h) / 2;

    result2 = sqrt(i * (i - f) * (i - g) * (i - h));

    printf("정수형 변환된 좌표의 삼각형 넓이는: %f \n", result2);

    //정수 형 변환 후 삼각형 넓이의 제곱 계산
    j = result2 * result2;

    printf("좌표의 정수 변환후 삼각형 넓이의 제곱: %f \n", j);

    //오차 계산
    err = d - j;

    printf("넓이의 제곱 사이의 오차: %f\n", err);

    return 0;

}