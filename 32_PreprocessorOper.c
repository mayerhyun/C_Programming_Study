#include <stdio.h>
// 데이터 타입에 따라 함수 이름을 생성하는 매크로
// print_##type 부분에 도달하면, 선행처리자는 ##을 기준으로 앞의 print_와 뒤의 int를 본드로 붙이듯 결합합니다.
// 그 결과 print_int라는 새로운 함수 이름이 만들어집니다.

#define PRINT_FUNC(type)           \
    void print_##type(type value)  \
    {                              \
        printf("값: %d\n", value); \
    }
// 실제 함수들을 자동으로 생성
PRINT_FUNC(int)  // void print_int(int value) { ... } 생성
PRINT_FUNC(char) // void print_char(char value) { ... } 생성
int main()
{
    print_int(100);  // 생성된 함수 호출
    print_char('a'); // 생성된 함수 호출
    return 0;
}