#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5

int * getMatrix(int rows, int cols);
void showMatrix(int* matrix, int rows, int cols);

int* transposeMatrix(int *b, int rows, int cols);
int* multiplyTransposeMatrix(int *a, int rows_a, int cols_a, int *b, int rows_b, int cols_b);

int main() {
	int seed = 0;
    scanf("%d", &seed);
    srand(seed);

    int *a = getMatrix(AROWS, ACOLS);
    int *b = getMatrix(BROWS, BCOLS);
 

    int* transResult = transposeMatrix((int*)b, BROWS, BCOLS);
    
    int* product = multiplyTransposeMatrix((int*)a, AROWS, ACOLS, transResult, BCOLS, BROWS);
    printf("Matrix product = (A * transpose(B)):\n");
    showMatrix(product, AROWS, BCOLS);

	free(a);
    free(b);
    free(product);
    free(transResult);

    return 0;
}

int * getMatrix(int rows, int cols) {
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = rand() % 100;  // 0-99 사이의 랜덤 값 생성
        }
    }
    
    return matrix;
}

void showMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int* transposeMatrix(int *b, int rows, int cols) {
    int *transpose = (int *)malloc(cols * rows * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j * rows + i] = b[i * cols + j];
        }
    }
    
    return transpose;
}

int* multiplyTransposeMatrix(int *a, int rows_a, int cols_a, int *b, int rows_b, int cols_b) {
    int *result = (int *)malloc(rows_a * rows_b * sizeof(int));
    
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < rows_b; j++) {
            result[i * rows_b + j] = 0;
            for (int k = 0; k < cols_a; k++) {
                result[i * rows_b + j] += a[i * cols_a + k] * b[j * cols_b + k];
            }
        }
    }
    
    return result;
}