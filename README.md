# C言語の勉強メモ
---
# 1. C 언어 개요

- 어느 정도 하드웨어에 종속
    → 완벽하게 플랫폼에 독립적이지 않다.

**장점**
- 하드웨어를 제어하는 시스템 프로그래밍 가능
- 이식성 갖춘 프로그램 → 장비가 바뀌어도 큰 수정 필요 X
- 기능 별로 나누어 개발 가능 → 함수를 사용해 기능 별 개발 → 유지 보수와 코드의 재활용성 높음
- 실행 속도가 빠르다 (인터프리터 언어 대비)
- 운영체제, 임베디드 시스템, 드라이버 개발에 적합

**단점**
- 메모리 관리를 개발자가 직접 해야 한다 (free 등)
- 포인터 등 난이도가 높은 개념 존재
- 객체지향 프로그래밍을 직접 지원하지 않음

---

### C 언어 구성요소

1. **상수**
    - 실행에 필요
    - 상수공간(RO : Read Only)에 기억
2. **변수**
    - 프로그램 작성 시 연산 결과 등을 저장하기 위해 할당된 메모리 공간
    - Stack, Heap 등에 생성
    - 네이밍 룰 맞추기
3. **연산자**
4. **명령어 (실행문)**
    - OS에서 주로 사용
5. **함수**
    - 단위 코드, 입력되는 데이터 가공해 출력
    - 구분
        1. **System Library 함수** - 벤더 측에서 미리 제공 (gcc compiler 등)
        2. **User Define 함수 (사용자 정의 함수)**
            - 프로그래머가 규칙에 따라 직접 생성
            - 선언(Prototype) : 함수의 존재를 컴파일러에게 미리 알림
            - 정의부(Definition) : 실제 함수의 동작(몸체)을 작성
            - 호출(Call) : 함수를 실행하는 곳

    ```c
    리턴타입 함수명(매개변수 선언) {
        statement;
        [return 값;]
    }
    ```

> **💡 선언부 vs 정의부 차이**
> ```c
> // 선언부 (Prototype) - 컴파일러에게 "이런 함수가 존재한다"고 알림
> int add(int a, int b);
>
> int main() {
>     int result = add(3, 5); // 호출
>     return 0;
> }
>
> // 정의부 - 실제 동작 구현
> int add(int a, int b) {
>     return a + b;
> }
> ```

---

### C 프로그래밍 개발 순서

1. **Source Code (*.c)** !! 절대 삭제하면 안 된다~
    → Preprocess (전 처리기) : `#include`, `#define` 등을 처리
