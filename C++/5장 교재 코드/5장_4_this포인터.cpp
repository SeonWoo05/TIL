// 5장_4_this포인터.cpp - 5.1.3 this 포인터

/*
Car&는 이 함수가 Car 객체에 대한 참조(reference) 를 리턴하겠다는 뜻
즉, 이 함수가 끝난 다음에도 "객체 자신을 다시 사용할 수 있게" 하려는 목적

return *this;  // 객체 자기 자신을 참조로 반환
이렇게 하면 메서드 체이닝이 가능함 .().().()
*/

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string manufacturer;
    int speed;

public:
    // 생성자에서 this 포인터 사용
    Car(string manufacturer, int speed) {
        this->manufacturer = manufacturer;  // this-> 사용
        this->speed = speed;
    }

    // Setter에서 this 포인터 사용 (Method Chaining 지원)
    Car& setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
        return *this;  // 객체 자신 반환
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

    /*
    // getter 추가하자면 이렇게게
    string getManufacturer() const {
        return manufacturer;
    }

    int getSpeed() const {
        return speed;
    }
    */
};

int main() {
    Car car1("Hyundai", 80);

    // 단순 setter 사용
    car1.setSpeed(100);

    // this 포인터 활용: Method Chaining
    car1.setManufacturer("Toyota")
        .setSpeed(100)
        .printCarInfo();

    return 0;
}
