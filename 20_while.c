#include <stdio.h>
int main()
{
    int i;
    int sum = 0;
    for (i = 1; i <= 10; ++i) // i가 10보다 작거나 같을 동안 반복
        sum += i;
    printf("1~%d까지의 합 = %d\n", (i - 1), sum);
    return 0;
}