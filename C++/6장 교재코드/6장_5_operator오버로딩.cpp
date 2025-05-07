#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 생성자
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // 복소수 × 복소수 연산자 오버로딩
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // 복소수 × 실수 (스칼라 곱) 연산자 오버로딩
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    // 실수 × 복소수 (friend 함수로 전역 연산자 오버로딩)
    friend Complex operator*(double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }

    // 출력 함수
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);   // 3 + 4i
    Complex c2(1, 2);   // 1 + 2i

    // double 타입에서 operator*를 찾음 → 없음 ⇒ 전역 함수 필요
    // 멤버 연산자는 왼쪽 피연산자가 그 클래스여야만 호출할 수 있다.
    // double은 사용자 정의 타입이 아니므로 멤버 함수를 추가할 수 없고, 전역 함수로 처리해야 함.
    Complex result1 = c1 * c2;     // 복소수 곱
    Complex result2 = c1 * 2.0;    // 복소수 * 실수
    Complex result3 = 2.0 * c1;    // 실수 * 복소수

    cout << "복소수 * 복소수: ";
    result1.print();  // -5 + 10i

    cout << "복소수 * 실수: ";
    result2.print();  // 6 + 8i

    cout << "실수 * 복소수: ";
    result3.print();  // 6 + 8i

    return 0;
}
