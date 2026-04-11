#include <stdio.h>
int main()
{
    int ary[5];
    double dary[10];

    int iary[] = {1, 2, 3, 4, 5};
    printf("배열의 용량: %d\n", sizeof iary);
    printf("배열의 개수: %d\n", (sizeof iary / sizeof iary[0]));

    // 요소의 값 출력
    int cnt = (sizeof dary / sizeof dary[0]);
    for (int i = 0; i < cnt; ++i)
        printf("%d번 방: %lf\n", i, dary[i]);

    printf("\n");
    cnt = sizeof iary / sizeof iary[0];
    for (int i = 0; i < cnt; ++i)
        printf("%d번 방: %d\n", i, iary[i]);
}
