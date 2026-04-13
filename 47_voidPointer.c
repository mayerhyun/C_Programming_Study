#include <stdio.h>

// *ptr을 해서 "물건 가져와!"라고 명령하면,
// 컴퓨터는 "몇 바이트 크기로 집어와야 합니까?"라고 되물으며 에러(컴파일 오류)를 냅니다.
int main(void)
{
    void *p;
    int intArray[5] = {1, 2, 3, 4, 5};
    double doubleArray[2][3] = {{1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}};
    char *charArray[4] = {"apple", "pear", "banana", "pineapple"};

    p = intArray; // void형 포인터 p는 int형 1차원 배열을 가리킬 수 있고
    printf("%d\n", *((int *)p + 2));

    p = doubleArray; // double형 2차원 배열을 가리킬 수도 있으며
    printf("%lf\n", *(*((double (*)[3])p + 1) + 2));
    // int(p *)[3] 얘랑 똑같은 개념임

    p = charArray;                     // char * 배열을 가리킬 수도 있다
    printf("%s\n", *((char **)p + 2)); // 이거는 *(*((char **)p + 0) + 2)) 이 경우에 p를 출력함
}