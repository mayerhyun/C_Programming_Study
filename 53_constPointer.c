int main()
{
    // 포인터의 대상이 const화 되는 경우
    const int *p;
    int abc = 7;
    p = &abc;  // p가 가리키는 방향(주소) 자체는 얼마든지 바꿀 수 있음
    *p -= 10;  // (    ) p가 가리키는 값은 못 바꿈....
    abc -= 10; // (    )

    // 포인터 변수가 const화 되는 경우
    int abc[3] = {10, 20, 30};
    int *const p1 = abc;
    printf("%d\n", *p1);
    printf("%d\n", ++*p1); // (    )

    printf("%d\n", *++p1); // (    )
}