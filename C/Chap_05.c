#include <stdio.h>

int main(void) {
    char ch;
    unsigned short usX;
    int n[4];

    printf("char 크기 %d\n", sizeof(char));
    printf("ch 크기 %d\n", sizeof(ch));

    printf("short 크기 %d\n", sizeof(short));
    printf("unsigned short 크기 %d\n", sizeof(usX));

    printf("int 크기 %d\n", sizeof(int));
    printf("int array n[4] 크기 %d\n", sizeof(n)); // 배열 n이 4개의 int 타입 요소로 구성

    printf("double 크기 %d\n", sizeof(double));

    return 0;
}


// Floating Point and Comparison Operation
#include <stdio.h>

int main(void)
{
    double x = 0.0;
    int i = 0;

    for (i = 0; i <= 9; i = i + 1)
        x = x + 0.1;

    if (x == 1.0)
        printf("x is 1.0\n");
    else
        printf("x is not 1.0\n"); // 0.1 10번 더하면 1.0 안됨 (부동소수점 문제)

    printf("x = %.20f\n", x);

    for (x = 0.0; x != 1.0; x = x + 0.1)
        printf("x = %.20f\n", x); // 정확한 1.0 안됨 => 무한루프

    return 0;
}


// return 1 if ch is a digit, i.e 0~9
// 0 (0x30) ~ 9 (0x39)
int is_digit (char ch) {
    // return (ch >= 0x30 && ch <= 0x39);
    return (ch >= '0' && ch <= '9');
}

// A(0x41) ~ Z(0x5A), a(0x61) ~ z(0x6A)
int is_alpha(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

/* return 1 if ch is an alpha-numeric character, i.e [A~Z][a~z][1~9] */
int is_alnum(char ch) {
    return (is_alpha(ch) || is_digit(ch));
}

// A(0x41) ~ Z(0x5A)
int is_upper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

// a(0x61) ~ z(0x6A)
int is_lower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}


// String Length
#include <stdio.h>

int main(void)
{
    int i;        // index
    int len;      // length
    char str[] = "Hello 007 ^^\n";

    for(i = 0; str[i]; i = i + 1)
        ;
    len = i; // 널 문자(\0)를 포함하지 않은 실제 길이

    printf("The length of [%s] : %d\n", str, len);

    return 0;
}



// String to Integer
#include <stdio.h>
int main(void) {
    int i; // index
    unsigned int num=0; // number
    char str[]="31415926"; // 정수를 표현한 string을 int로 출력하는 문제
    
    for(i=0;str[i];i=i+1) {
        num = num + str[i] - 0;
    }
    
    printf("[%s] is %d\n",str,num);
    
    return 0;
}


// CSV(Comma Separated Values)
#include <stdio.h>
int main(void)
{
    int i;              
    int num=0, sum=0;  
    char str[]="123,456,789";

    for(i=0;str[i];i++) {
        if (str[i] == ',') {  
            sum += num; // sum에 num을 더하고
            num = 0;  // num 초기화 시킴
        } else {             
            num = num * 10 + (str[i] - '0'); // 10곱해서 자리수 올려주고, str[i]를 '0'으로 아스키코드값이 아닌 
        } // 실제 정수로 만들어서 num * 10과 더해줌
    }
    sum += num;  // 마지막 num은 안더하고 끝났으니 합해주기
    printf("Sum of all values in CSV[%s] : %d\n", str, sum);

    return 0;
}
