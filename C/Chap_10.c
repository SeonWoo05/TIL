// // P_4
// // 동적 메모리를 활용하여 정수 배열을 생성하고, 난수로 초기화한 후, 메모리를 해제

// #include <stdio.h>
// #include <time.h>
// #include <stdlib.h>

// int main(void)
// {
//     int* na;                    // 동적 할당된 메모리를 가리킬 포인터
//     unsigned int nsize;         // 배열 크기
//     int i;

//     puts("Enter N (>0):");      // 사용자로부터 배열 크기 입력
//     scanf("%u", &nsize);
//     srand(time(0));             // 난수 생성을 위한 초기화

//     na = malloc(sizeof(int) * nsize); // 메모리 동적 할당
//     if (na) {                          // 메모리 할당 성공 여부 확인
//         for (i = 0; i < nsize; i++) { 
//             na[i] = rand() % 10000;    // 난수로 배열 초기화
//             printf("%d ", na[i]);      // 값 출력
//         }
//         free(na);                      // 사용한 메모리 해제
//     }

//     return 0;
// }