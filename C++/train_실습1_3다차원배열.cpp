/*
* 다차원 배열 처리 함수 구현
*/
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 4

using namespace std;

// 행렬 덧셈 (A + D = E)
void addMatrix(int A[][COLS_A], int D[][COLS_A], int E[][COLS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            E[i][j] = A[i][j] + D[i][j];
        }
    }
}

// 행렬 덧셈 - 이중 포인터에 대한 이해가 필요 => chap 2 
// C++에서는 2차원 배열의 두 번째 차원(COLS_A)이 반드시 지정되어야 함.
int** addMatrix2(int X[][COLS_A], int Y[][COLS_A], int rows, int cols) {
    int** Z = new int* [rows]; // 행(Row) 크기만큼 포인터 배열 동적 할당
    for (int i = 0; i < rows; i++) {
        Z[i] = new int[cols]; // 각 행에 대해 열(Col) 크기만큼 동적 할당
        for (int j = 0; j < cols; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
    return Z;
}

// 1) 2차원 배열에 난수 입력 (A: ROWS_A x COLS_A 전용)
void inputData(int arr[][COLS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 50; // 예: 0~49 난수
        }
    }
}

// 2) 2차원 배열에 난수 입력 (B: ROWS_B x COLS_B 전용)
void inputData(int arr[][COLS_B], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 50; // 예: 0~49 난수
        }
    }
}

// show A
void showData(const char* msg, int arr[][COLS_A], int rows, int cols) {
    cout << msg << endl; // endl은 줄 바꿈 역할
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// show B
void showData(const char* msg, int arr[][COLS_B], int rows, int cols) {
    cout << msg << endl; // endl은 줄 바꿈 역할
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// showData2: 동적 할당된 2차원 배열(int** 형태) 출력
void showData2(const char* msg, int** arr, int rows, int cols) {
    cout << msg << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Pointer to Array : 행렬 구조에서 안쪽 행렬 하나를 가리키는 포인터. A를 증가시키면 다음 배열을 가리킴
// int *A[COLS_A]; : Array of Pointers
// 여기서 A는 COLS_A개의 정수형 포인터를 저장하는 배열.
void multiplyMatrix(int (*A)[COLS_A], int (*B)[COLS_B], int (*C)[COLS_B], int rows_a, int cols_a, int cols_b) {
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// A[][COLS_A]는 배열 자체이지만, 함수에서 전달될 때 배열 포인터로 변환됨 == (*A)[COLS_A]
void transposeMatrix(int B[][COLS_B], int F[][ROWS_B], int rows_b, int cols_b) {
    for (int i = 0; i < cols_b; i++) {
        for (int j = 0; j < rows_b; j++) {
            F[i][j] = B[j][i];
        }
    }
}

// multiplyMatrixTransposed
// A(ROWS_A×COLS_A) × F(COLS_B×ROWS_B) => G(ROWS_A×COLS_B)
void multiplyMatrixTransposed(int A[][COLS_A], int F[][ROWS_B], int G[][COLS_B], int rowsA, int colsA, int colsB) {
// B[k][j] = F[j][k] 이므로 => G[i][j] = Σ ( A[i][k] * F[j][k] )
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            G[i][j] = 0;
                for (int k = 0; k < colsA; k++) {
                    G[i][j] += A[i][k] * F[j][k];
                }
            }
        }
    }

// equals
bool equals(int A[][COLS_A], int D[][COLS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != D[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0)); // 난수 초기화

    int A[ROWS_A][COLS_A]; // 2x3 행렬
    int B[ROWS_B][COLS_B]; // 3x4 행렬
    int C[ROWS_A][COLS_B]; // 2x4 행렬
    int D[ROWS_A][COLS_A]; // 2x3 복제 행렬
    int E[ROWS_A][COLS_A]; // 덧셈 결과 행렬
    int F[COLS_B][ROWS_B]; // 전치 행렬
    int G[ROWS_A][COLS_B]; // 전치 행렬 활용 곱셈 결과


    inputData(A, ROWS_A, COLS_A);
    inputData(B, ROWS_B, COLS_B);

    // 배열 복제 (수동 복사)
    for (int i = 0; i < ROWS_A; i++)
        for (int j = 0; j < COLS_A; j++)
            D[i][j] = A[i][j];

    cout << "A[2][3] = \n";
    showData("행렬 A", A, ROWS_A, COLS_A);

    cout << "D[2][3] = \n";
    showData("행렬 D", D, ROWS_A, COLS_A);

    cout << "B[3][4] = \n";
    showData("행렬 B", B, ROWS_B, COLS_B);

    addMatrix(A, D, E, ROWS_A, COLS_A);
    cout << "E[2][3] = \n";
    showData("행렬 E", E, ROWS_A, COLS_A);

    int** H = addMatrix2(A, D, ROWS_A, COLS_A); // 정적 배열은 함수 종료시 소멸됨. 따라서 동적 할당
    cout << "H[2][3] = \n";
    showData2("행렬 H", H, ROWS_A, COLS_A);
    delete[] H;

    multiplyMatrix(A, B, C, ROWS_A, COLS_A, COLS_B);
    cout << "C[2][4] = \n";
    showData("행렬 C", C, ROWS_A, COLS_B);

    transposeMatrix(B, F, ROWS_B, COLS_B);
    cout << "F[4][3] = \n";
    showData("행렬 F (B의 전치)", F, COLS_B, ROWS_B);

    multiplyMatrixTransposed(A, F, G, ROWS_A, COLS_A, COLS_B);
    cout << "G[2][4] (전치 행렬을 활용한 곱셈 결과) = \n";
    showData("행렬 G", G, ROWS_A, COLS_B);

    if (equals(A, D, ROWS_A, COLS_A))
        cout << "행렬 A와 D는 동일합니다.\n";
    else
        cout << "행렬 A와 D는 동일하지 않습니다.\n";
    // system("pause");
    return 0;
}
