#include <stdio.h>
void func(int a)
{
    printf("func 함수 ==> a변수 값: %d, a변수의 주소: %p\n", a, &a);
}
int main()
{
    int a = 10;
    printf("main 함수 ==> a변수 값: %d, a변수의 주소: %p\n", a, &a);
    func(a);
}