#include <stdio.h>

int main()
{
    void *arr[3];
    int a = 100;
    float b = 20.5;
    char *c = "Hello";

    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("Integer: %d\n", *((int *)arr[0]));
    printf("Float: %f\n", *((float *)arr[1]));
    printf("String: %s\n", *((char **)arr[2]));
    printf("H : %c\n", **((char **)arr[2]));
    printf("e : %c\n", *(*((char **)arr[2]) + 1));
    printf("e : %c", (*((char **)arr[2]))[1]);
    // 변수 c 자체가 이미 '포인터'임.
    // 포인터 변수의 주소를 저장했으므로, 이를 꺼낼 때는 당연히 '이중 포인터' 렌즈가 필요.
    // 변수 c는 메모리 0x2000번지에 위치하며, 그 안에는 "Hello"의 시작 주소인 **0x3000**이 들어있음
    return 0;
}

// H만 출력하고 싶다면?
// 물리적 메모리 구조상 'H' 1글자만 추출하기 위한 정확한 문법은 **((char **)arr[2])이며, 서식 지정자는 % c를 사용해야 합니다.