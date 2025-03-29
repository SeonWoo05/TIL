#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showData(char** arr, int size);
void swap(char* arr[], int i, int j);
char** sortFruits(char* arr[], int size, int mode);
void freeMemory(char** arr, int size);

int main() {
    // 문자열 포인터 배열
    char* fruits[] = { "복숭아", "바나나", "귤", "키위", "수박", "참외", "배", "사과", "포도", "감", "산딸기", "대추" };
    int mode = 0;
    int n = sizeof(fruits) / sizeof(fruits[0]);
    
    scanf("%d", &mode);
    
    char** result = sortFruits(fruits, n, mode);
            
    showData(result, n);
    freeMemory(result, n);

    return 0;
}

void showData(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

void swap(char* arr[], int i, int j) {
    char* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

char** sortFruits(char* arr[], int size, int mode) {
    char** result = (char**)malloc(size * sizeof(char*));
    
    for (int i = 0; i < size; i++) {
        result[i] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));
        strcpy(result[i], arr[i]);
    }
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int cmp = strcmp(result[j], result[j + 1]);
            
            if ((mode == 1 && cmp > 0) || (mode == 2 && cmp < 0)) {
                swap(result, j, j + 1);
            }
        }
    }
    
    return result;
}

void freeMemory(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}