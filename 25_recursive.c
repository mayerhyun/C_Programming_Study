#include <stdio.h>
int fact(int);
int main()
{
    int num = 5;
    printf("5! = % ld \n", fact(num));
}
int fact(int x)
{
    return ((x == 1) ? 1 : x * fact(x - 1));
}