#include <stdio.h>
typedef char *String;        // 포인터 변수를 typedef
typedef char StringAry[100]; // 1차원 문자배열을 typedef
int main()
{
    String name = "박보검";
    char *phone = "010-1234-5678";
    StringAry addr = "서울 강남구 역삼동 개나리 아파트 5-104호";
    printf("이름: %s\n", name);
    printf("주소: %s\n", addr);
    printf("전화번호: %s\n", phone);
    return 0;
}