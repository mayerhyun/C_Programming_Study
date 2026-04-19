#include <stdio.h>

// **후위 증감 연산자 (예: pp++)**가 전위 증감 (예: ++pp) 및 **참조 연산자 (*)**보다 우선순위가 높습니다.

// 전위 증감 (++pp)과 참조 (*pp)가 같이 쓰이면 우선순위가 같으므로 오른쪽에서 왼쪽으로 차례대로 결합하여 실행됩니다.

// pp - p는 포인터 pp가 배열 p의 몇 번째 인덱스를 가리키는지 반환합니다.

// *pp - a는 pp가 가리키는 포인터가 배열 a의 몇 번째 인덱스를 가리키는지 반환합니다.
int a[] = {0, 1, 2, 3, 4};
int *p[] = {a, a + 1, a + 2, a + 3, a + 4};
int **pp = p;

int main()
{
    pp++;
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    *pp++; // pp++ 먼저 하고 포인터 연산            // 40번에서는 증가 안했는데 얘는 증가는 함 // 왜 why? pp의 주소값을 ++에 먼저 넘겨주기는 하나 연산 자체는 모든게 다 끝나고 이루어짐
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    *++pp; // *(++pp) 이거임
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    pp = p;
    **pp++;
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    *++*pp;
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    ++**pp;
    printf("%d %d %d\n", pp - p, *pp - a, **pp);

    return 0;
}