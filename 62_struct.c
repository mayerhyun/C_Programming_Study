#include <stdio.h>
typedef struct Student
{
    int id;
    char *name;
    double score;
} ClassA;
void output(ClassA s);
int main(void)
{
    // 변수 선언
    struct Student son;
    // 초기화
    son.id = 10;
    son.name = "손오공";
    son.score = 78.45;
    printf("학번: %3d, 이름: %s, 점수: %.2lf\n", son.id, son.name, son.score);

    struct Student kim = {20, "김개발", 85.4};
    // . 연산자를 이용해서 초기화하면 누락된 멤버, 순서 괜찮음.
    struct Student lee = {.name = "이코딩", .score = 88.7};
    output(kim);
    output(lee);

    // struct Student 타입을 한 단어 Student 타입으로 별칭지정
    // 별칭이 2개가 되어버림 대신 Student는 main 메서드에서만 사용 가능
    typedef struct Student Student;
    Student park = {40, "박하드", 90.1};
    Student choi = {.name = "최근무", .id = 50, .score = 95.5};
    output(park);
    output(choi);
    ClassA song = {60, "송학생", 90.1};
    output(song);
}
void output(ClassA s)
{
    printf("학번: %3d, 이름: %s, 점수: %.2lf\n", s.id, s.name, s.score);
}