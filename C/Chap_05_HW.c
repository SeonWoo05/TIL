// // Problem 11
// #include <stdio.h> 
// int main(void)
// {
// 	int a=3, b, c, d;

// 	b = a++; // b에 a를 대입한 후에 a++ => a=4, b=3
// 	c = ++b; // b에 1을 더한 후 c에 대입 => b=4, c=4
// 	d = --c; // c에 1을 뺀 후 d에 대입 => c=3, d=3
// 	printf("%d,%d,%d,%d\n", a, b, c, d--); // 4,4,3,3 을 출력한 후 d=2

// 	return 0;
// }

// // Problem 12
// #include <stdio.h> 

// void print(int n) {
// 	printf("%d\n",n);
// }

// int main(void) {
// 	int a=3;
	
// 	print(a++);
// 	print(++a);
// 	print(a++);
// 	print(++a);
	
// 	return 0;	
// }

// Problem 13 레전드;
#include <stdio.h> 
int main(void)
{
	int nx = 0x85857A7A; // 2진수로 바꾸면, 16진수 한자리는 2진수 4자리
	int mask = 0xFFFF0000;
	// 일단 8과 7, 5와 A는 2진수 표현에서 반대
	// 16진수 FFFF = 11111111 11111111

	printf("nx = 0x%08X\n", nx);
	printf("mask = 0x%08X\n", mask);

	printf("~nx = 0x%08X\n", ~nx);	// NOT
	// not 연산하면 8은 7로, 5는 A로,... 

	printf("nx&mask = 0x%08X\n", nx&mask); // AND
	// and 연산하면 FFFF가 있는 상위 16비트만 살아남음

	printf("nx|mask = 0x%08X\n", nx|mask); // OR
	// or 연산하면 FFFF는 그대로 FFFF 다음 7A7A 이어짐

	printf("nx^mask = 0x%08X\n", nx^mask); // XOR
	// 상위 16비트는 mask가 전부 1이므로 and 연산(같은거만 1로 남기고) 후에 not을 붙이면 됨
	// 하위 16비트는 .. 0이므로 or 연산
	return 0;
}