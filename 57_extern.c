#include <stdio.h>
void sum();
int temp; // 전역 변수
int main()
{
    auto int a = 10;
    sum();
    printf("temp = % d \n", temp);
    printf("a = % d \n", a);
}
void sum()
{
    temp += 100;
}