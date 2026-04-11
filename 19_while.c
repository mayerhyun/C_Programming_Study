#include <stdio.h>
int main()
{
    int i = 1;
    int sum = 0;
    while (i <= 10)
    { // i가 10보다 작거나 같을 동안 반복
        sum += i;
        i++; // i를 1씩 증가 (무한 루프 방지)
    }
    printf("1~%d까지의 합 = %d\n", i, sum);
    return 0;
}
