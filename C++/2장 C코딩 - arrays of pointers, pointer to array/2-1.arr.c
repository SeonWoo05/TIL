/*
C 언어에서 변수가 저장되는 메모리 영역.

Stack (스택) 영역: 지역 변수 및 함수 호출과 관련된 데이터가 저장
Heap (힙) 영역: malloc, calloc, realloc 등을 사용하여 동적으로 할당된 메모리.
Data (데이터) 영역: 전역 변수 및 static 변수가 저장.
Code (코드) 영역: 실행 중인 프로그램 코드
*/

#include <stdio.h>
#include <stdlib.h>

// 포인터 연산을 수행하는 함수
void operationPointer(int* arr, int size) { // 배열을 전달하면 포인터로 받음. arr[] 해도 *arr랑 같다
    printf("&arr[0] = %p\n", &arr[0]); // 배열 첫번째 원소의 주소
    printf("arr = %p\n", arr); // 배열 이름은 포인터라서 위와 동일일

    // C에서 포인터 연산은 포인터가 가리키는 데이터 타입의 크기를 기반 // +1 해서 가리키는게 주소인지 값인지 중요
    // arr + 1  ==  (char *)arr + sizeof(int)
    printf("arr+1 = %p\n", arr + 1); // 배열의 두번째 원소의 주소
    printf("arr[0] = %d\n", arr[0]);
    printf("*arr = %d\n", *arr);
    printf("*arr+1 = %d\n", *arr + 1); // *arr 값 3을 먼저 가져오고 +1 => 4
    printf("*(arr+1) = %d\n\n", *(arr + 1)); // arr+1 의 주소에서 값을 가져옴 => 5
}

int main() {
    int odd[5] = { 3, 5, 7, 9, 11 };
    int size = sizeof(odd) / sizeof(odd[0]); // 배열 요소 개수

    // 포인터 연산을 수행하는 함수 호출
    //배열의 이름 (odd 혹은 arr)은 배열의 첫 번째 원소의 주소를 가리키는 포인터 상수
    operationPointer(odd, size); // 배열 이름은 포인터상수
    
    return 0;
}
