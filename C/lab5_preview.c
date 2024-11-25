// // Problem 1
// // dest는 함수의 입력값으로 주어진 포인터
// // 시작 위치를 그대로 반환해야 하므로 복사해서 값만 이어붙임
// // 복사한 포인터로 주소만 옮기면서 값을 채워줌
// #include <stdio.h>

// char *mystrcat(char *dest, char *src) {
// 	char *dest_ptr = dest; // 시작부분을 가리키는 포인터 변수 하나 생성하고

// 	while (*dest_ptr != '\0') {
// 		dest_ptr++; // 첫번째 인자의 '\0' 까지 포인터를 옮김
// 	}

// 	while (*src != '\0') {
// 		*dest_ptr = *src; // 거기서부터 두번째 인자 이어붙이고
// 		dest_ptr++;
// 		src++;
// 	}

//  *dest_ptr = '\0'; // '\0' 추가

// 	return dest; // 맨 처음 시작부분의 주소 반환
// }

// int main(void) {
// 	char str[256] = "Hello ";
// 	char * pstr2 = "Good Bye World !!!";
	
// 	printf("%s\n", mystrcat(mystrcat(str, "World !!! ..."), pstr2 ));

// 	return 0;
// }


// // Problem 2
// #include <stdio.h>
// #include <string.h>

// void swap(char *a, char *b) {
//     char temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void permute(char *str, int left, int right) {
// 	if (left == right) {
// 		puts(str);
// 		return;
// 	}

// 	for (int i=left; i<=right; i++) {
// 		swap(&str[left], &str[i]);
// 		permute(str, left+1, right);
// 		swap(&str[left], &str[i]);  
// 	}
// }

// void print_all_permutations(char *str) {
// 	int n = strlen(str);
// 	permute(str,0,n-1);

// 	return;
// }

// int main(void) { 
// 	char str[256] = "ABC";

// 	print_all_permutations(str);
// 	return 0; 
// } 


// // Problem 3
// #include <stdio.h>

// char *mystrtok1(char *str, char delim) {
//     static char *psave;  // 상태를 저장하는 정적 변수
//     char *start;         // 현재 토큰의 시작 위치

//     if (str != NULL) {
//         psave = str;  // 문자열 시작 저장
//     }

//     // 더 이상 토큰이 없으면 NULL 반환
//     if (psave == NULL) {
//         return NULL;
//     }


//     // // 구분자가 아닌 첫 번째 문자까지 이동
//     // while (*psave == delim) { 
//     //     psave++;
//     // }

//     // if (*psave == '\0') {
//     //     return NULL;  // 문자열 끝에 도달
//     // } // 맨 처음부터 구분자거나 '\0'이면 공백 출력하는데 그거 막는 코드


//     // 현재 토큰의 시작 위치 저장
//     start = psave;

//     // 구분자를 만날 때까지 진행
//     while (*psave != '\0' && *psave != delim) {
//         psave++;
//     }

//     // 구분자를 만나면 종료 처리
//     if (*psave == delim) {
//         *psave = '\0';  // 구분자를 '\0'으로 교체
//         psave++;        // 다음 위치로 이동
//     } else {
//         psave = NULL;   // 문자열 끝에 도달
//     }
// 	// 구분자를 '\0'로 교체했기 때문에 독립된 문자열처럼 작동
    
// 	return start;  // 현재 토큰 반환
// }

// int main(void) {
// 	char pstr[256] = { ",123,hello,34 56, Good.,Bye"};
// 	char *ptoken;
// 	char delim = ',';
// 	int test = 0;

// 	ptoken = mystrtok1(pstr, delim);
	
// 	while (ptoken) {
// 		printf("%s\n",ptoken);
// 		ptoken = mystrtok1(0, delim);		
// 	}
		
// 	return 0;
// }


// Problem 4
#include <stdio.h>

int is_delim(char ch, char *delim) {
    while (*delim != '\0') {
        if (ch == *delim) {
            return 1;  // 구분자라면 1 반환
        }
        delim++;
    }
    return 0;  // 구분자가 아니면 0 반환
}