2. **Temp File (*.c')** ; 전처리기에 의해 변형된 내용을 기계어로 번역
    → Compile
3. **Object File (*.obj)** ; 프로그래머의 기계어 코드 실행 시 필요한 코드 삽입
    → Link (여러 .obj 파일과 라이브러리를 하나로 합침)
4. **Execute File (*.exe)** ; 실행 가능한 기계어

---

- 하지만 현재는 Source Code를 한번에 Execute File로 변환해줌 (중간과정은 내부적으로 변환)

⇒ 사용하는 컴파일러에 따라 소스코드도 달라질 수 있다.

> **Java와의 비교**
> - .java → 컴파일 → .class (바이트코드, 완전한 기계어는 아님) → JVM이 빌드 → .jar
> - OS 독립적 / JVM이 jar파일을 해당 OS에 맞게 변환 / 그래서 C보다 실행속도가 느림

---

### 주석 (comment)

```c
// 한 줄 주석

/*
여러 줄 주석
*/
```

> **💡 주석 활용 팁**
> - 코드의 '무엇'이 아닌 '왜'를 설명하는 것이 좋은 주석이다.
> - 주석 처리로 코드를 임시 비활성화할 수 있다.

---

### C언어의 Expression과 Statement

- **표현식 (Expression)**
    - 값으로 평가될 수 있는 코드 조각
    - 리터럴, 변수, 연산식
    - 최종적으로 하나의 값을 산출
    - 예: `3 + 5`, `a * b`, `x > 0`

- **실행문 (=문장, 명령문) (Statement)**
    - 실행 가능한 문장
    - 제어문 블록을 제외하면 대부분 세미콜론(`;`)으로 종료
    - 예: `int a = 10;`, `printf("hello");`, `if (...) { ... }`

---

### C프로그램의 구조

```c
// 1) 전처리 지시문
// 컴파일 이전에 텍스트 치환/파일 포함 등을 처리
#include <stdio.h>   // 표준 입출력 헤더
#include <stdlib.h>  // 동적 메모리, 형변환 등
#define PI 3.14159   // 매크로 상수 정의 (세미콜론 X)

// 2) 함수 선언부 (Prototype)
// 함수의 프로토타입을 미리 선언
void printNumber(int);

// 3) main함수
int main(void)
{
    int num;
    num = 1;
    return 0;  // 정상 종료 시 0 반환 (OS에 반환)
}

// 4) 함수 정의부
// 때에 따라 선언부, 정의부가 합쳐지기도 한다.
void printNumber(int n) {
    printf("%d\n", n);
}
```

---

### main() 함수

- 프로그램을 구성하는 함수들 중 가장 중요한 함수
- 프로그램이 시작되고 종료되는 위치
- 운영체제가 프로그램을 실행할 때 가장 먼저 호출하는 함수
- **반환값(return value)**: `int`형으로, `return 0`은 정상 종료를 OS에 알린다.

```c
// 인자 없는 형태
int main(void) {
    return 0;
}

// 커맨드라인 인자를 받는 형태
int main(int argc, char *argv[]) {
    // argc : 인자의 개수
    // argv : 인자 문자열 배열 (argv[0]은 프로그램 이름)
    return 0;
}
```

---

### 자료형이란?

- **자료형**
    - C언어에서 다루는 데이터의 종류
    - **기본자료형**
        - 산술형
            - 정수형
                - 문자형 (`char` (1))
                - 수치형 (`short int` (2), `int` (4), `long` (4~8), `long long` (8))
            - 실수형 (`float` (4), `double` (8), `long double` (16))
        - 무치형 (`void` - 값이 없음. 반환 타입이나 포인터에 사용)
    - **유도자료형 (= 파생)** ; 기본자료형을 이용해 만들어진 자료형
        - 배열
        - 함수
        - 포인터 - 변수의 메모리 주소를 저장
        - 구조체, 공용체 - 확장형
        - 열거형 - 정수형 상수에 기호를 붙여 사용

- **중요성**
    - **메모리 관리**: 자료형에 따라 할당되는 메모리 크기가 다름
    - **데이터 해석**: 동일한 비트열이라도 자료형에 따라 다르게 해석
        - `int a;` → 4바이트 할당, 정수로 해석
        - `float b;` → 4바이트 할당, 부동소수점으로 해석 (같은 크기지만 다른 의미!)
    - **오류 방지**: 잘못된 타입 사용 시 컴파일러가 경고/오류 발생

- **참고**
    - C99 표준부터 `<stdint.h>` 에서 크기가 명확한 타입 제공 (`int32_t`, `uint8_t` 등)
    - 자료형의 별칭 : `typedef`
        - `typedef signed long long int llong;` 처럼 별칭을 만들어 사용

---

### 자료형의 종류 및 범위

- `unsigned`는 부호가 없는 것 → 최대값이 커진다!

| **구분** | **자료형** | **메모리 크기 (byte)** | **값의 범위** | **출력 변환 문자** |
|---|---|---|---|---|
| **문자형** | `char` | 1 | -128 ~ 127 | `%c` 또는 `%d` |
|  | `unsigned char` | 1 | 0 ~ 255 | `%u` |
| **정수형** | `short` | 2 | -32,768 ~ 32,767 | `%d` |
|  | `unsigned short` | 2 | 0 ~ 65,535 | `%u` |
|  | `int` | 4 | -2,147,483,648 ~ 2,147,483,647 | `%d` |
|  | `unsigned int` | 4 | 0 ~ 4,294,967,295 | `%u` |
|  | `long` | 4 (Windows 기준) | -2,147,483,648 ~ 2,147,483,647 | `%ld` |
|  | `unsigned long` | 4 | 0 ~ 4,294,967,295 | `%lu` |
|  | `long long` | 8 | $-2^{63}$ ~ $2^{63} - 1$ | `%lld` |
|  | `unsigned long long` | 8 | 0 ~ $2^{64} - 1$ | `%llu` |
| **실수형** | `float` | 4 | 약 ±3.4 × 10⁻³⁸ ~ ±3.4 × 10³⁸ | `%f` |
|  | `double` | 8 | 약 ±1.7 × 10⁻³⁰⁸ ~ ±1.7 × 10³⁰⁸ | `%lf` |
|  | `long double` | 16 (GCC 기준) | 더 넓은 범위 | `%Lf` |

> **⚠️ 주의**: `long`의 크기는 플랫폼마다 다르다. Windows 64bit에서는 4byte, Linux 64bit에서는 8byte. 크기를 확실히 하려면 `long long` 또는 `<stdint.h>`의 `int64_t` 사용 권장.

---

### signed vs unsigned

- **signed (부호 있음)** : 음수, 0, 양수 표현. 최상위 비트(MSB)가 부호 비트.
- **unsigned (부호 없음)** : 0과 양수만 표현. 동일한 메모리에서 최대값이 약 2배.

**주요 차이점 및 활용**

| 구분 | signed | unsigned |
|---|---|---|
| 표현 범위 | 음수~양수 | 0~양수 |
| 사용 예 | 일반 정수 계산 | 카운터, 비트 플래그, 크기(size) |
| 비트 연산 | MSB가 부호이므로 주의 | 예측 가능한 비트 연산 |

```c
// signed overflow 예시 (undefined behavior)
signed char a = 127;
a++;  // 127 + 1 = -128 (오버플로우, 결과 예측 불가)

// unsigned wraparound 예시 (정의된 동작)
unsigned char b = 255;
b++;  // 255 + 1 = 0 (modulo 256, 결과 예측 가능)
```

> **⚠️ 주의**: signed overflow는 undefined behavior이므로 절대 의존하면 안 된다.

---

### 진법

### 2진수

- `1011.01`
    - 1×2³ + 0×2² + 1×2¹ + 1×2⁰ + 0×2⁻¹ + 1×2⁻²
- `10110110`
    - signed 타입의 경우 첫번째 자리(MSB)는 부호 역할
    - 마지막 자리(LSB)는 홀/짝 구분 역할
- 2비트 ⇒ 2² = 4가지 표현

**진수 변환 요약**

| 10진수 | 2진수 | 8진수 | 16진수 |
|---|---|---|---|
| 0 | 0000 | 0 | 0 |
| 8 | 1000 | 10 | 8 |
| 10 | 1010 | 12 | A |
| 15 | 1111 | 17 | F |
| 16 | 10000 | 20 | 10 |

**진수 변환 방법**
- **10진수 → 2진수**: 2로 반복해서 나누고 나머지를 역순으로 읽음
- **2진수 → 8진수**: 오른쪽부터 3비트씩 묶어서 변환 (8 = 2³)
- **2진수 → 16진수**: 오른쪽부터 4비트씩 묶어서 변환 (16 = 2⁴)

---

### 상수와 변수의 이해

- **변수**
    - 반드시 초기화 해야 한다! (안 하면 쓰레기값(garbage value) 들어있음, 책임은 개발자에게)
    - 변수의 이름은 일반적인 Naming Rule (회사마다 다를 수 있음)
    - 일반적인 C 네이밍: snake_case (단어 사이를 _로 연결)

- **상수의 2분류**
    - 일반 상수 : `10`, `3.14`, `'A'`
    - 주소 상수 : 문자열 상수(`"hello"`)의 시작 주소, 함수명, 배열명 등

- **변수의 2분류**
    - 일반 변수 : 일반 상수 저장 (`int a = 10;`)
    - 포인터 변수 : 주소 상수 저장 (`int *p = &a;`)

> **💡 리터럴 상수의 타입**
> ```c
> 10      // int 상수
> 10L     // long 상수
> 10LL    // long long 상수
> 10U     // unsigned int 상수
> 3.14    // double 상수 (기본)
> 3.14f   // float 상수
> 'A'     // char 상수 (ASCII 65)
> "hello" // const char* (문자열 상수, 주소 반환)
> ```

---

### 숫자 상수

- **숫자 상수**
    - 정수 상수
        - `012` 처럼 앞에 `0`이 붙어있으면 8진수
        - `0x1A` 처럼 `0x`가 붙어있으면 16진수
    - 실수 상수 (10진수로 표현 사용)

- **데이터 표현에 사용되는 3가지 진법**
    - 10진법 : 0이 아닌 수로 시작되는 수
    - 8진법 : `0`을 접두어로 가짐
    - 16진법 : `0x`를 접두어로 가짐, 0~9, A~F
    - (컴퓨터 내부의 2진수는 코드에서 표기 불가)

```c
#include <stdio.h>

int main()
{
    // y는 8진수(앞에 0), z는 16진수(앞에 0x)
    // signed가 디폴트
    // 4바이트 -> 32비트
    int x = 10, y = 010, z = 0x10;

    // x = 10(10진수) ==> 0000 0000 0000 0000 0000 0000 0000 1010
    // y = 010(8진수) = 8(10진수) ==> 0000 0000 0000 0000 0000 0000 0000 1000
    // z = 0x10(16진수) = 16(10진수) ==> 0000 0000 0000 0000 0000 0000 0001 0000

    // %d : 10진수 출력, %o : 8진수 출력, %x : 16진수 출력
    printf("x의 값: %d %o %x\n", x, x, x);  // 10  12  a
    printf("y의 값: %d %o %x\n", y, y, y);  //  8  10  8
    printf("z의 값: %d %o %x\n", z, z, z);  // 16  20  10

    return 0;
}
```

> **💡 x의 결과가 왜 `12 a`인가?**
> - `10`(10진수) = `12`(8진수) = `a`(16진수)
> - 8진수 12는 "십이"가 아니라 "일이" → 1×8¹ + 2×8⁰ = 10

---

### 연산자의 종류

### 산술 연산자

| 연산자 | 의미 | 예시 |
|---|---|---|
| `+` | 덧셈 | `a + b` |
| `-` | 뺄셈 | `a - b` |
| `*` | 곱셈 | `a * b` |
| `/` | 나눗셈 (정수끼리면 몫만) | `7 / 2 = 3` |
| `%` | 나머지 | `7 % 2 = 1` |

```c
// 정수 나눗셈 주의!
int a = 7, b = 2;
printf("%d\n", a / b);    // 3 (소수점 버림)
printf("%f\n", (double)a / b);  // 3.500000 (형변환 후 나눗셈)
```

### 관계 연산자

| 연산자 | 의미 |
|---|---|
| `==` | 같다 |
| `!=` | 다르다 |
| `>`, `<` | 크다, 작다 |
| `>=`, `<=` | 크거나 같다, 작거나 같다 |

> **⚠️ 주의**: `=`는 대입, `==`는 비교! 혼동하지 말 것.

### 논리 연산자

| 연산자 | 의미 | Short-circuit |
|---|---|---|
| `&&` | AND (모두 참이면 참) | 앞이 거짓이면 뒤 평가 안 함 |
| `\|\|` | OR (하나라도 참이면 참) | 앞이 참이면 뒤 평가 안 함 |
| `!` | NOT | - |

### 대입 연산자

```c
a = 10;     // 대입
a += 5;     // a = a + 5
a -= 3;     // a = a - 3
a *= 2;     // a = a * 2
a /= 4;     // a = a / 4
a %= 3;     // a = a % 3
a &= 0xFF;  // a = a & 0xFF
a |= 0x01;  // a = a | 0x01
a ^= 0x10;  // a = a ^ 0x10
a <<= 1;    // a = a << 1
a >>= 1;    // a = a >> 1
```

### 증감 연산자

```c
int a = 5;
printf("%d\n", a++);  // 5 출력 후 a = 6 (후위: 사용 후 증가)
printf("%d\n", ++a);  // a = 7 후 7 출력 (전위: 증가 후 사용)
printf("%d\n", a--);  // 7 출력 후 a = 6
printf("%d\n", --a);  // a = 5 후 5 출력
```

### 삼항 연산자 (조건 연산자)

```c
// (조건식) ? 참일_때_값 : 거짓일_때_값
int max = (a > b) ? a : b;

// if-else의 축약형
if (a > b)
    max = a;
else
    max = b;
```

### sizeof 연산자

```c
printf("%zu\n", sizeof(int));       // 4
printf("%zu\n", sizeof(double));    // 8
printf("%zu\n", sizeof(char));      // 1

int arr[5];
printf("%zu\n", sizeof(arr));       // 20 (배열 전체 크기)
printf("%zu\n", sizeof(arr) / sizeof(arr[0]));  // 5 (요소 개수)
```

### 비트 연산자

- `a` → `1011 0011`
- `b` → `0110 1110`

```
~a    → 0100 1100   (1의 보수, NOT)
a & b → 0010 0010   (bit clear - 특정 비트 추출/끄기)
a | b → 1111 1111   (bit set - 특정 비트 켜기)
a ^ b → 1101 0010   (bit toggle - 특정 비트 반전)
a << 1 → 0110 0110  (왼쪽 시프트, ×2 효과, 최우측은 0 채움)
a >> 1 → 0101 1001  (오른쪽 시프트, ÷2 효과)
```

> **💡 시프트 연산 활용**
> - `a << n` : a × 2ⁿ (2의 n승 곱하기)
> - `a >> n` : a ÷ 2ⁿ (2의 n승 나누기, 정수 나눗셈)
> - signed와 unsigned에서 `>>` 동작 차이 주의: signed는 MSB(부호비트)로 채움, unsigned는 0으로 채움

---

### 부호와 1의 보수

- 1의 보수 : 모든 비트를 반전
    - `0000 1100` (12) → `1111 0011` (-12, 1의 보수 표현)
    - 문제: 0이 두 가지 표현 존재 (`0000 0000`, `1111 1111`)

---

### 부호와 2의 보수

- **전세계 모든 컴퓨터가 사용하는 방식**
- 음수 = 1의 보수 + 1
- 12(10진수)를 -12로 만들기:
    - `0000 1100` (12)
    - `1111 0011` (1의 보수)
    - `1111 0100` (2의 보수 = -12)

```
검증: 12 + (-12) = 0
  0000 1100
+ 1111 0100
-----------
1 0000 0000 (캐리 비트 무시 → 0000 0000 = 0) ✓
```

- 비트는 CPU에서 연산 → 임시 기억 저장소 레지스터 → 메모리 → 화면 출력
    - CPU : 얼마나 빨리 연산하느냐
    - 메모리(RAM) : 얼마나 많이 올려둘 수 있느냐

---

### 저장용량

- 1byte = 8bit
- 1KB = 2¹⁰ byte = 1,024 byte
- 1MB = 2²⁰ byte = 1,024 KB
- 1GB = 2³⁰ byte = 1,024 MB
- 영문자 하나는 1byte (ASCII), 한글은 보통 2~3byte (인코딩 방식에 따라)

---

### 실수 (floating point)

- **부동소수점수**: 소수점의 위치가 변동된다
- 컴퓨터 내부 메모리에는 소수점을 직접 표현할 수 없음
    - `11001.11` → `+1.100111 × 2⁴` (정규화)
    - 정규화: 소수점을 이동시켜 1.xxxx 형태로 만드는 것
- **IEEE 754 규약**에 맞춰 변환 (전세계 표준)
    - float (32bit) : 부호(1) + 지수(8) + 가수(23)
    - double (64bit) : 부호(1) + 지수(11) + 가수(52)

```c
// 실수형 주의사항: 부동소수점 오차
float a = 0.1f + 0.2f;
printf("%.20f\n", a);  // 0.30000001192092895508 (오차 발생!)

// 비교 시 주의
if (a == 0.3f)  // 이렇게 하면 안 됨!
if (fabs(a - 0.3f) < 1e-6)  // 오차 범위 내 비교가 올바른 방법
```

---

### Short circuit(단축 평가) & Sequence Point (시퀀스 포인트)

- 처리 속도의 효율성을 고려한 기능

**Short circuit**
- 판단이 완료되는 순간 뒤의 식은 계산하지 않는다.

```c
int a = 3, b = 4;

if (++a > 2 || ++b > 2) {};
// ++a가 4 > 2 → 참이므로 ||에서 단락평가 → ++b는 실행 안 됨!
// 결과: a = 4, b = 4 (b는 증가 안 됨)

if (++a < 2 && ++b < 2) {};
// ++a가 5 < 2 → 거짓이므로 &&에서 단락평가 → ++b는 실행 안 됨!
```

**Sequence Point**
- 모든 식의 계산이 완료되는 지점 (세미콜론, 함수 호출 전 등)
- 시퀀스 포인트 사이에서 같은 변수를 두 번 수정하면 **undefined behavior**

```c
// 잘못된 코드 (undefined behavior)
int i = 5;
i = i++;        // undefined behavior!
i = (i++ + i++); // undefined behavior!

// 올바른 코드
int j = 0;
int k = j++;  // j는 0을 k에 저장 후 1로 증가
printf("k=%d, j=%d\n", k, j);  // k=0, j=1
```

---

### 형 변환 (Type Casting)

```c
// 묵시적 형 변환 (자동, 작은 타입 → 큰 타입)
int a = 10;
double b = a;  // int → double, 자동 변환

// 명시적 형 변환 (강제 캐스팅)
double x = 3.14;
int y = (int)x;  // 3 (소수점 버림, 반올림 아님!)

// 실수 나눗셈
int p = 7, q = 2;
double result = (double)p / q;  // 3.5 (p만 캐스팅해도 OK)
```

> **💡 암시적 형 변환 우선순위** (작은 것 → 큰 것으로 자동 변환)
> `char` → `short` → `int` → `long` → `long long` → `float` → `double` → `long double`

---

### 조건문 if

```c
if (조건식 - 1)
{
    처리문장 1;
}
else if (조건식2)
{
    처리문장2;
}
else
{
    나머지 처리;
}
```

```c
// 1. 좋지 않은 식. 아래는 모두 dead code가 된다.
if (1) { ... }

// 2. 대입(=)과 비교(==) 혼동 주의! a=1은 항상 참(1)
// 아래 if 안의 else는 dead code가 된다.
if (a = 1) { ... }  // 항상 참, 버그!
if (a == 1) { ... } // 올바른 비교

// 3. 안전한 비교 패턴 (Yoda Condition)
if (1 == a) { ... }  // 상수를 왼쪽에 → 실수로 = 쓰면 컴파일 오류
```

---

### 선택문 switch ~ case

- 경우에 따라 별개의 문장 수행
- 수식의 위치에는 **정수값** 또는 문자로 평가되는 식이나 변수 (실수, 문자열 불가)
- `case` 문의 상수는 반드시 **정수형 상수** 또는 **문자 상수**
- `case`문 마지막에는 꼭 `break` 써주기!

```c
switch (변수 또는 정수식)
{
    case 상수1:
        처리문장1;
        break;
    case 상수2:
        처리문장2;
        break;
    default:  // 어떤 case에도 해당 안 될 때 (선택사항)
        기본처리;
        break;
}
```

> **💡 fall-through 활용 (의도적으로 break 생략)**
> ```c
> switch (grade) {
>     case 'A':
>     case 'B':
>         printf("우수\n");  // A, B 모두 이 문장 실행
>         break;
>     case 'C':
>         printf("보통\n");
>         break;
> }
> ```

---

## 반복문

- 몇 번 반복할 것인가 : 제어 변수

### while ; 반복 횟수를 모르는 경우

```c
while (조건식) {
    반복 수행할 문장;
}

// 예시 1 - 조건 제어
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;  // 증감식 누락 시 무한루프 주의!
}

// 예시 2 - break 제어
int i = 0;
while (1) {  // 무한루프
    if (i >= 10) break;  // 탈출 조건
    printf("%d\n", i);
    i++;
}
```

### for ; 반복 횟수를 아는 경우

```c
for (초기화식; 조건식; 증감식)
{
    반복 수행할 문장;
}

// 예시
for (int i = 0; i < 10; i += 2) {
    printf("%d\n", i);  // 0, 2, 4, 6, 8
}

// 중첩 for (2차원 배열 순회 등)
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("[%d][%d] ", i, j);
    }
    printf("\n");
}
```

### do ~ while

- 최소 한 번은 반드시 실행됨 (조건 검사가 끝에 있음)

```c
do
{
    반복한 문장;
} while (조건식);  // 세미콜론 필수!

// 활용 예: 유효한 입력을 받을 때까지 반복
int input;
do {
    printf("1~10 사이 숫자 입력: ");
    scanf("%d", &input);
} while (input < 1 || input > 10);
```

---

### 분기문 - continue, break, goto

- **break**: 현재 반복문 또는 switch 즉시 탈출
- **continue**: 현재 반복의 나머지를 건너뛰고 다음 반복으로

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) break;      // 5에서 반복 종료 → 0,1,2,3,4 출력
    printf("%d\n", i);
}

