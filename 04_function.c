#include <stdio.h> // 1) 전처리 지시문

void printNumber(int); // 2) 함수 선언부

int main(void) // 3) main 함수
{
    int num;
    num = 1;
    printNumber(num);
    num = 3;
    printNumber(num);
}

void printNumber(int n) // 4) 함수 정의부
{
    printf("정수값은 %d입니다.\n", n);
}