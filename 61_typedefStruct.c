// typedef 전 구조체 선언
struct Point
{
    int x;
    int y;
};
// 구조체 변수 선언
// (변수를 선언할 때마다 매번 struct를 써야 함)
struct Point p1;
// typedef 후 구조체 선언
typedef struct
{
    int x;
    int y;
} Point;
// 구조체 변수 선언
// (바로 Point로 선언 가능)
Point p1;