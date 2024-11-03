// switch 문 기본형식

// case 뒤의 수식은 반드시 constant expression
// 변수가 포함되면 안됨 => 상수로 선언한 상수는 가능
#include<stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    switch(a) {
        case 1:
            printf("a==one\n");
            break;
        case 2:
            printf("a==two\n");
            break;
        case 3:
            printf("a==three\n");
            break;
        case 4:
            printf("a==four\n");
            break;
        case 5:
            printf("a==five\n");
            break;
        default:
            printf("a==other\n");
    }
    return 0;
}

// do-while 문 기본형식

// 코드 블록을 먼저 한 번 실행한 후에 조건을 검사
// 따라서 조건이 처음에 거짓이더라도 코드 블록은 최소 한 번 실행됨

#include <stdio.h>

int main(void) {
    int i = 3;

    do {
        printf("i=%d\n", i++);
    } while (i < 3);

    printf("after loop\n");

    return 0;
}

// break 문

// 반복문 실행 중단 (다음 i로 가는거 아님)
// break 문은 가장 가까운 반복문만을 탈출
#include<stdio.h>

int main(void) {
    int i;
    for(i=0; i<100; i=i+1) {
        printf("i=");
        if(i==5)
            break;
        printf("%d\n",i);
    }
    printf("\n");

    return 0;
}

// 0이 입력될 때까지 사용자로부터 정수를 입력밭는 프로그램
// 0을 제외하고 입력 받은 정수 출력
#include <stdio.h>

int main(void) {
    int n_c;

    do {
        scanf("%d", &n_c);
        if (n_c == 0) break;
        printf("%d\n", n_c);
    } while (1);
}

// [확장] 1,2,3인 경우 각각 "case 1", "case 2", "case 3"를 출력하고
// 그 외 경우 "default" 라는 문자열을 출력
#include <stdio.h>

int main(void) {
    int n_c;

    do {
        scanf("%d", &n_c);

        if (n_c == 0) break;

        switch (n_c) {
            case 1:
                printf("case 1\n");
                break;
            case 2:
                printf("case 2\n");
                break;
            case 3:
                printf("case 3\n");
                break;
            default:
                printf("default\n");
        }
    } while (1);
}

// Currency Converter

#include <stdio.h>

void print_menu(void)
{
    char szmenu1[] = "[1] Set the base KRW-USD exchange rate";
    char szmenu2[] = "[2] Convert [KRW] to [USD]";
    char szmenu3[] = "[3] Convert [USD] to [KRW]";
    char szmenu0[] = "[0] Exit Program";
    char szchoice[] = "Enter your choice : ";

    printf("%s\n%s\n%s\n%s\n%s", szmenu1, szmenu2, szmenu3, szmenu0, szchoice);
}

int main(void)
{
    double in, out;
    int nchoice;
    int baserate = 1000;

    do
    {
        print_menu();
        scanf("%d", &nchoice);
        if (nchoice == 0)
            break;

        switch (nchoice) {
            case 1:
                printf("Current base exchange rate : %d\n", baserate);
                printf("Enter the new base rate : ");
                scanf("%d", &baserate);
                break;

            case 2:
                printf("Enter the amount of KRW : ");
                scanf("%lf", &in);
                out = in / baserate;
                printf("%.0f(KRW) == %f(USD)\n", in, out);
                break;        
        
            case 3:
                printf("Enter the amount of USD : ");
                scanf("%lf", &in);
                out = in * baserate;
                printf("%f(USD) == %.0f(KRW)\n", in, out);
                break;
        
            default:
                printf("wrong choice !\n");
        }

    } while (1);

    printf("bye bye\n");
    return 0;
}


// 다차원 배열

// 2차원 배열 Example - Matrix
#include <stdio.h>
#define NSIZE 3

void printNxN(int m[NSIZE][NSIZE]) {
    int i, j;
    char lineseg[8] = "-------";

    printf("+");
    for (i = 0; i < NSIZE; i++) printf("%s", lineseg);
    printf("+\n");

    for (i = 0; i < NSIZE; i++) {
        printf("|");
        for (j = 0; j < NSIZE; j++)
            printf("%6d", m[i][j]);
        printf("|\n");
    }

    printf("+");
    for (i = 0; i < NSIZE; i++) printf("%s", lineseg);
    printf("+\n");
}

int main(void) {
    int A[NSIZE][NSIZE] = { {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9} };

    printNxN(A);

    return 0;
}


// B = A + 1
// C = A * B
// D = C^Tc
#include <stdio.h>

#define NSIZE 3
void printNxN(int m[NSIZE][NSIZE]);

int main(void)
{
    int A[NSIZE][NSIZE] = { {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9} };

    int B[NSIZE][NSIZE];
    int C[NSIZE][NSIZE];
    int D[NSIZE][NSIZE];

    for (int i=0; i<NSIZE; i++) {
        for (int j=0; j<NSIZE; j++) {
            B[i][j] = A[i][j] + 1;
        }
    }
    printNxN(B);

    for (int i=0; i<NSIZE; i++) {
        for (int j=0; j<NSIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
    printNxN(C);

    for (int i=0; i<NSIZE; i++) {
        for (int j=0; j<NSIZE; j++) {
            D[i][j] = C[j][i];
        }
    }
    printNxN(D);

    return 0;
}

void printNxN(int m[NSIZE][NSIZE])
{
    for (int i = 0; i < NSIZE; i++) {
        for (int j = 0; j < NSIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}


// A 전치 **
#include <stdio.h>
#define NSIZE 3
void printNxN(int m[NSIZE][NSIZE]);

int main(void)
{
    int A[NSIZE][NSIZE] = { {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9} };

    int i, j, k;

    for (i=0; i<NSIZE; i++) {
        for (j=i+1; j<NSIZE; j++) { // j = i+1부터 => 중복없애고, 같은원소 두번바꾸는거 방지
            k = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = k;
        }
    }
    
    printNxN(A);
    
    return 0;
}