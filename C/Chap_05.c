/*
#include <stdio.h>
int main(void)
{
    char c1 = 'A';  // char 로 선언
    int c2;
    printf("%c\n", c1);

    c1 = 65; // c1 은 char
    printf("%c\n", c1);

    c1 = 0x41;
    printf("%c\n", c1);

    c2 = 'A'; // c2 는 int
    printf("%c, %d\n", c1, c1); // 출력 형식 지정
    printf("%c, %d\n", c2, c2);
    return 0;
}


#include <stdio.h>
int main(void)
{
    char ch; // use char type
    scanf("%c", &ch); // 문자에 해당하는 문자코드값(정수)를 변수에 저장
    printf("%c\n", ch);
    printf("%d\n", ch);
    return 0;
}


#include <stdio.h>

int is_digit (char ch) {
    return (ch >= 0x30 && ch <= 0x39);
}

int main(void) {
    int i;          // index
    int sum = 0;    // digit sum
    char str[] = "b234,56a,1";

    for (i = 0; str[i]; i = i + 1) {
        if (is_digit(str[i]))
            sum = sum + (str[i] - '0');  // 여기에서 문자를 숫자로 변환
    }

    printf("Sum of all digits in");
    printf(" [%s] : %d\n", str, sum);

    return 0;
}
*/

