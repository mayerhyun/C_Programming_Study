#include <stdio.h>
void exchange(int *, int *);
int main()
{
    printf("<<<<< call by reference >>>>>\n");
    int x = 5, y = 10;
    printf("** main 함수: \t\tx = %d \t y = %d\n", x, y);
    exchange(&x, &y);
    printf("** main 함수: \t\tx = %d \t y = %d\n", x, y);
}
void exchange(int *a, int *b)
{
    int temp;
    printf("** exchange함수:\ta = %d \t b = %d\n", *a, *b);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("** exchange함수:\ta = %d \t b = %d\n", *a, *b);
}