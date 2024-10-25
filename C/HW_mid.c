// HW2 (3)
#include <stdio.h>
int main(void) {
	printf("12345678\n\"12345678\"\n	12345678");
	return 0;
}

// HW2 (7)
#include <stdio.h>
int main(void) {
	float result;
	
	result = 7.0/2.0;

	printf("result = %f", result);

	return 0;
}

// HW2 (8)
#include <stdio.h>

int main(void) {
	float num=123.456;
	int 	n=0;
	float	f=0;
	
	n = num;
	f = num-n;
	
	printf("Integral Part = %d\n", n);
	printf("Fractional Part = %.3f\n", f);

	return 0;
}

// HW3 (5)
#include <stdio.h> 

int main(void)
{
	int y;

	scanf("%d",&y);
	if( y%4==0 && !(y%100==0 && y%400!=0)) 
		printf("leap\n");
	else
		printf("not leap\n");

	return 0;
}

// HW3 (6)
#include <stdio.h>

int main(void) {
	int a;

	for (a=15;a>0;a=a-(a%3+1)) {
		printf("%d\n", a);
	}

	return 0;
}
	
// HW3 (7)
#include <stdio.h> 

int main(void) {
	int n1,n2,j,i;

	for (j=0; j<3; j=j+1) {
		n1 = 3 - j;
		n2 = j + 1;
		for(i=0;i<n1;i=i+1) printf(".");
			for(i=0;i<n2;i=i+1) printf("*");
				printf("\n");
	}
	return 0;
}

// HW3 (8)
#include <stdio.h> 

int main(void) {
	int i,j;
	int n1,n2,n3;

	for(j=0; j<10 ; j=j+1) {
		n1 = 9 - j;
		n2 = j + (j / 2) + 1;
		n3 = 9 - (j / 2);
		for(i=0;i<n1;i=i+1) printf(". ");
		for(i=0;i<n2;i=i+1) printf("* ");
		for(i=0;i<n3;i=i+1) printf(". ");
		printf("\n");
	}
	for(j=0; j<9 ; j=j+1) {
		n1 = 2 * (j + 1);
		n2 = 13 - j - ((j+1)/2);
		n3 = 4 - (j / 2);
		for(i=0;i<n1;i=i+1) printf(". ");
		for(i=0;i<n2;i=i+1) printf("* ");
		for(i=0;i<n3;i=i+1) printf(". ");
		printf("\n");
	}
	return 0;
}

// HW3 (9)
#include <stdio.h> 

int main(void) {
	int i;			// index
	int ecnt = 0;	// even number count
	int a[10] = {3,7,8,9,2,3,4,6,1,7};
	{// This block is added for automatic scoring. 
		int option;
		int a2[] = {1,3,5,7,9,1,3,5,7,9};
		int a3[] = {1,3,7,9,9,3,1,7,1,2};
	
		scanf("%d", &option);
		if (option == 2) memcpy(a, a2, sizeof(a));
		else if (option == 3) memcpy(a, a3, sizeof(a));
	}

	for(i = 0; i < 10 ; i = i+1) {
		if (a[i] % 2 == 0)
			ecnt++;
	}
	printf("There are %d even numbers in a[10]\n", ecnt);

	return 0;
}

// HW4 (1)
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

// HW4 (3)
#include <stdio.h>

// Put function arguments
void line(int j) {
	int n1, n2, n3, n4;
	
	if (j<10) {
		n1 = 9 - j;
		n2 = 2 * j + 1;
		n3 = 9 - j;
		n4 = 0;
	}
	else {
		n1 = 0;
		n2 = j - 9;
		n3 = 2 * (19 - j) - 1;
		n4 = j - 9;
	}
	int i;

	for(i=0; i<n1; i=i+1) printf(". ");  
	for(i=0; i<n2; i=i+1) printf("* ");  
	for(i=0; i<n3; i=i+1) printf(". ");  
	for(i=0; i<n4; i=i+1) printf("* ");  
	printf("\n");
}

int main(void) {
	int j;

	for(j=0; j<10; j=j+1)
		line(j);
	for(j=0; j<9; j=j+1)
		line(j+10);
	return 0;
}

// HW5 (1)
#include <stdio.h>
int main(void) {
	int input_values;
	int n_hours, n_minutes, n_seconds;
	
	scanf("%d", &input_values);
	
	int tmp = input_values;	

	n_hours = tmp / 3600;
	tmp %= 3600;
	
	n_minutes = tmp / 60;
	tmp %= 60;
	
	n_seconds = tmp;
	
	printf("%d seconds is equivalent to %d hours, %d minutes and %d seconds\n", input_values, n_hours, n_minutes, n_seconds);
	return 0;
}


// HW5 (3)
#include <stdio.h> 

int is_alpha(char ch) {
	if (ch >= 'A' && ch <= 'z') return 1;
	else return 0;
}

int is_upper(char ch) {
	if (ch >= 'A' && ch <= 'Z') return 1;
	else return 0;
}
int main(void) {
	char ch;

	scanf("%c", &ch);
	printf("%c is ", ch);
	if (is_alpha(ch)) {
		if (is_upper(ch))
			printf("an uppercase alphabetic character\n");
		else
			printf("a lowercase alphabetic character\n");
	}
	else
		printf("is not an alphabetic character\n");

	return 0;
}

// HW5 (4)
#include <stdio.h>
int main(void) {
	char msg[] = "^^ \tThis is a Test Message 2022 !!\n Thank You !!!";
	int i;
	
	printf("%s\n", msg);
	
	for (i=0; msg[i] != '\0'; i++) {
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			msg[i] = msg[i] - ' ';
		}
	}
	
	printf("%s\n", msg);
	return 0;
}

// HW5 (5) 문자열을 숫자로
#include <stdio.h>

int main(void)
{
	char str[11];
	unsigned int num=0;	// number
	int i; // index

	scanf("%s",str);

	for(i=0; str[i]; i++) {
		num = (10 * num) + (str[i] - '0');
	}

	printf("[%s] is %d\n",str,num);
	
	return 0;
}

// HW5 (6)
#include <stdio.h>

#define INT_BITS 32

void print_binary(unsigned int n) {
	for (int i=INT_BITS-1; i>=0; i--) { // 31부터 시작
		int mask = 1 << i; // 비트 쉬프트 연산 : << 은 1을 오른쪽으로 i 만큼 = X 2의 i승 이라 할 수 있음
		if (n & mask) printf("1"); // 비트 & 연산 : & 는 같으면 1반환
		else printf("0");
	}
}

int main(void) {
	unsigned int num;
	
	scanf("%d", &num);
	print_binary(num);
	
	return 0;
}

// HW5 (7)
#include <stdio.h> 
int main(void)
{
	int i;		// index

	unsigned int num=0;	// number
	unsigned int nd, len;
	char str[11];       // Max Digits + 1
	char rstr[11];      // Max Digits + 1

	scanf("%d",&num);
 
	for (i=0, nd=num; nd>0; i+=1,nd=nd/10) {
		rstr[i] = nd % 10 + '0';
	}

	len = i;

	for (i=0; i<len; i++) {
		str[i] = rstr[len-1-i];
	}

	str[i] = '\0';
	printf("%d is [%s]\n",num, str);
	return 0;
}
