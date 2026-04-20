#include <stdio.h>
#include <string.h> // strcpy를 사용하기 위해.
typedef struct
{
    char name[20];
    char phone[25];
} Friend;
void output(Friend *);
int main(void)
{
    Friend f1 = {"손오공", "111-2323"};
    Friend *p1;
    p1 = &f1;
    output(p1);
    Friend f2 = {"저팔계", "222-2323"};
    Friend *p2 = &f2;
    // 구조체 변수를 통해 수정
    strcpy(f2.name, "삼장법사");
    // strcpy는 문자열(char *)을 복사하는 함수이므로, 정수형 데이터를 다루는 해당 구조체 멤버에는 애초에 사용할 수 없습니다.
    //  포인터 변수를 통해 수정
    strcpy(p2->phone, "010-1212-4545");
    output(p2);
}
void output(Friend *f)
{
    printf("이름: %s, 전화번호: %s\n", f->name, f->phone);
}