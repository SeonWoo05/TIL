// Recursive Function Call

/*
// Factorial
#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d", factorial(n));

    return 0;
}


// Fibonacci Sequence
#include <stdio.h>

int fibo(int n) {
    if (n==0) return 0;    
    if (n==1) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d", fibo(n));

    return 0;
}


// Hanoi Tower
#include <stdio.h>

void hanoi_tower(int n, int ox, int tx, int mx)
{
    if (n < 1)
        printf("Error: n >= 1\n");
    else if (n == 1)
        printf("%d -> %d\n", ox, tx);
    else
    {
        // n-1개의 원반을 출발 기둥(ox)에서 중간 기둥(mx)으로 이동
        hanoi_tower(n - 1, ox, mx, tx);
        // 가장 큰 원반을 출발 기둥(ox)에서 목표 기둥(tx)으로 이동
        printf("%d -> %d\n", ox, tx);
        // n-1개의 원반을 중간 기둥(mx)에서 목표 기둥(tx)으로 이동
        hanoi_tower(n - 1, mx, tx, ox);
    }
}

int main(void)
{
    int n, ox, tx, mx;
    printf("Enter the height of the tower\n");
    scanf("%d %d %d %d", &n, &ox, &tx, &mx);
    hanoi_tower(n, ox, tx, mx);
    return 0;
}


// 지역 변수 유효 범위
#include <stdio.h>

int foo(int n);

int main(void) {
    int a;
    int b = 3;

    a = 3;
    b = a * b;
    {
        int c;

        c = a - b;
        b = c * 3;
    }
    printf("%d\n", c); // c 유효 범위가 끝나서 오류남
    return 0;
}


// 변수충돌
#include <stdio.h>

int gSum;
// foo2 호출 => gSum은 1
// foo1 호출 => gSum은 2, nx는 3
int foo1(int n) {
    gSum = gSum + n;
    return (gSum + 1);
}

int foo2(int n) {
    int gSum = n;
    return (gSum + 1);
}

int main(void) {
    int nx;
    gSum = 0;
    nx = foo1(foo2(1));
    printf("nx=%d,gSum=%d\n", nx, gSum);
    return 0;
}
*/

// // Prime Number
// #include <stdio.h>
// #include <math.h>

// int isprime(int n) {
//     if (n == 1) return 0;
//     for(int i=2; i<=sqrt(n)+1; i++) {
//         if (!(n%i)) return 0;
//     }
//     return 1;
// }

// int main(void) {
//     int a;
//     scanf("%d", &a);
//     if (isprime(a))
//         printf("a prime\n");
//     else
//         printf("not a prime\n");
//     return 0;
// }


// // Greatest Common Divisor (최대공약수)
// // + GCD를 이용하여 LCM, isCoprime 구현
// #include <stdio.h>
// int GCD(int a, int b) {
//     int nd = a;
//     if (nd < b) nd = b;
//     for (; nd>=1; nd=nd-1)
//         if (a%nd == 0 && b%nd == 0) break;
//     return nd;
// }

// int LCM(int a, int b) {
//     int nd = GCD(a,b);
//     return (a/nd) * (b/nd) * nd;
// }

// int isCoprime(int a, int b) {
//     if (GCD(a,b) == 1) return 1;
//     else return 0;
// }

// int main(void) {
//     int a, b;
//     printf("Enter two positive integers\n");
//     scanf("%d%d", &a, &b);
//     printf("GCD of (%d,%d) is %d\n",
//            a, b, GCD(a, b));
//     printf("LCM of (%d,%d) is %d\n",
//            a, b, LCM(a, b));
//     printf("(%d,%d) isCoprime? %d\n",
//            a, b, isCoprime(a, b));
//     return 0;
// }


// Euclidean Algorithm
// 1. Recursive Function 형태로
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

// 2. Non Recursive
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}