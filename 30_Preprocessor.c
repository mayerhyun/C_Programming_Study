#include <stdio.h>
// 매크로 상수
#define PI 3.141592
// 매크로 상수(식)
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
// 매크로 함수
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
#define SQUARE(x) ((x) * (x))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// 만약 typedef를 쓰지 않고 순수하게 구조체만 선언했다면, main 함수 안에서 변수를 만들 때 매번 귀찮게 struct 키워드를 붙여야 합니다.
// 미사용 시 선언 방식 : struct point p1 = {10, 20};
// typedef 적용 후 선언 방식 : POINT p1 = {10, 20};
typedef struct point
{
    int x, y;
} POINT;
// 자바 개발자에게 구조체를 설명할 때 가장 많이 쓰는 비유가 바로 "메서드(Method)가 싹 다 빠진 순수한 DTO" 입니다.

int main()
{
    POINT p1 = {10, 20};
    POINT p2 = {-7, 2};
    int data[] = {1, 2, 3, 4, 5};
    printf("ABS(%d) = %d\n", p2.x, ABS(p2.x));
    printf("MAX(%d, %d) = %d\n", p1.x, p2.x, MAX(p1.x, p2.x));
    printf("MIN(%d, %d) = %d\n", p1.y, p2.y, MIN(p1.y, p2.y));
    // 배열의 데이터 출력
    for (int i = 0; i < ARR_SIZE(data); ++i)
        printf("%d ", data[i]);
    printf("\n");
    return 0;
}