#include <stdio.h>
int main()
{
    int ary[5] = {1, 2, 3, 4, 5};
    int *ptr;
    ptr = ary;

    printf("%d\n", *ptr++);
    printf("%d\n", (*ptr)++);
    printf("%d\n", *++ptr); // == > *(++ptr)
    printf("%d\n", ++*ptr); // == > ++(*ptr)
}