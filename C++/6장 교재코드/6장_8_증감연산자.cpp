#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // 생성자
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 전위형 ++ 연산자 오버로딩 (++a)
    Complex& operator++() {
        ++real;
        ++imag;
        cout << "전위형 ++ 연산자 호출됨" << endl;
        return *this;
    }

    // 후위형 ++ 연산자 오버로딩 (a++)
    Complex operator++(int) {
        Complex temp = *this;  // 현재 상태 저장
        real++;
        imag++; // this 객체 자체는 증가하고 있음
        cout << "후위형 ++ 연산자 호출됨" << endl;
        return temp;  // 증가 전 상태 (사용자에게 보여줄 값값)
    }

    // 출력 함수
    void print() const {
        cout << "(" << real << " + " << imag << "i)" << endl;
    }
};

int main() {
    Complex a(1, 2);

    cout << "초기값: ";
    a.print();

    cout << "\n전위형 ++a 실행:\n";
    (++a).print();  // 전위: 먼저 증가 후 출력

    cout << "\n후위형 a++ 실행:\n";
    (a++).print();  // 후위: 먼저 출력 후 증가

    cout << "\n후위형 이후 상태:\n";
    a.print();  // 후위형 이후 상태 확인

    return 0;
}
