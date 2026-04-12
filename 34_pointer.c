#include <stdio.h>
int main()
{
    int *ptr, num = 50;
    ptr = &num;
    *ptr = *ptr + 4;
    printf("num = % d\t *ptr = % d \n", num, *ptr);
    return 0;
}