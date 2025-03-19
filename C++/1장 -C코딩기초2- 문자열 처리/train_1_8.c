/*
📌 C 스타일 문자열 변환 내용
C++ strtok(): **"string tokenize"**의 약어
char* strtok(char* str, const char* delim);
strtok()을 사용하여 문자열을 "," 기준으로 분리

문자열 앞뒤 공백 제거
strtok()는 자동으로 공백을 제거하지 않으므로 공백을 제거하는 함수(trim())를 구현

정렬 C++ qsort() 사용
qsort()를 사용하여 사전순 정렬

특정 문자열 검색 strcmp() 사용
strcmp()를 사용하여 특정 문자열과 일치하는지 확인
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 문자열 앞뒤 공백 제거 함수
void trim(char* str) {
    char* start = str;
    char* end;

    // 앞쪽 공백 제거
    while (*start == ' ' || *start == '\t' || *start == '\n') {
        start++;
    }

    // 끝 포인터 찾기
    end = start + strlen(start) - 1;

    // 뒤쪽 공백 제거
    while (end > start && (*end == ' ' || *end == '\t' || *end == '\n')) {
        *end = '\0';
        end--;
    }

    // 문자열을 앞으로 복사
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
        // str은 원래 문자열의 시작 주소
        // start는 공백이 제거된 실제 문자열의 시작 주소
        // 앞에 공백이 있으면 문자열을 앞으로 당겨오는 역할을 합니다.
        // strlen(start) + 1 → 문자열 길이 + 널문자(\0)까지 포함해서 복사합니다.
    }
}

// 버블 정렬
void bubbleSort(char* list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(list[j], list[j + 1]) > 0) {
                // swap
                char* temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
// 문자열을 콤마(,)로 분리하고 정렬하는 함수
int splitAndSort(char* baseString, char* list[], int maxTokens) {
    int count = 0;
    char* token = strtok(baseString, ","); // 콤마를 기준으로 문자열 분리

    while (token != NULL && count < maxTokens) {
        trim(token); // 공백 제거
        list[count] = token;
        count++;
        token = strtok(NULL, ","); // 다음 토큰
        // baseString 문자열에서 , 구분자를 찾아 첫 번째 토큰을 잘라주고 반환합니다.
        // 잘라진 위치에 \0(NULL 문자)을 넣어 문자열을 끝내고, 그 다음 문자 주소를 내부 static 포인터에 저장해 둡니다.
    }

    // 정렬
    bubbleSort(list, count);

    return count; // 분리된 문자열 개수 반환
}

// 배열에서 특정 문자열의 빈도수 반환
int findAllString(char* list[], int size, const char* target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], target) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char s[] = "한국, 일본,미국,중국 , 미국 ,   독일   ,   프랑스, 미국 "; // 원본 문자열 (배열 사용)
    char* sortedArray[20]; // 분리된 문자열 저장 배열 // *,[],() 연산자 우선순위 321

    // 문자열을 분리하고 정렬
    int size = splitAndSort(s, sortedArray, 20);

    // 정렬된 배열 출력
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", sortedArray[i]);
    }
    printf("\nArray length = %d\n", size);

    // 특정 문자열 찾기
    const char* target = "미국";
    int frequency = findAllString(sortedArray, size, target);
    printf("빈도수 = %d\n", frequency);

    return 0;
}
