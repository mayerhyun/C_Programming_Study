#include <stdio.h>

// 1. 매크로 함수
#define SQUARE_MACRO(x) ((x) * (x))

// 2. 인라인 함수
//   복잡한 코드는 inline을 붙여봤자 컴파일러가 어차피 일반 함수로 바꿔버립니다.
// 따라서 로직이 길고 복잡해진다면 처음부터 맘 편하게 일반 함수로 선언해서 쓰는 것이
// 표준 가이드라인입니다.inline int square_inline(int x)
inline int square_inline(int x)
{
    return x * x;
}

int main()
{
    int a = 5;
    int b = 5;

    // [상황 1] inline 함수 호출: 정상 작동
    int res1 = square_inline(a++);
    // a가 먼저 평가되어 5가 함수로 넘어감. (5 * 5 = 25)
    // 계산이 끝난 후 a는 6이 됨.

    // [상황 2] 매크로 함수 호출: 치명적 논리 오류 발생
    int res2 = SQUARE_MACRO(b++);
    // 선행처리자가 텍스트를 그대로 복사해서 다음과 같이 만들어버림:
    // int res2 = ((b++) * (b++));
    // b가 두 번이나 증가해버리며, 컴파일러에 따라 25, 30, 36 등 쓰레기값을 산출함.

    printf("inline 결과: %d\n", res1); // 25
    printf("define 결과: %d\n", res2); // 예측 불가능한 쓰레기값
    return 0;
}