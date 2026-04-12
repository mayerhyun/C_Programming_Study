#include <stdio.h>
int main()
{
    int ary[5] = {10, 20, 30, 40, 50};
    int *ptr, i;
    ptr = ary;

    // 1) 배열을 배열로 표현
    for (i = 0; i < 5; i++)
        printf("%6d", ary[i]);
    printf("\n");

    // 2) 포인터변수를 배열로 표현
    for (i = 0; i < 5; i++)
        printf("%6d", ptr[i]);
    printf("\n");

    // 3) 포인터 연산
    for (i = 0; i < 5; i++)
        printf("%6d", *(ptr + i));
    printf("\n");

    // 4) 배열명 연산
    for (i = 0; i < 5; i++)
        printf("%6d", *(ary + i));
    printf("\n");

    return 0;
}