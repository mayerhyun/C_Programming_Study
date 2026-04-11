// 8비트의 앞 4비트는 습도, 뒤 4비트는 온도라고 할 때 각각 분리하시오.
#include <stdio.h>
void bitPrint(unsigned char *data);
int main()
{
    unsigned char raw_data = 0xA3; // 1010 0011 (2진수)
    printf("초기 상태: ");
    bitPrint(&raw_data);

    // 1. 뒤의 4비트(습도) 추출 (Masking)
    unsigned char humidity = raw_data & 0x0F;
    printf("** 습도: ");
    bitPrint(&humidity);

    // 2. 앞의 4비트(온도)추출 (Shifting): 1010 0011 >> 4 = 0000 1010 (10)
    // unsigned char temperature = raw_data >> 4;
    unsigned char temperature = raw_data & 0xF0;
    printf("** 온도: ");
    bitPrint(&temperature);

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