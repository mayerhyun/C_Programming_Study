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

typedef struct point
{
    int x, y;
} POINT;

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