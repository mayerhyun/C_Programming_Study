#include <stdio.h>
int main()
{
    short x = 32767; // short형의 최대값
    short y = x + 1; // short형의 최대값보다 1큰 값을 y에 저장
    printf("x = %hd\t y = %hd\n", x, y);
    // 참고로 음수중 가장 작은 수의 원본수가 2의 보수랑 똑같음

    short a = -32767;     // a = 1000 0000 0000 0001
    unsigned short b = a; // unsigned형 기억공간에 음수값을 저장하면?
    printf(" a = %hd \t b = %hu\n", a, b);
    printf(" a = %hu \t b = %hd\n", a, b);
    // %hd (부호 있는 16비트 정수): 1000 0000 0000 0001는 2의 보수 ==> -32767
    // %hu (부호 없는 16비트 정수): 1000 0000 0000 0001는 원본     ==> 32769

    short c;
    unsigned short d;
    long L1, L2;
    c = d = -1;
    // c = 1111 1111 1111 1111      2의보수임    10진수 : -1
    // d = 1111 1111 1111 1111      원본 2진수임 10진수 : 65535
    L1 = c * 3L;
    L2 = d * 3L;
    printf("L1 = % ld\n", L1);
    printf("L2 = % ld\n", L2);

    // 선언만하고 초기화 안하면 자료형의 범위안에서 아무값이나 들어가게 됨
    unsigned short e;
    printf("%d", e);

    return 0;
}