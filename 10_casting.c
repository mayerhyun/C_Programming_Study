#include <stdio.h>

int main(void)
{
    int area = 5 * 5 * 3.14;       // 묵시적 형변환 int -> double
    double area1 = 10 / 5;         // 묵시적 형변환 double -> int
    double area2 = (double)25 / 4; // 명시적 형변환

    printf("%d %f %f \n", area, area1, area2);
    printf("%f %f %f \n", area, area1, area2);

    int ival;
    double dval;
    dval = 5 / 4;                  // 연산의 결과가 double 변수에 대입되면서 묵시적 변환
    printf("5/4 = %.2lf\n", dval); // double 자료형을 영구적으로 유지하지만, 저장되는 값 자체는 1.000000이 됩니다.  // C언어는 '정수와 정수의 연산 결과는 반드시 정수'
    dval = (double)5 / 4;          // 숫자를 명시적 변환
    printf("5/4 = %.2lf\n", dval); // 1.25
    ival = 5 / (double)4;
    printf("(double)5 / 4 = %d\n", ival); // 1
    ival = 1.5 + 1.6;
    printf("1.5 + 1.6 = %d\n", ival); // 3
    ival = (int)1.5 + (int)1.6;
    printf("(int)1.5 + (int)1.6 = %d\n", ival); // 2

    return 0;
}