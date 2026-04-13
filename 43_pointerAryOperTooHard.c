#include <stdio.h>
int main()
{
    int ary[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};
    int *ptr;
    ptr = &ary;
    int i = 0, j = 1, k = 0;
    // 포인터 표현
    ary[i] == *(ary + i);
    ary[i][j] == *(*(ary + i) + j);
    ary[i][j][k] == *(*(*(ary + i) + j) + k);
    // 주소 표현
    ptr[i] == (ary + i);
    &ary[i][j] == (*(ary + i) + j);
    &ary[i][j][k] == (*(*(ary + i) + j) + k);
}