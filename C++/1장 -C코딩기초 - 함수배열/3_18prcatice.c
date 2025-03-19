#include <stdio.h>
#include <stdlib.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

void getMatrix(int matrix[][ACOLS], int rows);
void getMatrix_b(int matrix[][BCOLS], int rows);
void showMatrix_c(int matrix[][CCOLS], int rows);
void multiplyMatrix(int a[][ACOLS], int rows_a, int b[][BCOLS], int rows_b, int c[][CCOLS], int rows_c);

int main() {
    int seed = 0;
    scanf("%d", &seed);
    srand(seed);

    int a[AROWS][ACOLS], b[BROWS][BCOLS], c[CROWS][CCOLS];

    getMatrix(a, AROWS);
    getMatrix_b(b, BROWS);

    multiplyMatrix(a, AROWS, b, BROWS, c, CROWS);
    showMatrix_c(c, CROWS);

    return 0;
}

void getMatrix(int matrix[][ACOLS], int rows) {
    for (int i = 0; i < AROWS; i++) {
        for (int j = 0; j < ACOLS; j++) {
            matrix[i][j] = rand() % 100;  
        }
    }
}

void getMatrix_b(int matrix[][BCOLS], int rows) {
    for (int i = 0; i < BROWS; i++) {
        for (int j = 0; j < BCOLS; j++) {
            matrix[i][j] = rand() % 100;  
        }
    }
}

void showMatrix_c(int matrix[][CCOLS], int rows) {
    for (int i = 0; i < CROWS; i++) {
        for (int j = 0; j < CCOLS; j++) {
            if (j == CCOLS - 1) {  // 마지막 원소는 공백없이 줄바꿈
                printf("%d", matrix[i][j]);
            } else {
                printf("%-8d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void multiplyMatrix(int a[][ACOLS], int rows_a, int b[][BCOLS], int rows_b, int c[][CCOLS], int rows_c) {
    for (int i = 0; i < AROWS; i++) {
        for (int j = 0; j < BCOLS; j++) {
            c[i][j] = 0;
            for (int k = 0; k < BROWS; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }   
}