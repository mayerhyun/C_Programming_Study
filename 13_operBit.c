#include <stdio.h>
#define LED_PIN 3                   // 3번째 비트(0000 1000)만 켜고자 함.
void bitPrint(unsigned char *data); // 힘수가 main보다 아래있어서 여기 써있는거임...

int main()
{
    unsigned char register_A = 0x00; // 초기 상태 (00000000)
    printf("초기 상태: ");
    bitPrint(&register_A);

    // LED_PIN 비트만 1로 설정
    register_A |= (1 << LED_PIN); // register_A = register_A | (1 << 3)   | (Bitwise OR) 연산은 두 비트 중 하나라도 1이면 결과가 1

    // 결과: 00000000 | 00001000 = 0000 1000 (3번 비트만 ON)
    printf("Set 결과: ");
    bitPrint(&register_A);
    return 0;
}

void bitPrint(unsigned char *data)
{
    unsigned char temp = 0x80; // 16진수 80을 2진수로 바꾸면 1000 0000임 (참고로 char는 8비트임)
    for (int i = 0; i < (sizeof *data) * 8; ++i)
    {
        if (i % 4 == 0)
            printf(" ");
        if ((*data & temp) == 0)
            printf("0");
        else
            printf("1");
        temp = temp >> 1;
    }
    printf("\n");
}