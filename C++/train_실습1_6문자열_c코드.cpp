 /*
  char*와 cstring 함수를 사용하여 문자열 처리
 부분 문자열 검색 strstr() 사용
 문자열 시작 비교 strncmp() 사용
 문자열 끝 비교 strcmp() 사용
 숫자 추출 → isdigit()을 이용해 수동 복사
 */
#include <iostream>
#include <cstring> // strcmp, strstr, strncmp
#include <cctype>  // isdigit

using namespace std;

// 특정 조건에 맞는 문자열을 찾아 출력하는 함수
void findStrings(char array[][50], int size, const char* keyword, const char* condition) {
    for (int i = 0; i < size; i++) {
        char* element = array[i];

        if (strcmp(condition, "contains") == 0) {
            if (strstr(element, keyword) != nullptr) { // strstr 부분 문자열 검색
                cout << element << endl;
            }
        }
        else if (strcmp(condition, "number") == 0) {
            bool found = false;
            for (int j = 0; element[j] != '\0'; j++) {
                if (isdigit(element[j])) {
                    cout << element[j];
                    found = true;
                }
            }
            if (found) cout << endl;
        }
        else if (strcmp(condition, "startsWith") == 0) {
            if (strncmp(element, keyword, strlen(keyword)) == 0) {
                cout << element << endl;
            }
        }
        else if (strcmp(condition, "endsWith") == 0) {
            int elementLen = strlen(element);
            int keywordLen = strlen(keyword);

            if (elementLen >= keywordLen &&
                strcmp(element + (elementLen - keywordLen), keyword) == 0) {
                cout << element << endl;
            }
        }
        else {
            cout << "Invalid condition." << endl;
        }
    }
}

int main() {
    char address[][50] = { // char address[8][50]는 8개의 문자열을 각각 최대 50자까지 저장할 수 있는 공간을 의미
        "경기도 남양주 별내동", // 각 행(즉, address[i])은 자동으로 \0이 포함된 문자열이 저장됨
        "서울시 영등포구 당산동",
        "부산시 동래구 온천동144",
        "충남 천안시 서북구",
        "부산시 연제구 연산동",
        "서울시 송파구 석촌동",
        "전북 부안군 부안읍",
        "부산시 금정구 장전동63"
    };
    int size = 8; // 배열 크기

    // 1. "부산시"를 포함하는 문자열 찾기
    cout << "1. Contains '부산시':\n";
    findStrings(address, size, "부산시", "contains");

    // 2. 숫자만 추출하여 출력
    cout << "\n2. 문자열에서 숫자 추출:\n";
    findStrings(address, size, "99", "number");

    // 3. "서울시"로 시작하는 문자열 찾기
    cout << "\n3. Starts with '서울시':\n";
    findStrings(address, size, "서울시", "startsWith");

    // 4. "연산동"으로 끝나는 문자열 찾기
    cout << "\n4. Ends with '연산동':\n";
    findStrings(address, size, "연산동", "endsWith");
    return 0;
}
