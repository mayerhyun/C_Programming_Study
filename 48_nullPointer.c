#include <stdio.h>
#include <stdlib.h> // malloc() 함수를 위해 include
int main()
{
    void *ptr = malloc(sizeof(int)); // malloc : 운영체제에게 빈칸을 찾아줘 라고 요구하는것임
    // 운영체제가 빈칸을 찾고 유요한 주소를 넘겨줌
    // 사용자는 3000번 칸에 *ptr을 넣음
    // malloc()의 매개변수는 무조건 '할당받을 총 바이트(Byte) 크기 = 숫자만 들어감
    // *ptr의 값은 쓰레기값임 (RAM에는 이전에 실행되었던 다른 프로그램이 사용하고 버린 데이터의 잔해들이 그대로 남아있는거임)
    // 성공적으로 빈칸을 찾아서 넣어주게 되면 "메모리 생성 성공"이 출력됨
    if (ptr == NULL)
    {
        printf("메모리 생성 실패");
        exit(0);
    }
    else
    {
        printf("메모리 생성 성공");
    }
    return 0;
}