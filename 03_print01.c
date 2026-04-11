#include <stdio.h>
int main()
{
    int a = -2;
    printf("%u\n", a);

    int x = 12345;
    printf("1234567890\n");
    printf("=%d=\n", x);
    printf("=%8d=\n", x);
    printf("=%-8d=\n", x);
    printf("=%3d=\n", x);

    float y = 22.17;
    printf("1234567890123456\n");
    printf("=%f=\n", y);
    printf("=%10.4f=\n", y);
    printf("=%-10.4f=\n", y);
    printf("=%.2f=\n", y);

    return 0;
}