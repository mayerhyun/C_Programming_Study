#include <stdio.h>
int main()
{
    // 즉 const로 선언된 변수는 Read만 가능하고 Write는 할 수 없는 상태가 되므로
    // • 반드시 변수를 선언하면서 초기화해야 한다.
    const int a = 10;
    int b;
    printf("% d\n", a);     // ( )
    printf("% d\n", a + 1); // ( )
    printf("% d\n", a++);   // ( 오류 )
    b = a;                  // ( )
    a = 20;                 // ( 오류 )
    return 0;
}