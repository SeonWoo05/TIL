// 2장-3 array_pointer.cpp
#include <stdio.h>
#include <stdlib.h>
//submit the debugged code
//break piont 설정 / 해제 - F9
void main(){
	int n = 0;
	n = 3;//lvalue로 사용됨 - ++ 연산은 expression,n은 lvalue
	//n++ = 3;//++ 연산은 lvalue가 아니다

	printf("%d\n\n", n);
	//char *p;//scanf("%s", p) 사용시에 p가 초기화되지 않아 사용되어 오류
	char p[10];
	//scanf("%s", p);
	/*
	int data[4] = { 1,2,3,4 };
	int *ap1 = data[1]; int(*ap2)[4];  ap2 = data; int*ap3 = *(data + 2);
	ap1++; ap2++; ap3++;
	printf("%d, %d, %d", *ap1, **ap2, *ap3);
	*/
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int *b; b = a[2]; // 3*4로 나뉜 세번째 행의 첫번째 원소 가리킴
	printf("*(++b)) = %d, ", *(++b)); printf("*(++b)) = %d\n\n", *(++b)); // 마지막 원소 4개 안에서 ++ 이니까 10, 11

	int *A[3];
	int B[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (*Q)[4];//pointer to array
	//B[][] 대신에 *[], (*)[]을 사용하여 동등하게 처리
	A[0] = B[0]; // 포인터 배열이니까 각 행의 첫 원소를 가리키는 포인터 저장
	A[1] = B[1];
	A[2] = B[2];
	Q=B; // 4개 짜리 int를 원소로 하는 배열에 대한 포인터. B의 첫 행을 가리키고 다음은 B의 두번째 행
	/*
	A = B;//A는 배열 이름 상수로서 lvalue가 아니다.
	*Q = B; // *Q도 배열 이름 상수로서 lvalue가 아니다.
	*Q = B[0]; // *Q도 배열 이름 상수로서 lvalue가 아니다.
	*/
	printf("**B = %d, *B[0] = %d, (*B+1)[0] = %d, *(B+1)[0] = %d\n", **B, *B[0], (*B+1)[0], *(B+1)[0]); // (*B+1)[0] == (B[0]+1)[0]
	printf("**A = %d, *A[0] = %d, (*A+1)[1] = %d\n",**A, *A[0], (*A+1)[1]);
	// 2차원 배열 변수, array of pointers, pointer to array가 동일하게 사용됨
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{

			printf("B[%d][%d]: %d  ",i,j,B[i][j]);
			printf("**A[%d][%d]: %d  ",i,j,A[i][j]);
			printf("Q[%d][%d]: %d\n",i,j,Q[i][j]);
		}
	}
	printf("\n\n");
}