char *mystrtok(char *str, char *delim) {
    static char *psave;  // 상태를 저장하는 정적 변수
    char *start;         // 토큰의 시작 위치

    // 첫 번째 호출이면 문자열의 시작을 저장
    if (str != NULL) {
        psave = str;
    }

    // 더 이상 처리할 문자열이 없으면 NULL 반환
    if (psave == NULL) {
        return NULL;
    }

    // // 구분자를 건너뛰고 토큰의 시작 위치 찾기
    // while (*psave != '\0' && is_delim(*psave, delim)) {
    //     psave++;
    // }

    // // 문자열의 끝에 도달하면 NULL 반환
    // if (*psave == '\0') {
    //     return NULL;
    // }

    // 토큰의 시작 위치 저장
    start = psave;

    // 구분자를 만날 때까지 이동
    while (*psave != '\0' && !is_delim(*psave, delim)) {
        psave++;
    }

    // 구분자를 만나면 종료 처리
    if (*psave != '\0') {
        *psave = '\0';  // 구분자를 '\0'으로 교체
        psave++;        // 다음 위치로 이동
    } else {
        psave = NULL;   // 문자열 끝에 도달
    }

    return start;  // 현재 토큰 반환
}

int main(void) {
    char str[] = "apple,orange;banana grape";
    char delim[] = ",; ";
    char *token;

    // mystrtok 호출 및 결과 출력
    token = mystrtok(str, delim);
    while (token) {
        printf("%s\n", token);
        token = mystrtok(NULL, delim);
    }

    return 0;
}


// // Problem 5
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <string.h>
// #include <limits.h>
// #include <stdint.h>

// // Fix issues related to pointer operations

// double calculateAverage(int *values, size_t count) {
//     // if (values == NULL || count == 0) { 
//     //     // NULL 포인터나 0개의 요소 처리
//     //     return 0.0;
//     // }

// 	double sum = 0.0;
// 	for (size_t i = 0; i <= count; i++) { // <= -> <로 수정
// 			sum += values[i];
// 	}
// 	return sum / count;
// }

// void updateTemperature(float *temp) {
//     // if (temp == NULL) {
//     //     // NULL 포인터를 처리하기 위한 에러 메시지 출력
//     //     fprintf(stderr, "Error: NULL pointer passed to updateTemperature\n");
//     //     return;
//     // }

// 	*temp = 25.0;
// }

// void reverseString(char *str) {
// 	// if (str == NULL) {
//     //     // NULL 포인터 처리
//     //     fprintf(stderr, "Error: NULL pointer passed to reverseString\n");
//     //     return;
//     // }

// 	size_t len = strlen(str);
// 	// if (len == 0) {
//     //     // 빈 문자열은 그대로 반환
//     //     return;
//     // }

// 	for (size_t i = 0; i < len / 2; i++) {
// 			char temp = str[i];
// 			str[i] = str[len - i - 1];
// 			str[len - i - 1] = temp;
// 	}
// }

// // The main function is intentionally hidden.





// // Problem 3
// #include <stdio.h>

// char *mystrtok1(char *str, char delim) {
//     static char *psave = 0; 
//     char *start;         

//     if (str != NULL) psave = str;  

//     if (psave == NULL) return NULL;

//     start = psave;

//     while (*psave != '\0' && *psave != delim) {
//         psave++;
//     }

//     if (*psave == delim) {
//         *psave = '\0'; 
//         psave++;      
//     } else {
//         psave = NULL;   
//     }
    
// 	return start; 
// }

// int main(void) {
// 	char pstr[256] = { ",123,hello,34 56, Good.,Bye"};
// 	char *ptoken;
// 	char delim = ',';
// 	int test = 0;

// 	ptoken = mystrtok1(pstr, delim);
	
// 	while (ptoken) {
// 		printf("%s\n",ptoken);
// 		ptoken = mystrtok1(0, delim);		
// 	}
		
// 	return 0;
// }