for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;  // 짝수는 건너뜀 → 1,3,5,7,9 출력
    printf("%d\n", i);
}
```

- **goto**: 지정한 레이블로 무조건 분기 (가독성 저하로 사용 지양)

```c
// goto는 되도록 사용하지 않는 것이 좋다.
// 예외적으로 깊은 중첩 루프 탈출 시 사용하기도 함
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        if (i * j > 50) goto exit_loop;
    }
}
exit_loop:
printf("탈출!\n");
```

---

### 배열 - 1차원

```c
// 선언
int arr[5];              // 크기 5의 int 배열 (초기화 없음 → 쓰레기값)
int arr[5] = {1,2,3,4,5}; // 선언과 동시에 초기화
int arr[5] = {0};         // 모두 0으로 초기화
int arr[] = {1,2,3};      // 크기 자동 계산 (3)

// 접근
arr[0] = 10;   // 0번 인덱스에 저장
printf("%d\n", arr[2]);  // 2번 인덱스 값 출력

// 배열명은 배열 첫 번째 요소의 주소
printf("%p\n", arr);     // arr[0]의 주소
printf("%p\n", &arr[0]); // 동일한 주소

// 문자 입력 받기
char name[20];
fgets(name, sizeof(name), stdin);
// (저장 장소, 크기, 어디에서 데이터를 읽을지)
// stdin : 입력버퍼에서 읽어오겠다. (키보드)
// 주의: 개행문자(\n)가 함께 저장됨 → 제거 필요
name[strcspn(name, "\n")] = '\0';
```

> **⚠️ 배열 범위 초과(Out of Bounds) 주의!**
> C는 배열 범위를 자동으로 체크하지 않음. 범위를 벗어나면 다른 메모리를 침범하는 undefined behavior 발생.

---

### 배열 - 2차원

```c
// 선언: 자료형 배열명[행크기][열크기]
int arr[3][4];  // 3행 4열

