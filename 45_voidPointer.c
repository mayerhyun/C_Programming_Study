#include <stdio.h>

// • void 포인터는 포인트 변수가 참조하고 있는 target의 데이터 타입을 알 수 없는 포인터를 말한다.
// • 다시 말하면 void 포인터는 가리키는 대상체의 type에 제한이 없는 포인터라 할 수 있다.
// • 메모리를 동적으로 할당하는 malloc() 함수의 반환 타입이 void *타입이다.
// • void 포인터가 포인팅 하는 데이터의 값을 가져와 사용하려면 형변환이 필요하다.

int main()
{
    int a = 10;
    char b = 'x';
    void *ptr = &a;
    // void Pointer로부터 값을 가져오려면 적절하게 형변환을 해야 한다.
    printf("Void Pointer가 가리키는 값: %d\n", *((int *)(ptr)));
    ptr = &b;
    printf("Void Pointer가 가리키는 값: %c\n", *((char *)(ptr)));
}