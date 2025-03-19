#include <stdio.h>
#include <string.h>  // strcat, strcpy, strncpy, strstr

// strcat(dest, src); dest 문자열 뒤에 src 문자열을 이어 붙입니다.
// strcpy(dest, src); src 문자열을 dest에 복사합니다.
// strncpy(dest, src, n); src의 처음 n 문자를 dest에 복사합니다.
// strstr(haystack, needle); 문자열 내에서 특정 부분 문자열을 찾는 함수입니다. 위치를 반환

// 문자열 교체 함수
void replaceString(char* baseString, const char* target, const char* replacement, char* result) {
    char* pos = baseString;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    result[0] = '\0';  // 결과 문자열 초기화

    while ((pos = strstr(pos, target)) != NULL) { // strstr이 위치 반환
        // target 위치까지의 부분 문자열을 result에 복사
        strncat(result, baseString, pos - baseString); // pos 전까지만 이어붙임
        // replacement 문자열을 result에 추가
        strcat(result, replacement);
        // pos 이후의 나머지 문자열을 다시 baseString으로 갱신
        pos += targetLen;
        baseString = pos;
    }
    // 남은 부분을 result에 추가
    strcat(result, baseString);
}

int main() {
    char s[100] = "자바 코딩, 파이썬 코딩, C 코딩, C# 코딩"; // 원본 문자열
    char newString[150];  // 문자열 추가 후 저장할 공간
    char finalString[200];  // 문자열 교체 후 저장할 공간

    // 서브스트링 추가
    strcpy(newString, s);  // 원본 복사
    strcat(newString, " PCCP 시험: 11월 23일");  // 서브스트링 추가

    // 문자열 교체
    replaceString(newString, "코딩", "프로그래밍", finalString);

    // 결과 출력
    printf("%s\n", finalString);

    return 0;
}
