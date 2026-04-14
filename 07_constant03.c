#include <stdio.h>
int main()
{
    char a = 'A', b = 'a', c = 'a' - 'A';

    printf("ASCII code %c is %d\n", a, a);
    printf(" 'a' + 1 = %c\n", 'a' + 1);
    printf("%d = '%c'\n", b - a, c);
    printf("'%c' = %d\n", 'b' - 32, 'b' - 32); // 대소문자 차이 32

    // char str[문자열길이 + 1] = "문자열";
    char fruit[7] = "banana";
    printf("%s\n", fruit);
    return 0;
}