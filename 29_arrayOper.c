#include <stdio.h>
int main()
{
    // 배열과 증갑연산자 1
    int i = 0;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array[i++]; // array[i] 사용 후 i 증가
    array[++i]; // i를 증가시킨 후 array[i] 값을 사용
    --array[i]; // array[i] 값을 1감소 시킨 후 array[i] 를 사용.
    array[i]--; // array[i] 값을 사용 후 array[i] 를 감소 시킨다.
    for (int j = 0; j < 10; ++j)
        printf("%d ", array[j]);
    printf("\n");

    // 배열과 증감연산자 2

    int ary[5] = {1, 3, 5, 7, 9};
    int n, j = 1;

    n = ary[j++]; // n=3, i=2
    printf("n=%d, i=%d\n", n, j);

    n = ary[++j]; // n=7, i=3
    printf("n=%d, i=%d\n", n, j);

    n = --ary[j]; // n=6, i=3 // {1, 3, 5, 6, 9}
    printf("n=%d, i=%d\n", n, j);

    n = ary[j]--; // n=6 // {1, 3, 5, 5, 9}
    printf("n=%d, i=%d\n", n, j);

    for (int k = 0; k < 5; ++k)
    {
        printf("%d ", ary[k]);
    }
    printf("\n");

    return 0;
}