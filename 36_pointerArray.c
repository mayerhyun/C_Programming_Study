#include <stdio.h>
int main()
{
    int ary[5] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; ++i)
        printf("ary[%d] => %d ", i, ary[i]);
    printf("\nary = %p, &ary[0] = %p\n", ary, &ary[0]);
    printf("sizeof ary = %d, sizeof ary[0] = %d\n", sizeof ary, sizeof ary[0]);
    printf("sizeof &ary = %d", sizeof &ary);
    return 0;
}