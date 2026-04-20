#include <stdio.h>
typedef struct
{
    char name[20];
    char phone[20];
    int salary;
} Employee;
void output(Employee *, int);
int main(void)
{
    Employee emp[4] = {{"이몽룡", "011", 9500}, {"변사또", "019", 8900}, {"정방자", "041", 4500}, {"최월매", "055", 9900}};
    Employee *ptr = emp;
    int count = sizeof emp / sizeof emp[0];
    printf("1개 출력=> 이름: %s, 전화번호: %s, 연봉: %d\n\n", ptr->name, ptr->phone, ptr->salary);
    output(emp, count);
}
void output(Employee *ptr, int count)
{
    for (int i = 0; i < count; ++i)
    {
        // (1) 배열표현
        // printf("이름: %s, 전화번호: %s, 연봉: %d\n", ptr[i].name , ptr[i].phone, ptr[i].salary);
        // (2) 포인터 연산 표현
        printf("이름: %s, 전화번호: %s, 연봉: %d\n",
               (ptr + i)
                   ->name,
               (ptr + i)->phone, (ptr + i)->salary);
    }
}