#include <stdio.h>
int main()
{
    int x = 10, y = 010, z = 0x10;
    printf("x의 값 : %3d %3o %3x \n", x, x, x); // 10진수 , 8진수, 16진수
    printf("y의 값 : %3d %3o %3x \n", y, y, y);
    printf("z의 값 : %3d %3o %3x \n", z, z, z);
    return 0;
}
