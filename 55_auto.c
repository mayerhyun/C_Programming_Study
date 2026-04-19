#include <stdio.h>
void workover(int);
int reset(int);
int main()
{
    // return 값을 받아줄 변수가 있지 않으면 저장이 안됨 함수 속 a와 main의 a는 다른놈임.
    // 왜냐 call by value이기 떄문
    auto int a = 5;

    reset(a / 2);
    printf("%d\n", a);

    reset(a /= 2);
    printf("%d\n", a);

    a = reset(a / 2);
    printf("%d\n", a);

    workover(a);
    printf("%d\n", a);
}
void workover(int a)
{
    a = ((a * a) / (2 * a) + 4) * (a % a);
    printf("%d\n", a);
}
int reset(int a)
{
    a = (a < 2) ? 5 : 0;
    return (a);
}