#include <stdio.h>
#include <string.h> // strcpy를 사용하기 위해.
typedef struct
{
    char name[20];
    char phone[25];
} Friend;
void output(Friend);
int main(void)
{
    // 구조체 변수 선언과 초기화 동시 처리
    Friend f1 = {"성춘향", "0102323-4545"};
    output(f1);
    // 구조체 변수 선언과 초기화 나눠 처리
    Friend f2;
    strcpy(f2.name, "이몽룡");
    strcpy(f2.phone, "010-1234-2567");
    output(f2);
}
void output(Friend s)
{
    printf("이름: %s, 전화번호: %s\n", s.name, s.phone);
}