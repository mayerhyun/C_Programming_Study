#include <stdio.h>

int main()
{
    char place = 0;
    printf("s 입력 시 '서울'로 이동합니다.\n");
    printf("j 입력 시 '제주'로 이동합니다.\n");
    printf("가고 싶은 곳의 문자를 입력하세요: ");
    scanf("%c", &place);

    if (place == 's')
    {
        goto LABEL_SEOUL;
    }
    else if (place == 'j')
    {
        goto LABEL_JEJU;
    }
    else
    {
        printf("잘못된 입력입니다.\n");
        goto END;
    }

LABEL_SEOUL:
    printf(">>> 서울에 도착했습니다. <<<\n");
    goto END;
LABEL_JEJU:
    printf(">>> 제주도에 도착했습니다. <<<\n");
END:
    printf("여행이 끝났습니다.\n");
    return 0;
}