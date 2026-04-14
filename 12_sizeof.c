#include <stdio.h>
int main()
{
    int a, b[10];
    double c[3];
    printf("'A' size : %d\n ", sizeof('A'));       // (4바이트): 작은따옴표로 둘러싸인 문자 리터럴은 char형이 아니라 int형으로 취급
    printf("\"A\" size : %d\n ", sizeof("A"));     // (2바이트): 큰 따옴표로 둘러싸인 문자 리터럴은 끝에 항상 \0이 포함되어서 'A' + \0 총 2바이트임
    printf("\"AB\" size : %d\n ", sizeof("AB"));   // (3바이트):'A', 'B', '\0' 총 3문자이므로 3바이트
    printf("5 size : %d\n ", sizeof(5));           // (4바이트): int는 4
    printf("5.0 size : %d\n ", sizeof(5.0));       // (8바이트): 소수점이 있는 실수는 double 8
    printf("5.0f size : %d\n ", sizeof(5.0f));     // (4바이트): f를 붙이면 강제 float형 취급
    printf("char size : %d\n ", sizeof(char));     // (1바이트): 문자형 데이터의 기본 크기
    printf("int size : %d\n ", sizeof(int));       // (4바이트): 정수형 데이터의 기본 크기입니다.
    printf("float size : %d\n ", sizeof(float));   // (4바이트): 단정밀도 부동소수점 데이터의 크기입니다.
    printf("double size : %d\n ", sizeof(double)); // (8바이트): 배정밀도 부동소수점 데이터의 크기입니다.
    printf("a size : %d\n ", sizeof(a));           // (4바이트): a는 int형 변수이므로 4바이트입니다.
    printf("b size : %d\n ", sizeof(b));           // (40바이트):
    printf("c size : %d\n ", sizeof(c));           // (24바이트): double 요소 3개를 가진 배열이므로 8 * 3 = 24바이트입니다.
    return 0;
}