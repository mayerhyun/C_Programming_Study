#include <stdio.h>
typedef int (*Func)(int, int);
int plus(int, int);
int minus(int, int);
int proxy(int, int, Func);
int main()
{
    int x = 10, y = 25;
    Func f = plus;
    printf("덧셈 : %d\n", proxy(x, y, f));
    f = minus;
    printf("뺄셈 : %d\n", proxy(x, y, f));
    return 0;
}
int plus(int x, int y)
{
    return x + y;
}
int minus(int x, int y)
{
    return x - y;
}
int proxy(int x, int y, Func f)
{
    return f(x, y);
}