// 초기화
int arr[2][3] = {{1,2,3}, {4,5,6}};
int arr[2][3] = {1,2,3,4,5,6};  // 동일한 결과

// 접근
arr[1][2] = 10;  // 1행 2열에 저장

// 메모리 상 연속적으로 저장됨 (행 우선 순서)
// arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2]

// 배열 크기 구하기
int rows = sizeof(arr) / sizeof(arr[0]);    // 행 개수
int cols = sizeof(arr[0]) / sizeof(arr[0][0]); // 열 개수
```

---

### 포인터 연산

- 포인터 연산 시 **처음 할당된 타입의 크기만큼** 증감된다.

| 포인터 타입 | 연산 후 증감 크기 |
|---|---|
| `char*` | 1 byte |
| `short*` | 2 byte |
| `int*` | 4 byte |
| `float*` | 4 byte |
| `double*` | 8 byte |

> **핵심**: 방 이동과 값 연산 구분이 제일 중요하다!!!

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;  // arr[0]의 주소

printf("%d\n", *p);      // 10 (값)
printf("%d\n", *(p+1));  // 20 (주소+1칸 이동 후 값)
p++;  // p가 arr[1]을 가리킴
printf("%d\n", *p);      // 20

// 배열과 포인터 등가 표현
arr[i] == *(arr + i)  // 동일!
&arr[i] == (arr + i)  // 동일!
```

