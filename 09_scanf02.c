#include <stdio.h>
int main()
{
    int age;
    double height;

    printf("나이와 키를 입력 하시오: ");
    scanf("%d %lf", &age, &height);

    printf("입력한 나이는 %d, 키는 %.2lf입니다.\n", age, height);

    char name[70];
    printf("이름이 무엇인가요? ");

    // 주의: name 변수 앞에는 &기호가 없다. 배열의 이름은 그 배열의 주소 값과 동일
    scanf("%s", name);
    printf("반갑습니다. %s씨!\n", name);

    int i = 0;
    int a = i++ + i++; // 오류는 아닌데 권장하지 않음
    printf("%d\n", a);
    i = ++i; // 오류 (연산안됨)
    printf("%d\n", i);
    return 0;
}