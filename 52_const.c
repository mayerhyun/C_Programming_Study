#include <stdio.h>
void sub(int a, const int b)
{
    a += 5; // ( )
    b += 5; // ( )
    printf("a = %d b = % d\n", a, b);
}
int main()
{
    int i = 5, j = 10;
    sub(i, j);
    return 0;
}