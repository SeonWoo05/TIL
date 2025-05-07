#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // 생성자
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 크기 계산
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // operator > 정의 (호출 로그 포함)
    bool operator>(const Complex& other) const {
        cout << "operator> 호출됨: ";
        this->print();
        cout << " > ";
        other.print();
        cout << " ?" << endl;
        return this->magnitude() > other.magnitude();
    }

    // 대입 연산자 (기본으로 충분하지만 명시 가능)
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            this->real = other.real;
            this->imag = other.imag;
        }
        return *this;
    }

    // 출력
    void print() const {
        cout << "(" << real << " + " << imag << "i)";
    }
};

// 복소수 배열 정렬 함수 (오름차순, operator> 사용)
void sortComplex(Complex arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // 교환
                Complex temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 배열 출력
void printArray(Complex arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i].print();
        cout << "  (|z| = " << arr[i].magnitude() << ")" << endl;
    }
}

int main() {
    Complex arr[] = {
        Complex(1, 2),   // |z| ≈ 2.236
        Complex(3, 4),   // |z| = 5
        Complex(0, 1),   // |z| = 1
        Complex(2, 2),   // |z| ≈ 2.828
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "정렬 전:\n";
    printArray(arr, size);

    cout << "\n정렬 수행 중...\n";
    sortComplex(arr, size);  // 사용자 정의 정렬 함수

    cout << "\n정렬 후 (오름차순):\n";
    printArray(arr, size);

    return 0;
}
