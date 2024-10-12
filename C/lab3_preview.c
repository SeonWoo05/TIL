/*
// <Problem 1>
// 함수형으로 변환하기

#include <stdio.h> 
// Complete sum_of_3()
int sum_of_3(int b, int e) {
	int s=0;
	for (int i=b; i<=e; i++) {
		if (i%3==0) s = s + i;
	}
	return s;
}

int main(void) {
	int b, e;

	scanf("%d%d", &b, &e);

	printf("sum == %d\n", sum_of_3(b, e));
	
	return 0;
}


// <problem 2>                      # 다시봐야함
#include <stdio.h> 

int euclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//#define GCD(a,b)	euclidr(a,b)
#define GCD(a,b) euclid(a,b)

int euclidr(int a, int b) {
	if (b > a) return euclidr(b, a);
	if (b == 0) return a;
	return euclidr(b, a % b);
}

int LCM(int a,int b) {
	return (a * b) / GCD(a,b);
}

int isCoprime(int a, int b) {
	if (GCD(a,b) == 1) return 1;
    else return 0;
}

int main(void) {
	int a, b;
	printf("Enter two positive integers\n");
	scanf("%d%d", &a, &b);
	printf("GCD of (%d, %d) is %d\n", a, b, GCD(a, b));
	printf("LCM of (%d, %d) is %d\n", a, b, LCM(a, b));
	printf("(%d, %d) is co-prime (True-1 / False-0) : %d\n", a, b, isCoprime(a, b));
	return 0;
}


// <problem 3>
#include <stdio.h> 

int count_digits(int n) {
    int cnt = 0;

    if (n == 0) return 1; // 입력값 0일 때 처리

    while (n > 0) {
        n = n / 10;
        cnt += 1;
    }

    return cnt;
}

int sum_digits(int n) {
    int sum = 0;
    
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int analyze_digits(int n) {
    return count_digits(n) + sum_digits(n);
}

int main() {
	int num=0;
	
	scanf("%d",&num);
	printf("Result: %d",analyze_digits(num));
	
	return 0;
}


// <problem 4>
#include <stdio.h>

int is_optimized_prime(int n);

int main(void)
{
    int a;
    scanf("%d", &a);
    if (is_optimized_prime(a))
        printf("a prime\n");
    else
        printf("not a prime\n");
    return 0;
}

int is_optimized_prime(int n) 
{
    if (n < 2) return 0;
    if (n == 2 || n == 3 || n == 5) return 1;
    
    if (n % 2 == 0 || n % 5 == 0) return 0;
    
    int sum = 0;
    int nd = n;

    while (nd > 0) {
        sum += nd % 10;
        nd /= 10;
    }
    if (sum % 3 == 0) return 0;

    for (int i=5; i*i<=n; i+=6) {
        if (n % i == 0 || n % (i + 2) == 0)  return 0;
    }

    return 1;
}
*/

// <problem 5>
#include <stdio.h> 

void hanoi_tower(int n, int ox, int tx, int mx) {
	if (n < 1) {
		printf("Error: n >= 1\n");
	}
	else if (n == 1) {
		printf("%d -> %d\n", ox, tx);
	}
	else {
		hanoi_tower(n-1,ox,mx,tx);
        printf("%d -> %d\n", ox, tx);
        hanoi_tower(n-1,mx,tx,ox);
	}
}

int main(void) {
	int n;

	printf("Enter the height of the tower :\n");
	scanf("%d", &n);
	hanoi_tower(n, 1, 3, 2);

	return 0;
}