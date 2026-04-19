#include <stdio.h>
int reset();
int next(int);
int last(int);
int now(int);
int i = 1; // data에 저장되는 전역변수임
int main()
{
    auto int i, j; // 지역변수임 스택에 쌓임
    i = reset();
    for (j = 0; j < 3; j++)
    {
        printf("** i = % d \t j = % d \n", i, j);
        printf("next(i) = % d\n", next(i));
        printf("last(i) = % d\n", last(i));
        printf("now(i + j) = % d\n", now(i + j));
    }
}
int reset() { return (i); } // 함수 안에서 쓰는 i는 전역변수 i임
int next(int j) { return (j = i++); }
int last(int j)
{
    static int i = 10;
    return (j = i--);
}
int now(int i)
{
    auto int j = 10;
    return (i = j += i);
}