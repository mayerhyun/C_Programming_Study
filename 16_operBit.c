#include <stdio.h>
#define LED_PIN 3 // 3번 버튼을 토글

void bitPrint(unsigned char *data);

int main()
{
    unsigned char register_A = 0x29; // 초기 상태 (0010 1001)
    printf("초기 상태: ");
    bitPrint(&register_A);

    // 3번 비트가 0->1, 1->0으로 바뀜
    register_A ^= (1 << LED_PIN); // 1 ^ 1 = 0 // 서로 다르면 1임
    printf("Toggle 결과:");
    bitPrint(&register_A);
    return 0;
}
void bitPrint(unsigned char *data)
{
    unsigned char temp = 0x80;
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