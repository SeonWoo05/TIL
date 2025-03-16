#include <iostream>
#include <string> // C++에만 존재
#include <ctime>

using namespace std;
const int SIZE = 10; // const : 상수 선언

/*
// 문자열 출력
int main() {
    string words[] = {"Hello", "World", "C++"};
    string *data = words; // string 배열을 가리키는 포인터
    cout << data[0] << endl;  // "Hello"
    cout << data[1] << endl;  // "World"
}
*/

/*
// show
void showData(const char* msg, int data[], int size) {
    cout << msg << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    showData("배열 출력:", numbers, 5);
    return 0;
}
*/

/*
//난수를 10 ~ 60 사이에 생성
void inputData(int data[], int SIZE) {
    srand(time(0));
    
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 50; // rand() % 범위
    }
}

// show
void showData(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE);
    showData(data, SIZE);
    return 0;
}
*/

void inputData(int data[], int SIZE) {
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        data[i] = rand();
    }
}

void showData(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE);
    showData(data, SIZE);
    return 0;
}