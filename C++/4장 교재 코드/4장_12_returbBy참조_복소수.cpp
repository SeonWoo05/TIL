// 4장_12_returnBy참조_복소수.cpp - 4.4.3 reference에 의한 함수 parameter
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 복소수 구조체 정의
struct complex {
    float real;
    float imaginary;
};

// 난수를 사용하여 복소수를 생성하는 함수 (Pass by Reference로 결과 저장)
void getComplex(complex& c) {
    c.real = (rand() % 100) / 10.0f;      // 0.0 ~ 9.9
    c.imaginary = (rand() % 100) / 10.0f; // 0.0 ~ 9.9
}

// 두 개의 복소수를 더하는 함수 (Pass by Reference & Return by Reference)
complex& addComplex(const complex& c1, const complex& c2, complex& result) {
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;  // result는 main()에서 선언된 변수이므로 참조 반환 안전
}

// 복소수를 출력하는 함수 (Pass by Reference)
void showComplex(const complex& c) {
    cout << c.real;
    if (c.imaginary >= 0)
        cout << " + " << c.imaginary << "i" << endl;
    else
        cout << " - " << -c.imaginary << "i" << endl;
}

int main() {
    srand(time(0)); // 난수 시드 초기화

    complex num1, num2, sum; // 복소수 구조체 선언

    // 난수를 생성하여 복소수에 저장
    getComplex(num1);
    getComplex(num2);

    // 복소수 출력
    cout << "Complex Number 1: ";
    showComplex(num1);

    cout << "Complex Number 2: ";
    showComplex(num2);

    // 복소수 덧셈 (결과도 참조로 전달)
    addComplex(num1, num2, sum);

    // 결과 출력
    cout << "Sum: ";
    showComplex(sum);

    return 0;
}