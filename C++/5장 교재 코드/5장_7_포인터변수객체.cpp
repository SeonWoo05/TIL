// 5장_7_포인터변수객체.cpp - 5.2 클래스 객체의 포인터 변수 처리

#include <iostream>
#include <cstring>  // strcpy, strlen 사용
using namespace std;

class Car {
private:
    char* manufacturer;
    int speed;

public:
    // 기본 생성자 (Default Constructor)
    Car() {
        manufacturer = new char[8]; // "Unknown" 저장할 공간
        strcpy(manufacturer, "Unknown");
        speed = 0;
        cout << "Default Constructor 호출" << endl;
    }

    // 일반 생성자 (Parameterized Constructor)
    Car(const char* manufacturer, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1]; // 문자열 길이만큼 동적 할당
        strcpy(this->manufacturer, manufacturer);
        this->speed = speed;
        cout << "Parameterized Constructor 호출" << endl;
    }

    // 복사 생성자 (깊은 복사)
    Car(const Car& other) {
        this->manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(this->manufacturer, other.manufacturer);
        this->speed = other.speed;
        cout << "Copy Constructor 호출" << endl;
    }

    // 소멸자 (Destructor)
    ~Car() {
        cout << "Destructor 호출: " << manufacturer << endl;
        delete[] manufacturer; // 동적 할당된 메모리 해제
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

    // 멤버 정보 출력 함수
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
    Car* car1 = new Car();  // 기본 생성자 호출
    car1->printCarInfo();

    cout << "\n=== Parameterized Constructor 실습 ===" << endl;
    Car* car2 = new Car("Hyundai", 80);  // 일반 생성자 호출
    car2->printCarInfo();

    cout << "\n=== Copy Constructor 실습 ===" << endl;
    Car* car3 = new Car(*car2);  // 복사 생성자 호출
    car3->printCarInfo();

    cout << "\n=== Method Chaining 실습 ===" << endl;
    car2->setManufacturer("Toyota")
         .setSpeed(100)
         .printCarInfo();

    // 동적 할당된 객체 해제 (소멸자 호출)
    delete car1;
    delete car2;
    delete car3;

    // 고급: 객체 배열 생성
    Car* carSet = new Car[10];  // Car() 10번 호출됨
    carSet[0].setManufacturer("Toyota");
    carSet[1].setSpeed(120);
    carSet[2].printCarInfo();

    // Car* carSet = new Car[10]("Hyundai", 100);  // ❌ 에러: 배열은 기본 생성자만 가능

    // 포인터 배열을 통한 객체 배열 만들기
    Car* carSet2[10];
    for (int i = 0; i < 10; ++i) {
        carSet2[i] = new Car("Hyundai", 100 + i * 10);  // 매개변수 생성자 호출
    }

    for (int i = 0; i < 10; ++i) {
        delete carSet2[i];  // 소멸자 호출
    }

    int num;
    cin >> num;  // 종료 대기용 입력
    return 0;
}
