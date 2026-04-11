#include <stdio.h>
#define LED_PIN 2 // 2번째 비트(0000 0100)만 끄고자 함.

void bitPrint(unsigned char *data);

int main()
{
    unsigned char register_A = 0x0F; // 초기 상태 (0000 1111)
    printf("초기 상태: ");
    bitPrint(&register_A);

    // LED_PIN 비트만 0로 설정
    register_A &= ~(1 << LED_PIN); // 0000 1111 & 1111 1011 -> 0000 1011

    // 결과: 00000000 & 00000100 = 0000 0010 (2번 비트만 OFF)
    printf("Clear 결과:");
    bitPrint(&register_A);

    return 0;
}
void bitPrint(unsigned char *data)
{
    unsigned char temp = 0x80;   // 1000 0000
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