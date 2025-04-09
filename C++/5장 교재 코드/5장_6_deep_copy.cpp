// 5장_6_deep_copy.cpp - 5.2 복사 생성자와 소멸자

/*
Car car1("Hyundai", 80);
Car car2 = car1; // 복사 생성자

car2.setManufacturer("BMW");

car1.printCarInfo(); 
// 얕은 복사면 car1의 제조사가 "BMW"로 바뀜           
// 같은 manufacturer 포인터가 가리키는 메모리를 가리키고 있어서
// 깊은 복사면 서로 다른 메모리를 가리키고 있어서 "Hyundai" 유지
*/

#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

public:
    // 기본 생성자 (Default Constructor)
    Car() {
        manufacturer = new char[8];
        strcpy(manufacturer, "Unknown");
        speed = 0;
        cout << "Default Constructor 호출" << endl;
    }

    // 일반 생성자 (Parameterized Constructor)
    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        cout << "Parameterized Constructor 호출" << endl;
    }

    // 복사 생성자 (Deep Copy Implementation)
    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        cout << "Copy Constructor 호출 (Deep Copy)" << endl;
    }

    // 소멸자 (Destructor)
    ~Car() {
        cout << "Destructor 호출: " << manufacturer << endl;
        delete[] manufacturer; // 여기서 메모리 할당 해제해줌
    }

    // Setter (Method Chaining 지원)
    Car& setManufacturer(const char* manufacturer) {
        delete[] this->manufacturer; // 기존 메모리 해제
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);
        return *this;
    }

    Car& setSpeed(int speed) {
        this->speed = speed;
        return *this;
    }

    // 정보 출력 함수
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
    Car car3 = car2;  // 복사 생성자 호출 (Deep Copy)
    car3.printCarInfo();

    cout << "\n=== Method Chaining 실습 ===" << endl;
    car2.setManufacturer("Toyota")
        .setSpeed(100)
        .printCarInfo();

    return 0;  // 소멸자 자동 호출
}