```c
// 포인터 연산 우선순위 정리
int a = 5;
int *ptr = &a;

*ptr++;    // *ptr의 값을 구하고 ptr을 1 증가 (후위++)
(*ptr)++;  // *ptr의 값을 1 증가 (ptr 주소는 변화 없음)
*++ptr;    // ptr 1 증가 후 *ptr 계산 (전위++)
++*ptr;    // *ptr의 값을 1 증가시킨 후 그 값 반환
```

---

### 배열 포인터

```c
int arr[5] = {1, 2, 3, 4, 5};

// 배열명은 상수 주소 → 변경 불가!
// arr = &arr[1];  // 오류! 배열명은 상수

int *p = arr;   // 포인터 변수로 배열 접근 가능
p++;            // p는 변수이므로 변경 가능

// 포인터를 배열처럼 사용
printf("%d\n", p[1]);    // *(p+1)와 동일
printf("%d\n", *(p+2));  // p[2]와 동일
```

---

### 포인터와 문자열

```c
// 두 가지 방법의 차이가 매우 중요!
char str1[5] = "abcd";  // 상수영역 → 스택영역으로 복사 (수정 가능)
char *str2 = "abcd";    // 상수영역의 주소만 저장 (수정 불가!)

str1[0] = 'A';  // OK (스택의 복사본 수정)
// str2[0] = 'A'; // 위험! 상수 영역 수정 → 런타임 오류 (Segfault)

// 올바른 const 선언
const char *str3 = "abcd";  // const로 명시 (수정 불가)
```

> **주소가 되는 것들**
> 1. 배열명 → 배열 첫 번째 요소의 주소
> 2. 문자열 리터럴 → 문자열 상수 첫 번째 문자의 주소
> 3. 함수명 → 함수의 시작 주소

---

### 다차원 포인터

```c
/*
a의 차원은 0차원 (정수값)
int방의 주소를 추출하면 int* 타입 (1차원)
int*이 있는 방의 주소를 추출하면 int** 타입 (2차원)
int**이 있는 방의 주소를 추출하면 int*** 타입 (3차원)

변수의 주소를 딸 때마다 차원이 올라감
*/

#include <stdio.h>
int main(void) {
    int a, b;

    int *p1;    // 1차원 int 포인터변수 선언 (1번 따라가면 int)
    int **p2;   // 2차원 포인터변수 (2번 따라가면 int)
    int ***p3;  // 3차원 포인터변수 (3번 따라가면 int)

    p1 = &a;
    p2 = &p1;
    p3 = &p2;

    // 아래 4개의 문장은 동일하다
    a = 25;
    *p1 = 25;
    **p2 = 25;
    ***p3 = 25;

    return 0;
}
```

---

### 포인터 배열과 배열 포인터

```c
// 포인터 배열: 배열 안의 값이 주소(포인터)
int *p2[5];  // 요소 5개짜리 배열, 각 요소는 int* (int를 가리키는 포인터)

// 배열 포인터: 포인터가 배열을 가리킴
int (*p3)[5];  // p3는 포인터, 가리키는 곳에 int형 5열 배열이 있음
               // 2차원 배열의 행 포인터로 사용됨
```

> **💡 헷갈릴 때 읽는 법**: `*`와 `[]` 중 괄호가 더 가까운 것이 먼저 결합
> - `int *p[5]`: p는 배열(`[5]` 먼저), 각 요소는 `int*` → **포인터 배열**
> - `int (*p)[5]`: p는 포인터(`*` 먼저, 괄호로 묶임), 가리키는 것은 `int[5]` → **배열 포인터**

---

### 다차원 배열과 포인터

```c
#include <stdio.h>
int main()
{
    // ary[면][행][열]
    // 선언문에서 []는 쓸수록 차원이 올라감
    // 실행문에서 []는 쓸수록 차원이 내려감 (역참조)

    int ary[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}},
                        {{1,2,3,4},{5,6,7,8},{9,10,11,12}}};

    // 값 표현 (가장 낮은 차원까지 내려가야 실제 값)
    // ary[i]      == *(ary + i)         → 2차원 배열 (면)
    // ary[i][j]   == *(*(ary + i) + j)  → 1차원 배열 (행)
    // ary[i][j][k]== *(*(*(ary+i)+j)+k) → 정수 값

    // 주소 표현 (마지막 * 하나 제거)
    // &ary[i]      == (ary + i)
    // &ary[i][j]   == (*(ary + i) + j)
    // &ary[i][j][k]== (*(*(ary + i) + j) + k)

    return 0;
}
```

---

## 동적 메모리

### 동적 메모리 할당

- 프로그램 수행 도중 필요한 메모리를 할당 받아 사용
- 동적 할당 메모리는 **힙(Heap) 영역**에 생성
- 생성 메모리는 반드시 개발자가 직접 해제해야 함 (`free`)
- 해제하지 않으면 **메모리 누수(Memory Leak)** 발생

