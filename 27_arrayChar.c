#include <stdio.h>
int main()
{
    char fruit[10] = {'a', 'p', 'p', 'l', 'e'};

    for (int i = 0; i < 5; ++i)
        printf("%c", fruit[i]);
    printf("\n");

    // 문자열을 배열에 저장하려면 끝은 반드시 널(NULL, \0)로 끝나야 한다.
    // 즉, 문자데이터의 크기보다 배열요소의 크기가 +1 많아야 한다.

    char fruit_1[] = {'a', 'p', 'p', 'l', 'e', '\0'};
    char fruit_2[] = "banana";
    char fruit_3[6] = "orange";                        // (X)
    char fruit_4[5] = "pear";                          // (0)
    printf("banana의 저장용량: %d\n", sizeof fruit_2); // char는 1바이트라서 sizeof fruit_2 / sizeof fruit_2[0] 할 필요 X
    printf("%s\n", fruit_1);
    printf("%s\n", fruit_2);
    printf("%s\n", fruit_3); // 출력결과는?
    printf("%s\n", fruit_4);
    char name[] = "홍길동";
    printf("이름: %s, 저장용량: %d\n", name, sizeof name);

    // 문자열의 입력
    char name2[50];
    char name3[50];
    printf("이름을 입력하시오 : ");
    // "Jennifer", "James Dean" ==> 두 종류의 데이터를 각각 입력하고 출력의 결과를 확인

    scanf("%s", name2); // James \n (엔터가 버퍼에 남게되어서 fgets에 들어가게 됨)
    // scanf 에서 James Dean을 입력하면 James \n Dean \n 인건데 \n Dean \n가 들어가게 됨
    // scanf("%s")가 "James Dean"을 입력받을 때 "James"만 읽고 멈췄던 이유는,
    // 입력 버퍼(메모리)를 한 글자씩 읽어가다가 바로 이 공백 문자(데이터 번호 32번, ' ')를 마주치는 순간
    // "아, 여기서 하나의 단어가 끝났구나"라고 판단

    fgets(name3, sizeof name3, stdin); // fgets가 먼저 실행되면, 입력 버퍼가 깔끔하게 비어짐
    // fgets(저장할_배열, 최대_크기, 데이터_출처);  stdin = 키보드로부터 데이터가 입력받아졌다는 의미
    printf("반갑습니다. %s님!\n", name2);
    printf("반갑습니다. %s님!\n", name3);

    // 1. scanf("%s"): "공백은 단어의 끝(구분자)이다"
    // 2. fgets: "공백은 일반 알파벳과 똑같은 문자다"
}