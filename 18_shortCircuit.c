#include <stdio.h>
int function(int n)
{
    printf("%d", n);
    return n;
}
int main()
{
    int i = 0;
    int x;
    x = i++ + function(i++); // 함수 호출 전에 값이 두 번 수정됨. 정의되지 않은 행동
    printf("%d", x);
    return 0;
}