| **함수** | **선언 예시** | **설명** |
|---|---|---|
| `malloc()` | `void *ptr = malloc(size);` | 메모리 블록 할당 (초기화 없음, 쓰레기값) |
| `calloc()` | `void *ptr = calloc(num, size);` | 메모리 블록 할당 + **0으로 초기화** |
| `realloc()` | `void *ptr = realloc(ptr, new_size);` | 이미 할당된 블록 크기 변경 |
| `free()` | `free(ptr);` | 동적 할당 메모리 해제 |

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc 사용 예시
    int *arr = (int *)malloc(sizeof(int) * 5);  // int 5개 공간 할당

    if (arr == NULL) {  // 할당 실패 시 NULL 반환 → 반드시 체크!
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // calloc: 0으로 초기화까지
    // malloc(sizeof(int) * 5) == calloc(5, sizeof(int))
    int *arr2 = (int *)calloc(5, sizeof(int));

    // realloc: 크기 변경 (기존 데이터 유지)
    arr = (int *)realloc(arr, sizeof(int) * 10);

    // 반드시 해제! (시작 주소로 해제해야 함)
    free(arr);
    free(arr2);
    arr = NULL;   // 해제 후 NULL로 초기화 권장 (dangling pointer 방지)
    arr2 = NULL;

    return 0;
}
```

> **⚠️ 주의사항**
> - `free()` 시 반드시 **시작 주소**를 전달 (중간 주소 사용 시 오류)
> - 이미 해제한 메모리 다시 해제하면 (double free) 프로그램 종료
> - 해제 후 포인터를 NULL로 초기화하는 습관을 들이자

---

### 2차원 배열의 동적 메모리 할당

```c
int **ip;
int rows = 3, cols = 4;

// 1단계: 행 포인터 배열 할당
ip = (int **)malloc(sizeof(int *) * rows);

// 2단계: 각 행에 열 배열 할당
for (int i = 0; i < rows; i++) {
    ip[i] = (int *)malloc(sizeof(int) * cols);
}

// 사용
ip[1][3] = 100;

// !!!!!!!!!!!!!!!!! 해제는 반드시 열부터 !!!!!!!!!!!!!!!!!
// 행부터 해제하면 열의 주소를 찾을 수 없다!
for (int i = 0; i < rows; i++) {
    free(ip[i]);   // 먼저 각 행의 열 해제
}
free(ip);          // 그 다음 행 포인터 배열 해제
ip = NULL;

// 행마다 열 크기가 다른 가변 배열도 가능
// 각각 malloc/free 쌍이 맞아야 함
```

---

### 서브넷

- 서브넷 마스크 계산
    - `/27` → 32비트 중 앞 27비트가 1

    ```
    11111111.11111111.11111111.11100000
    = 255.255.255.224
    ```

- **진법 팁**

    | CIDR | 마지막 옥텟 | 사용 가능 호스트 수 |
    |---|---|---|
    | `/24` | 0 | 254 |
    | `/25` | 128 | 126 |
    | `/26` | 192 | 62 |
    | `/27` | 224 | 30 |
    | `/28` | 240 | 14 |

- **네트워크 연산 (AND 연산으로 같은 네트워크인지 확인)**

    `200.1.1.65/27` 분석:
    ```
    IP (65):   01000001
    마스크(224): 11100000
    AND 결과:   01000000 = 64 → 네트워크 주소: 200.1.1.64
    ```

    - `200.1.1.80` 과 같은 네트워크인지?
        ```
        80:  01010000 AND 11100000 = 01000000 = 64 → 같은 네트워크 ✓
        ```
    - `200.1.1.100` 과 같은 네트워크인지?
        ```
        100: 01100100 AND 11100000 = 01100000 = 96 → 다른 네트워크 ✗
        ```

---

### 기억 클래스

```
┌─────────────────────────────────────────────────────────┐
│                  메모리 영역                              │
├────────────────────┬────────────────────────────────────┤
│ 코드 (Code/Text)   │ 프로그램 명령어 저장                 │
├────────────────────┼────────────────────────────────────┤
│ 데이터 (Data)      │ 초기화된 전역/정적 변수              │
├────────────────────┼────────────────────────────────────┤
│ BSS               │ 초기화되지 않은 전역/정적 변수 (0)   │
├────────────────────┼────────────────────────────────────┤
│ 힙 (Heap)         │ 동적 할당 메모리 (아래 → 위로 성장) │
├────────────────────┼────────────────────────────────────┤
│ 스택 (Stack)      │ 지역 변수, 함수 호출 (위 → 아래 성장)│
└────────────────────┴────────────────────────────────────┘
```

- **레지스터 변수** (`register`): CPU Register에 저장 → 연산 속도가 가장 빠름 (현대 컴파일러는 자동 최적화)
- **전역 변수 (데이터/BSS 영역)**: 모든 파일에서 사용 가능, 프로그램 종료까지 유지
- **지역 변수 (스택)**: 함수 내에서만 유효, 함수 종료 시 소멸. 런타임에 크기 결정
- **동적 메모리 (힙)**: `malloc`/`free`. 컴파일 시 크기 불확정

```c
int globalVar = 10;      // 전역 변수 (Data 영역)
int globalVar2;          // 전역 변수 (BSS 영역, 0으로 초기화)

void func() {
    int localVar = 5;    // 지역 변수 (Stack)
    static int count = 0; // 정적 지역 변수 (Data 영역, 함수 종료 후에도 유지!)
    count++;
    printf("호출 횟수: %d\n", count);
}
```

---

### static

- **함수 내 선언 시**: 지역 변수이지만 프로그램 종료까지 값 유지 (static 지역 변수)
- **함수 외부 선언 시**: 전역 변수이지만 **해당 파일 내에서만** 접근 가능 (internal linkage)

```c
// static 지역 변수 활용
void counter() {
    static int count = 0;  // 최초 1회만 초기화
    count++;
    printf("count = %d\n", count);
}

int main() {
    counter();  // count = 1
    counter();  // count = 2
    counter();  // count = 3
    return 0;
}
```

- `auto` : 지역변수의 기본값 (생략 가능, 현재는 거의 안 씀)
- `extern` : 다른 파일에 정의된 전역 변수를 가져다 쓸 때 선언

---

## 구조체

- 관련있는 것들을 묶어둔 것 (OOP의 추상화와 유사)

```c
// 선언 방법 1: struct 태그 사용
struct Student {
    char name[20];
    int age;
    float gpa;
};
struct Student s1;  // 사용 시 struct 키워드 필요

// 선언 방법 2: typedef로 별칭 지정 (가장 많이 사용)
typedef struct {
    char name[20];
    char phone[25];
} Friend;

Friend f1;  // struct 없이 바로 사용 가능

// 선언 방법 3: 구조체명 + 별칭 동시 지정
typedef struct Node {
    int data;
    struct Node *next;  // 자기 참조 시 구조체명 필요
} Node;
```

```c
// 구조체 초기화 및 접근
Friend f2 = {"홍길동", "010-1234-5678"};  // 선언과 동시에 초기화
strcpy(f2.name, "이몽룡");   // 문자열 복사 (= 직접 대입 불가)
printf("%s\n", f2.name);

