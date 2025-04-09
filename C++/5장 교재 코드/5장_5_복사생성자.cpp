// 5장_5_복사생성자.cpp - 5.2 복사 생성자와 소멸자

/*
동적 할당된 데이터가 있을 경우에는 반드시 깊은 복사(deep copy)를
수행하는 복사 생성자를 직접 구현해야 한다.
*/

#include <iostream>
using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

public:
    // 기본 생성자 (Default Constructor)
    Car() {
        manufacturer = "Unknown";
        speed = 0;
        cout << "Default Constructor 호출" << endl;
    }

    // 일반 생성자 (Parameterized Constructor)
    Car(char* manufacturer, int speed) {
        this->manufacturer = manufacturer;
        this->speed = speed;
        cout << "Parameterized Constructor 호출" << endl;
    }

    // 복사 생성자 (Copy Constructor)
    // parameter가 Car class의 객체
    // Car 클래스의 다른 객체(other) 를 참조로 받아서, 그걸 기반으로 새 객체를 만듦
    Car(const Car& other) {
        this->manufacturer = other.manufacturer;
        this->speed = other.speed;
        cout << "Copy Constructor 호출" << endl;
    }

    // 소멸자 (Destructor)
    ~Car() {
        cout << "Destructor 호출: " << manufacturer << endl;
    }

    // Setter에서 this 포인터 사용 (Method Chaining 지원)
    Car& setManufacturer(char* manufacturer) {
        this->manufacturer = manufacturer;
        return *this; // this 포인터를 사용하여 객체 자신을 반환
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // 멤버 함수에서 this 포인터 사용
    void printCarInfo() {
        cout << "제조사: " << this->manufacturer
             << ", 속도: " << this->speed << " km/h" << endl;
    }
};

// =============================
// 메인 함수
// =============================
int main() {
    cout << "=== Default Constructor 실습 ===" << endl;
    Car car1;  // 기본 생성자 호출
    car1.printCarInfo();

    cout << "\n=== Parameterized Constructor 실습 ===" << endl;
    Car car2("Hyundai", 80);  // 일반 생성자 호출
    car2.printCarInfo();

    cout << "\n=== Copy Constructor 실습 ===" << endl;
    Car car3 = car2;  // 복사 생성자 호출
    car3.printCarInfo();

    cout << "\n=== Method Chaining 실습 ===" << endl;
    car2.setManufacturer("Toyota")
        .setSpeed(100)
        .printCarInfo();

    return 0;  // 소멸자 자동 호출
}
