#include <stdio.h>
int main(void)
{
    int arr[3] = {20, 30, 40};
    int *ptr;
    ptr = arr; // arr의 주소(즉 &arr[0] = arr)를 ptr에 대입. 배열명이 포인터와 비슷하므로 포인터도 배열명처럼 동작할 수 있다.
    printf("arr[0]의 값: %d\n", arr[0]);
    printf("*ptr의 값: %d\n", *ptr);
    printf("ptr[0]의 값: %d\n", ptr[0]); // 포인터 변수인 ptr을 배열처럼 표현
    printf("*arr의 값: %d\n", *arr);     // 배열명인 arr을 포인터처럼 표현 : 20
    printf("arr의 값: %d\n", arr);       // arr의 주소
    printf("ptr의 값: %d\n", ptr);       // arr의 주소
    return 0;
}