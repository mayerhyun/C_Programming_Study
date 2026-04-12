#include <stdio.h>
int main()
{
    int ary[5] = {10, 20, 30, 40, 50};
    int *ptr, i;
    ptr = &ary[2]; /* 포인터변수가 배열의 중간을 가리킴 */
    for (i = 0; i < 5; i++)
        printf("%6d", ary[i]);
    printf("\n");
    for (i = -2; i < 3; i++)
        printf("%6d", *(ptr + i));
    printf("\n\n");
    return 0;
}