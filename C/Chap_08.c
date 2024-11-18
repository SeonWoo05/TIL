// // P.14
// #include <stdio.h>

// int main(void)
// {
//     int nx = 36;
//     int ny = 0;
//     int* pn = &nx;

//     printf("ADDR:%p\n", &nx);
//     printf("ADDR:%p\n", &ny);
//     printf("ADDR:%p\n", pn);
//     printf("Size %d\n", sizeof(pn));
//     printf("ADDR:%p\n",&pn);

//     ny = *pn;
//     *pn = ny + 1;
//     nx = *pn + *(&ny);

//     printf("%d, %d, %d\n", nx, ny, *pn);

//     return 0;
// }


// // P.21
// #include <stdio.h>

// int sum_product(int a, int b, int *sum, int *prod)
// {
//     *sum = a + b;
//     *prod = a * b;
//     return 1;
// }

// int main(void)
// {
//     int a = 3, b = 7, sum = 0, prod = 0;

//     sum_product(a, b, &sum, &prod);

//     printf("a+b=%d, a*b=%d\n", sum, prod);

//     return 0;
// }


// // P.25
// #include <stdio.h>

// int main(void)
// {
//     int a = 1, *pa = &a;

//     printf("a: %d, pa: %p\n", a, pa);
//     ++*pa; // ++*pa *pa 는 a의 값. a값에 ++
//     printf("a: %d, pa: %p\n", a, pa);
//     *pa++; // *pa, pa++; pa 주소에 ++
//     printf("a: %d, pa: %p\n", a, pa);
//     a += *--pa; // 원래 a를 가리키던 주소로 되돌리고 그때의 값 = a => a+a
//     printf("a: %d, pa: %p\n", a, pa);

//     return 0;
// }


// // P_29
// // 첨자가 아닌 포인터를 이용하여 CSV 문자열을 순회하도록 수정하라
// #include <stdio.h>

// int main(void)
// {
//     char *pstr;          // pointer
//     int num = 0, sum = 0; // number
//     char str[] = "123,456,789";

//     for (pstr = str; *pstr; pstr++) {
//         if (*pstr == ',') {  // new num
//             sum += num;
//             num = 0;
//         } else {             // a digit
//             num = num * 10 + (*pstr - '0');
//         }
//     }
//     sum += num;

//     printf("Sum of all values in ");
//     printf("CSV[%s] : %d\n", str, sum);

//     return 0;
// }


// // P_31
// #include <stdio.h>
// #define END_MARK -1

// int sum_w_endmark2(int nums[])
// {
//     int i = 0, sum = 0;
//     while (nums[i] != END_MARK) {
//         sum += nums[i];
//         nums[i++] = END_MARK;
//     }
//     return sum;
// }

// int main(void)
// {
//     int array1[4] = {1, 2, 3, END_MARK};
//     int s1;

//     printf("Array1 [%d, %d, %d]\n", array1[0], array1[1], array1[2]);

//     s1 = sum_w_endmark2(array1);

//     printf("Array1 [%d, %d, %d]\n", array1[0], array1[1], array1[2]);

//     printf("Sum of Array1: %d\n", s1);

//     return 0;
// }


// // P_34 mystrcpy()
// #include <stdio.h>

// void mystrcpy(char dest[], char src[]) {
//     int i = 0, j = 0;
//     while (src[i]) {
//         dest[j++] = src[i++];
//     }
//     dest[j] = '\0';
// }

// void mystrcpy2(char *dest, char *src) {
//     while (*src) {
//         *dest++ = *src++; // 포인터가 가리키는 주소의 값을 저장하고
//     } // 포인터에 ++ (배열의 다음주소)
//     *dest = '\0'; // 마지막은 알아서 채워줘야함
// }

// int main(void) {
//     char mystr1[256];
//     char mystr2[256];
//     char mystr3[256];

//     gets(mystr1);

//     mystrcpy(mystr2, mystr1);
//     puts(mystr2);

//     mystrcpy2(mystr3, mystr1);
//     puts(mystr3);

//     return 0;
// }


// // P_37
// #include <stdio.h>

// int mystrcmp(char *lhs, char *rhs)
// {
//     while (*lhs && (*lhs == *rhs)) {
//         lhs++;
//         rhs++;
//     }
//     return *lhs - *rhs;
// }

// int main(void)
// {
//     char mystr1[256];
//     char mystr2[256];
//     gets(mystr1);
//     gets(mystr2);

//     if (mystrcmp(mystr1, mystr2) == 0)
//         puts("2 strings are equal");
//     else
//         puts("2 strings are different");

//     return 0;
// }


// P_38
#include <stdio.h>
#include <string.h>

int ispalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main(void)
{
    char buffer[1024];
    gets(buffer);
    printf("[%s] is ", buffer);
    if (ispalindrome(buffer))
        puts("a palindrome");
    else
        puts("not a palindrome");
    return 0;
}


// // P_39
// #include <ctype.h>
// #include <stdio.h>

// int main() {
//     char ch = 'A';
//     if (isalnum(ch)) {
//         printf("%c is alphanumeric.\n", ch);
//     } else {
//         printf("%c is not alphanumeric.\n", ch);
//     }
//     return 0;
// }
