#include <stdio.h>
#include <stdlib.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 5
#define CCOLS 6

int** getMatrix(int rows, int cols);
void showMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
int ** multiplyMatrix(int **a, int arows, int acols, int **b, int brows, int bcols);

int** getMatrix(int rows, int cols) {
	int** matrix = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 100;  // 0~99 범위의 난수
		}
	}
	return matrix;
}

int** multiply(int** A, int Arows, int Acols, int** B, int Brows, int Bcols) {
	int** result = (int**)malloc(Arows * sizeof(int*)); // int*를 rows 개 만들겠다 → 행마다 하나씩 포인터 배열
	for (int i = 0; i < Arows; i++) {
		result[i] = (int*)malloc(Bcols * sizeof(int)); // 각 행에 대해 Bcols개의 열을 동적 할당
		for (int j = 0; j < Bcols; j++) {
			result[i][j] = 0;
			for (int k = 0; k < Acols; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return result;
}

void showMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main() {
	int seed = 0;
	scanf("%d", &seed);
	srand(seed);
    
	int** A = getMatrix(AROWS,ACOLS);
	int** B = getMatrix(BROWS,BCOLS);
	int** C = getMatrix(CROWS,CCOLS);
	int** D;
	
	D = multiply(multiply(A, AROWS, ACOLS, B, BROWS, BCOLS), AROWS, BCOLS, C, CROWS, CCOLS);
    
	showMatrix(D, AROWS, CCOLS);
	
	freeMatrix(A, AROWS);
	freeMatrix(B, BROWS);
	freeMatrix(C, CROWS);
	freeMatrix(D, AROWS);
	
	return 0;
}