// 구조체 복사 (=로 가능)
Friend f3 = f2;   // 멤버 전체가 복사됨 (deep copy 아님, 포인터 멤버 주의)
```

---

### 구조체와 포인터

```c
Friend friend = {"저팔계", "010-0000-0000"};
Friend *ptr = &friend;

// -> 연산자: 포인터를 통한 구조체 멤버 접근
strcpy(ptr->name, "저팔계");    // ptr->name == (*ptr).name
printf("%s\n", ptr->name);

// 구조체 포인터를 함수에 전달 (call by reference)
void printFriend(Friend *f) {
    printf("이름: %s, 전화: %s\n", f->name, f->phone);
}
printFriend(&friend);
```

---

### 자기 참조 구조체 (연결 리스트)

```c
typedef struct Node {
    int data;
    struct Node *next;  // 자기 자신 타입의 포인터
} Node;

// 단순 연결 리스트 구성
Node n1 = {10, NULL};
Node n2 = {20, NULL};
n1.next = &n2;  // n1 → n2

// 순회
Node *cur = &n1;
while (cur != NULL) {
    printf("%d\n", cur->data);
    cur = cur->next;
}
```

---

### Bit Field

```c
// 비트 단위로 멤버 할당 (메모리 절약)
typedef struct {
    unsigned int age  : 7;   // 7비트 → 0~127
    unsigned int gender : 1; // 1비트 → 0 or 1
    unsigned int grade : 4;  // 4비트 → 0~15
} Person;
// 전체: 1byte + 일부 (구현에 따라 다름)
// 패딩 때문에 실제 sizeof는 예상과 다를 수 있음
```

---

### 공용체 (union)

```c
// 구조체: 각 구성원을 연속적인 메모리에 할당
// 공용체: 각 구성원이 같은 메모리 공간 공유 → 동시에 한 멤버만 유효

union number {
    char a;    // 1바이트
    short b;   // 2바이트
    long c;    // 8바이트
};
// 가장 큰 멤버(long, 8바이트) 크기로 할당
// 시작 주소가 모두 같음 → 값을 바꾸면 다른 멤버 값도 바뀜!

union number u;
u.c = 0x12345678;
printf("%x\n", u.b);  // 하위 2바이트만 해석 (엔디안에 따라 결과 다름)
```

---

### 열거형 (enum)

```c
// 정수형 상수에 이름을 부여
enum Season {SPRING, SUMMER, FALL, WINTER};
// 기본값: SPRING=0, SUMMER=1, FALL=2, WINTER=3

enum Color {RED=1, GREEN=2, BLUE=4};  // 직접 값 지정

enum Season s = SUMMER;
printf("%d\n", s);  // 1

// switch와 함께 자주 사용
switch (s) {
    case SPRING: printf("봄\n"); break;
    case SUMMER: printf("여름\n"); break;
}
```

---

### 엔디안 (Endian)

- 컴퓨터의 메모리에 데이터를 저장하는 순서

- **빅 엔디안 (Big Endian)**: MSB부터 저장
    - 메인프레임, 네트워크 통신 표준
    - `0x12345678` → `12 34 56 78` 순으로 저장
    - 사람이 읽는 순서와 동일 (직관적)

- **리틀 엔디안 (Little Endian)**: LSB부터 저장
    - 현재 대부분의 PC (x86, x64)
    - `0x12345678` → `78 56 34 12` 순으로 저장
    - 연산이나 타입 변환 시 효율적
    - `printf` 출력 시에는 내부적으로 변환하여 `12345678`로 출력

```c
// 엔디안 확인 방법
#include <stdio.h>

int main() {
    int n = 1;
    char *p = (char *)&n;

    if (*p == 1)
        printf("Little Endian\n");  // 낮은 주소에 하위 바이트(01)가 있음
    else
        printf("Big Endian\n");

    return 0;
}
```

---

## 입출력 함수

- 입력 스트림, 출력 스트림
    - 키보드: `stdin` (standard in)
    - 모니터: `stdout` (standard out)
    - 오류: `stderr` (standard error)

```c
// 표준 출력
printf("정수: %d, 실수: %.2f, 문자: %c, 문자열: %s\n", i, f, c, s);

// 표준 입력 (주의: 버퍼 오버플로우 위험)
int x;
scanf("%d", &x);  // 변수 앞에 & 필수!

// 문자열 입력 (scanf보다 안전)
char buf[100];
fgets(buf, sizeof(buf), stdin);  // 개행문자 포함됨 → 제거 필요
buf[strcspn(buf, "\n")] = '\0';

// 한 문자 입력 (입력 버퍼 사용 안 함)
// _getch();  // Windows 전용, 화면 멈춤 용도
```

> **⚠️ scanf 주의사항**
> - 문자열(char[]) 입력 시 `&` 불필요 (배열명 자체가 주소)
> - `scanf("%s", buf)` 는 공백에서 읽기 멈춤, 크기 제한 없어 위험
> - 권장: `scanf("%99s", buf)` 또는 `fgets` 사용

---

### 저수준 vs 고수준 파일 I/O

| 구분 | 저수준 (Low-level) | 고수준 (High-level) |
|---|---|---|
| 함수 | `open`, `read`, `write`, `close` | `fopen`, `fread`, `fwrite`, `fclose` |
| 버퍼 | 없음 (직접 OS 접근) | 있음 (stdio 버퍼) |
| 이식성 | 낮음 (OS 종속) | 높음 (표준 C) |
| 속도 | 빠름 (버퍼 없으므로) | 버퍼링으로 실질적으로 빠름 |

---

### 파일 입출력

```c
#include <stdio.h>

int main() {
    FILE *fp;

    // 쓰기
    fp = fopen("test.txt", "w");  // "w": 쓰기, "r": 읽기, "a": 추가
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    fprintf(fp, "Hello, File!\n");
    fclose(fp);

    // 읽기
    char buf[100];
    fp = fopen("test.txt", "r");
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    }
    fclose(fp);

    // 바이너리 파일 (이미지 등)
    // fp = fopen("image.jpg", "rb");  // "rb": 바이너리 읽기
    // fp = fopen("output.jpg", "wb"); // "wb": 바이너리 쓰기

    return 0;
}
```

> **파일 모드 정리**
> - `"r"`: 읽기 (파일 없으면 실패)
> - `"w"`: 쓰기 (기존 내용 삭제)
> - `"a"`: 추가 (파일 끝에 이어쓰기)
> - `"rb"`, `"wb"`, `"ab"`: 바이너리 모드

---

## 함수 포인터

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    // 함수 포인터 선언: 반환타입 (*변수명)(매개변수타입들)
    int (*fptr)(int, int);

    fptr = add;   // 함수명은 함수의 시작 주소
    printf("%d\n", fptr(3, 4));  // 7

    fptr = sub;
    printf("%d\n", fptr(10, 3)); // 7

    // 함수 포인터 배열
    int (*ops[2])(int, int) = {add, sub};
    printf("%d\n", ops[0](5, 3)); // 8
    printf("%d\n", ops[1](5, 3)); // 2

    return 0;
}
```

