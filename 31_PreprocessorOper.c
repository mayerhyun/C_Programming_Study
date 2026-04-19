#include <stdio.h>

// 선행처리자의 단일행 규칙: C언어에서 #으로 시작하는 모든 선행처리 명령어(#define, #include 등)는
// 반드시 한 줄(Single Line) 안에 모두 작성되어야 함.
// 그래서 \ 이거 쓰면 줄 바꿀 수 있음

// 매크로 함수 내부에서 매개변수 앞에 #을 붙이는 것을 **문자열화 연산자(Stringizing Operator)**라고 함
// 이는 전달받은 변수의 '이름(텍스트)' 자체에 강제로 큰따옴표("")를 씌워버리는 기능입니다.
#define PRINT_POINT(pt)                   \
    {                                     \
        printf(#pt "=");                  \
        printf("(%d, %d)\n", pt.x, pt.y); \
    }
// 중괄호 {}의 역할: 다중 문장 블록화 (Statement Block)
typedef struct point
{
    int x, y;
} POINT;

int main()
{
    POINT p1 = {10, 20};
    POINT p2 = {-7, 2};
    /* 전달인자로 p1을 전달하면
    매크로함수의 매개변수명 pt가 #pt에 의해
    "p1"이라는 문자열로 확장된다. */
    PRINT_POINT(p1);
    PRINT_POINT(p2);
    return 0;
}