#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    // 1. 문자열을 저장할 충분한 크기의 배열 선언
    char s[100];
    int a;
    double p;
    fp = fopen("./score.txt", "r");
    // 파일 열기 성공 여부 확인
    if (fp == NULL)
    {
        puts("File not found!");
        return 1; // 비정상 종료 시 1을 리턴.
    }
    // 2. 모든 내용을 읽을 때까지 반복처리
    while (fscanf(fp, "%d %lf %s", &a, &p, s) != EOF)
    {
        printf("이름: %s 나이: %d 학점: %.2lf\n", s, a, p);
    }
    fclose(fp);
    return 0;
}