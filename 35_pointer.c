/* 포인터 변수 크기 확인 */
#include <stdio.h>
int main()
{
    char *cp, ch = 'a';
    int *ip, num = 5;
    double *dp, dnum = 3.14;
    cp = &ch;
    ip = &num;
    dp = &dnum;
    printf("cp : % d, *cp : % d Byte\n", sizeof(cp), sizeof(*cp)); // cp : 8, *cp : 1 Byte
    printf("ip : % d, *ip : % d Byte\n", sizeof(ip), sizeof(*ip)); // ip : 8, *ip : 4 Byte
    printf("dp : % d, *dp : % d Byte\n", sizeof(dp), sizeof(*dp)); // dp : 8, *dp : 8 Byte
    return 0;
}