> **활용**: 콜백 함수, 전략 패턴, 함수 테이블 등에 사용

---

### void 포인터

```c
#include <stdio.h>

int main()
{
    int a = 10;
    char b = 'x';

    void *ptr = &a;  // 어떤 타입의 주소든 저장 가능 (제한 없음)

    // 값을 가져오려면 반드시 형변환 필요!
    printf("void ptr → int: %d\n", *((int *)(ptr)));

    ptr = &b;
    printf("void ptr → char: %c\n", *((char *)(ptr)));

    // malloc()의 반환 타입이 void*인 이유
    // → 어떤 타입으로든 받을 수 있어야 하기 때문
    // int *ip = (int *)malloc(sizeof(int) * 5);

    return 0;
}
```

---

## 전처리기 (Preprocessor)

```c
// 헤더 파일 포함
#include <stdio.h>   // 시스템 헤더 (컴파일러 경로에서 탐색)
#include "mylib.h"   // 사용자 정의 헤더 (현재 디렉토리에서 탐색)

// 매크로 상수 정의
#define MAX_SIZE 100
#define PI 3.14159265

// 함수형 매크로 (주의: 부작용 가능성)
#define SQUARE(x) ((x) * (x))  // 괄호로 연산자 우선순위 문제 방지
// SQUARE(a+1) → ((a+1)*(a+1)) ✓
// #define SQUARE(x) x*x 이면 SQUARE(a+1) → a+1*a+1 = 오류 ✗

// 조건부 컴파일
#define DEBUG

#ifdef DEBUG
    printf("디버그 모드\n");
#endif

#ifndef MYLIB_H  // 헤더 중복 포함 방지 (include guard)
#define MYLIB_H
// 헤더 내용
#endif
```

---

## 분할 컴파일

- 프로젝트가 커지면 여러 파일로 분리

```
// main.c
#include "math_utils.h"  // 헤더 파일 포함

int main() {
    int result = add(3, 5);
    return 0;
}

// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H
int add(int a, int b);  // 함수 선언 (prototype)
#endif

// math_utils.c
#include "math_utils.h"
int add(int a, int b) {  // 함수 정의
    return a + b;
}
```

```powershell
# 각각 컴파일 후 링크
gcc -c main.c           # main.obj 생성
gcc -c math_utils.c     # math_utils.obj 생성
gcc main.obj math_utils.obj -o program  # 링크 → program.exe
```

---

# 9. (추후 작성)

---

# 19. C표준 주요 라이브러리 헤더 파일 및 기능

| 헤더 파일 | 주요 기능 |
|---|---|
| `<stdio.h>` | 표준 입출력 (`printf`, `scanf`, `fopen` 등) |
| `<stdlib.h>` | 동적 메모리(`malloc`, `free`), 형변환, 종료(`exit`) 등 |
| `<string.h>` | 문자열 처리 (`strcpy`, `strlen`, `strcmp`, `strcat` 등) |
| `<math.h>` | 수학 함수 (`sqrt`, `pow`, `fabs`, `sin`, `cos` 등) |
| `<ctype.h>` | 문자 분류/변환 (`isdigit`, `isalpha`, `toupper`, `tolower` 등) |
| `<time.h>` | 시간 관련 (`time`, `clock`, `localtime` 등) |
| `<stdint.h>` | 크기 명확한 정수형 (`int32_t`, `uint8_t` 등) (C99~) |
| `<stdbool.h>` | 불리언 타입 (`bool`, `true`, `false`) (C99~) |
| `<limits.h>` | 자료형 한계값 (`INT_MAX`, `CHAR_MIN` 등) |
| `<errno.h>` | 오류 코드 (`errno`, `ERANGE` 등) |

---

# 20. 전처리와 분할 컴파일

→ 위 '전처리기' 및 '분할 컴파일' 섹션 참조

---

# Appendix

### 진수 표현 요약

- 8비트 최댓값: `1111 1111` = 255 (unsigned), 127 (signed)
- MSB (Most Significant Bit): 최상위 비트, 부호 역할
- LSB (Least Significant Bit): 최하위 비트, 홀/짝 판별

---

### C언어 주요 문자열 처리 함수

```c
#include <string.h>

strlen(s)           // 문자열 길이 (NULL 제외)
strcpy(dst, src)    // 문자열 복사 (버퍼 오버플로 주의)
strncpy(dst, src, n)// 최대 n글자 복사 (안전)
strcat(dst, src)    // 문자열 연결
strncat(dst, src, n)// 최대 n글자 연결 (안전)
strcmp(a, b)        // 문자열 비교 (같으면 0, a>b면 양수, a<b면 음수)
strncmp(a, b, n)    // 최대 n글자 비교
strchr(s, c)        // 문자 c의 첫 번째 위치 포인터 반환
strstr(s, sub)      // 부분 문자열 탐색
strtok(s, delim)    // 구분자로 문자열 분리
```

---

# 실습

```c
// 데이터를 입력받을 때 사용
// 변수 앞에는 꼭 &을 써준다.
scanf("%d", &x);
```

1. 지구 공전 주기 - 1년 365.2422일 → 몇일, 몇 시간, 몇 분, 몇초? (초는 소숫점 두자리)
2. 소수 여부 출력
3. 입력한 정수까지 존재하는 모든 소수 구하기
4. 24, 25, 26, 29

```c
// 실습 1: 지구 공전 주기
#include <stdio.h>

int main() {
    double total_days = 365.2422;
    long long total_seconds = (long long)(total_days * 24 * 60 * 60);

    long long days = total_seconds / (24 * 60 * 60);
    long long hours = (total_seconds % (24 * 60 * 60)) / (60 * 60);
    long long minutes = (total_seconds % (60 * 60)) / 60;
    double seconds = total_days * 24 * 60 * 60 - (long long)(total_days * 24 * 60 * 60 - total_seconds % 60);

    printf("%lld일 %lld시간 %lld분 %.2f초\n", days, hours, minutes,
           (total_days * 86400) - (days * 86400 + hours * 3600 + minutes * 60));
    return 0;
}

// 실습 2: 소수 여부 판별
#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("숫자 입력: ");
    scanf("%d", &n);
    printf("%d는 %s\n", n, isPrime(n) ? "소수" : "소수가 아님");
    return 0;
}

// 실습 3: n 이하 소수 모두 출력
int main() {
    int n;
    printf("최대값 입력: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
```