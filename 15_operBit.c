#include <stdio.h>
#define BUTTON_PIN 2 // 2번째 비트(0000 0100)가 눌렸는지 상태 확인

void bitPrint(unsigned char *data);

int main()
{
    unsigned char register_A = 0x2C; // 초기 상태 (0010 1001)  (0010 1100)
    printf("초기 상태: ");
    bitPrint(&register_A);

    printf("Bit 상태 확인:");

    if (register_A & (1 << BUTTON_PIN))
    {
        printf("%d번 버튼 눌림\n", BUTTON_PIN);
    }
    else
    {
        printf("%d번 버튼 안눌림\n", BUTTON_PIN);
    }
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