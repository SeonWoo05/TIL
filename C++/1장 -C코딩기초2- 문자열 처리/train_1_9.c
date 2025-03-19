#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 버블 정렬
void bubbleSort(char* list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(list[j], list[j + 1]) > 0) {
                // list[j]가 list[j + 1]보다 사전순으로 뒤에 있다면
                // 즉, strcmp(list[j], list[j + 1]) 가 양수라면,
                // swap
                char* temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void bubbleSortInt(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                // swap
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// 문자열을 공백(" ")으로 분리하여 배열에 저장하고 정렬하는 함수
int splitSortString(char* input, char* stringArray[], int maxTokens) {
    int count = 0;
    char* token = strtok(input, " ");  // 공백을 기준으로 분리

    while (token != NULL && count < maxTokens) {
        stringArray[count++] = token;  // 토큰 저장
        token = strtok(NULL, " ");
    }

    // 문자열 배열 정렬 (사전순)
    bubbleSort(stringArray, count);

    return count;  // 분리된 문자열 개수 반환
}

// 문자열 배열을 정수 배열로 변환하고 정렬하는 함수
void convertSortToIntArray(char* stringArray[], int intArray[], int size) {
    for (int i = 0; i < size; i++) {
        intArray[i] = atoi(stringArray[i]);  // atoi : 문자열 → 정수 변환
    }

    // 정수 배열 정렬 (오름차순)
    bubbleSortInt(intArray, size);
}

// 문자열 배열 출력 함수
void printStringArray(char* stringArray[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", stringArray[i]);
    }
    printf("\n");
}

// 정수 배열 출력 함수
void printIntArray(int intArray[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");
}

int main() {
    char input[] = "12 111 911 921 94 23 214 222"; // char input[] = { '1', '2', ' ', '1', '1' 과 같이 할당됨.
    char* sortedStringArray[20];
    int sortedIntArray[20];

    // 문자열을 공백으로 분리하고 정렬
    int size = splitSortString(input, sortedStringArray, 20);

    // 정렬된 문자열 배열 출력
    printf("Sorted String Array:\n");
    printStringArray(sortedStringArray, size);

    // 문자열 배열을 정수 배열로 변환 및 정렬
    convertSortToIntArray(sortedStringArray, sortedIntArray, size);

    // 정렬된 정수 배열 출력
    printf("Sorted Integer Array:\n");
    printIntArray(sortedIntArray, size);

    return 0;
}