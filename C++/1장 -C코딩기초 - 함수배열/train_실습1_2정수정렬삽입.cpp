// stack : 로컬변수 할당
// heap : 메모리 할당

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // 전역에서 std 네임스페이스 사용 => 접두어 생략
const int SIZE = 10; // const : 상수 선언

//난수를 10 ~ 60 사이에 생성
void inputData(int data[], int SIZE) {
    srand(time(0));
    
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 51 + 10; // rand() % 범위 , 0이상 정수를 생성
    }
}

// show
void showData(const char* msg, int data[], int size) {
    cout << msg << endl; // endl은 줄 바꿈 역할
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// sort (오름차순)
void sortData(int *data, int SIZE) { // int *data == int data[]
    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            if (*(data + i) > data[j]) // *(data+i) == data[i]
                swap(data[i], data[j]);
        }
    }
}

// swap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// reverse swap
void reverse(int data[], int SIZE) {
    for (int i = 0; i < (SIZE / 2); i++) {
        int j = SIZE - i - 1;
        swap(data[i], data[j]);
    }
}

// 최대값을 먼저 뽑아내는 Selection Sort
void maxSort(int data[], int size) {
    // 왼쪽부터 하나씩 '가장 큰 값'을 찾아 앞으로 배치
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] > data[maxIndex]) {
                maxIndex = j;
            }
        }
        // swap
        int temp = data[i];
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
    }
}

/*
 * char *data[] : 문자열을 가리키는 포인터들의 배열.
 * ex) char *data[] = {"Hello", "World", "C++"}; 이면 data[0] = (Hello를 가리키는) 포인터
 * 
*/

/*
 * 난이도가 매우 높은 알고리즘 구현
 * 정렬된 기존 배열에 임의 값을 추가하는 알고리즘 > 새 배열의 크기는 기존 배열보다 +1로 만들고 기존 배열을 copy할 때
 * 삽입된 값이 중간에 들어가는 알고리즘 구현하기
 * O(n) 알고리즘으로 구현
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[SIZE + 1]; // new 동적 메모리 할당 , 함수 종료후에도 남아 있어 delete[] 필요
    
    int pos = 0; // 시작 위치 설정
    while (pos < SIZE && data[pos] < value) {
        pos++;
    }

    for (int i = 0; i < pos; i++) {
        newData[i] = data[i];
    }
    
    newData[pos] = value;
    
    for (int i = pos+1; i < SIZE; i++) {
        newData[i] = data[i-1];
    }

    return newData;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE); // data 라는 주소 상수를 전달
    showData("난수 입력", data, SIZE);

    sortData(data, SIZE);
    showData("정렬후", data, SIZE);

    reverse(data, SIZE);
    showData("\n역순 재배치", data, SIZE);

    maxSort(data, SIZE);
    showData("\n", data, SIZE);

    sortData(data, SIZE);
    showData("\n 정렬후", data, SIZE);

    // 새로운 값 삽입 해보기
    int realData[] = { 5, 15, 99 };
    for (int newData : realData) { // newData : 배열의 각 원소, 배열의 원소를 모두 정렬 => i 도입 안해도됨
        int* result = insertData(data, SIZE, newData); // insert 후에도 정렬이 되어있도록, 기존 배열에 넣을 수 없기 때문에 새로운 배열 할당(copy)
        cout << "\n\n" << newData << " : ";
        showData("실수 삽입후", result, SIZE + 1);
        delete[] result; // 동적 할당 해제
    }

    return 0;
}
