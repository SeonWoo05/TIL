// 03. 제어구조기초  


// #include <stdio.h>

// int main(void) {
//     int i; // index
//     int a[10]={3,7,8,9,2,3,4,6,1,7};
    
//     for(i=9; i>-1; i--) {
//         if (!(a[i]%2)) {
//             printf("Found:a[%d]=%d\n", i, a[i]);
//             break;
//         }
//     }
    
//     if (i==-1) {
//         printf("No even number\n");
//     }
//     return 0;
// }


// #include <stdio.h>

// int main(void) {
//     int n, n_d, sum=0;
    
//     printf("Enter a positive integer\n");
    
//     scanf("%d", &n);
//     if (n <= 0) return 1;
//     for (n_d=n; n_d>0; n_d/=10) { // 한자리수가 되면 ex) int라서 3/10 = 0 => 종료
//         sum = sum + (n_d % 10);
//     }
//     printf("Sum of all digits of %d=%d\n", n, sum);
//     return 0; 
// }


// #include <stdio.h> 
// int main(void)
// {
//  	int a = 2, b = 3, c = 0;

// 	printf("%d\n", a!=b);	// 1
// 	printf("%d\n", !a);	// 2
// 	printf("%d\n", b||c);	// 3
// 	printf("%d\n", a&&b);	// 4

// 	return 0;
// }


// #include <stdio.h>
// int main(void) {
//     int nPulseRate;
//     printf("맥박수를입력하세요:");
//     scanf("%d", &nPulseRate);
//     if (nPulseRate >= 60 && nPulseRate <= 90)
//         printf("\n정상범위입니다.\n");
//     if (nPulseRate <= 90 && nPulseRate >= 60)
//         printf("\n 정상범위입니다.\n");
//     if (nPulseRate < 60 || nPulseRate > 90)
//         printf("\n 정상범위입니다.\n");
//     if (nPulseRate > 90 || nPulseRate < 60)
//         printf("\n 정상범위입니다.\n");
//     if (60 <= nPulseRate <= 90)
//         printf("\n 정상범위입니다.\n");
//         // C 언어에서는 <= 연산이 순차적으로 평가 X
//         // 즉, (60 <= nPulseRate)는 1 또는 0의 값이 되는데,
//         // 이 값이 다시 <= 90과 비교됨 => 논리적 오류
//     return 0;
// }


// #include <stdio.h> 
// int main(void)
// {
// 	int n1, n2, n3;
// 	int nx=0, ny=0;

// 	printf(" Enter three integers : ");
// 	scanf("%d %d %d", &n1, &n2, &n3);

// 	if (n1 < n2)
// 		if (n1 < n3) nx = n1;
// 	else nx = n3;

// 	if (n1 < n2) {
// 		if (n1 < n3) ny = n1;
// 	}
// 	else ny = n3;

// 	printf("nx=%d, ny=%d\n", nx, ny);

//         return 0;
// }


// #include <stdio.h> 
// int main(void)
// {
// 	int n1, n2, n3;
// 	int nx=0, ny=0;

// 	printf(" Enter three integers : ");
// 	scanf("%d %d %d", &n1, &n2, &n3);

// 	if (n1 < n2) // 이 if에 대한 else문은 없음
// 		if (n1 < n3) nx = n1; // 이 상황인거임
// 		else nx = n3;

// 	if (n1 < n2) {
// 		if (n1 < n3) ny = n1;
// 	}
// 	else ny = n3;

// 	printf("nx=%d, ny=%d\n", nx, ny);

//         return 0;
// }


// #include <stdio.h> 
// int main(void)
// {
// 	int i, j, k;
// 	int n=0;
	
// 	for (i=1; i<10; i=i+1) 
// 		for (j=1; j<10; j=j+1)
// 			for (k=1; k<10; k=k+1) 
// 				n=n+1;

// 	printf("n=%d\n",n);		// 1

// 	n=0;
// 	for (i=1; i<10; i=i+1) 
// 		for (j=i; j<10; j=j+1)
// 			for (k=j; k<10; k=k+1) 
// 				n=n+1;
// 	// n=45+36+28+21+15+10+6+3+1=165
	
// 	printf("n=%d\n",n);		// 2

//     return 0;
// }


// #include <stdio.h> 
// int main(void)
// {
//     int i;
//     // int a[3]={2,9}; // 나머지 자동 0으로 초기화
// 	// int a[3]={0,}; // 허용된 초기화 방식, 나머지 0
// 	// int a[3]={2,9,8};
// 	// int a[]; // 배열을 선언할 때 크기를 지정 or 초기화 리스트를 사용해야 함
// 	// int a[3]={2,9,8,7}; // 배열 크기보다 더 많은 값 => 컴파일 에러가 발생

//     for(i=0; i<3; i=i+1) {
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }

// #include <stdio.h> 
// int main(void)
// {
//     int i;
//     int a[3]={2,9,8};

//     for(i=0; i<=3; i=i+1) { // Run-Time Error
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }


// HW2 - 5 (윤년)
// 연도가 4로 나누어떨어져야 함.
// 연도가 100으로 나누어떨어지는 경우, 400으로도 나누어떨어져야 함.
// if ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) )
// if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))


// // HW2 - 8 (별찍기)
// #include <stdio.h>

// int main(void) {
//     int i, j;
//     int n1, n2, n3;

//     // 첫 번째 삼각형 부분 (점점 별이 늘어나는 부분)
//     for (j = 0; j < 10; j = j + 1) {  // 10번 반복 (0부터 9까지)

//         n1 = 9 - j;  // 왼쪽의 점(`.`) 개수는 9에서 시작해 j가 증가할 때마다 1씩 줄어듦
//         n2 = j + (j / 2) + 1;  // 별(`*`)의 개수는 j가 짝수일 때 2개, 홀수일 때 1개씩 늘어남
//         n3 = 9 - (j / 2);  // 오른쪽의 점(`.`) 개수는 j가 짝수일 때마다 1씩 줄어듦

//         for (i = 0; i < n1; i = i + 1) printf(". ");
//         for (i = 0; i < n2; i = i + 1) printf("* ");
//         for (i = 0; i < n3; i = i + 1) printf(". ");
//         printf("\n");
//     }

//     // 두 번째 삼각형 부분 (점점 별이 줄어드는 부분)
//     for (j = 0; j < 9; j = j + 1) {  // 9번 반복 (0부터 8까지)

//         n1 = 2 * (j + 1);  // 왼쪽의 점(`.`) 개수는 2배씩 증가
//         n2 = 13 - j - ((j + 1) / 2);  // 별(`*`)의 개수는 j가 홀수일 때 2개씩 줄고, 짝수일 때는 1개씩 줄어듦
//         n3 = 4 - (j / 2);  // 오른쪽의 점(`.`) 개수는 짝수마다 1씩 줄어듦

//         for (i = 0; i < n1; i = i + 1) printf(". ");        
//         for (i = 0; i < n2; i = i + 1) printf("* ");
//         for (i = 0; i < n3; i = i + 1) printf(". ");
//         printf("\n");
//     }

//     return 0;
// }