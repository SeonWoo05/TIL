// 5_3_클래스private.cpp - 5.1.2 private에 의한 encapsulation 구현

#include <iostream>
#include <cstring>
using namespace std;

// 자동차 클래스 (모든 멤버 변수를 private으로 설정)
class Car {
private:
    char manufacturer[50];  // 제조사 (char *로 구현)
    char model[50];         // 모델명 (char *로 구현)
    double weight;          // 차중량 (kg)
    int length;             // 전장(mm)
    int width;              // 전폭(mm)
    int speed;              // 속도

public:
    // 생성자 선언
    Car(const char* m, const char* mod, double w, int l, int wdt, int s);
    Car();  // 기본 생성자

    // Getter & Setter
    void setManufacturer(const char* m);
    const char* getManufacturer() const;

    void setModel(const char* mod);
    const char* getModel() const;

    void setWeight(double w);
    double getWeight() const;

    void setLength(int l);
    int getLength() const;

    void setWidth(int w);
    int getWidth() const;

    void setSpeed(int s);
    int getSpeed() const;

    // 전장 기준으로 차급 세그먼트 분류
    const char* getSegment();

    // 과속 여부 판단 메소드
    void checkSpeeding(int speedLimit);
    void checkSpeeding(); // 기본 제한속도 60km/h

    // 객체 정보 출력하는 연산자 오버로딩
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// 자동차 클래스 멤버 함수 구현
// =============================

// 매개변수 있는 생성자
Car::Car(const char* m, const char* mod, double w, int l, int wdt, int s) {
    strncpy(manufacturer, m, sizeof(manufacturer) - 1); // null 문자 이전까지만 복사
    manufacturer[sizeof(manufacturer) - 1] = '\0'; // index니까 하나 뒤임. null 문자 삽입

    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';

    weight = w;
    length = l;
    width = wdt;
    speed = s;
}

// 기본 생성자
Car::Car() {
    manufacturer[0] = '\0';
    model[0] = '\0';
    weight = 0.0;
    length = 0;
    width = 0;
    speed = 0;
}

// 클래스의 멤버를 private으로 선언하면 외부에서 직접 접근할 수 없어서 간접적으로 접근
// Setter & Getter 구현

// 문자열 변경을 막기 위해 const char* 로 반환
// const 멤버 함수 → 객체 상태를 변경하지 않겠다는 보증
void Car::setManufacturer(const char* m) {
    strncpy(manufacturer, m, sizeof(manufacturer) - 1);
    manufacturer[sizeof(manufacturer) - 1] = '\0';
}

const char* Car::getManufacturer() const {
    return manufacturer;
}

void Car::setModel(const char* mod) {
    strncpy(model, mod, sizeof(model) - 1);
    model[sizeof(model) - 1] = '\0';
}

const char* Car::getModel() const {
    return model;
}

void Car::setWeight(double w) {
    weight = w;
}

double Car::getWeight() const {
    return weight;
}

void Car::setLength(int l) {
    length = l;
}

int Car::getLength() const {
    return length;
}

void Car::setWidth(int w) {
    width = w;
}

int Car::getWidth() const {
    return width;
}

void Car::setSpeed(int s) {
    speed = s;
}

int Car::getSpeed() const {
    return speed;
}

// 전장 기준으로 차급 세그먼트 분류
const char* Car::getSegment() {
    if (length < 4200)
        return "B-세그먼트 (소형차)";
    else if (length < 4600)
        return "C-세그먼트 (준중형, 소형 패밀리카)";
    else if (length < 4900)
        return "D-세그먼트 (중형차, 패밀리 세단)";
    else if (length < 5100)
        return "E-세그먼트 (대형차, 고급 세단)";
    else
        return "F-세그먼트 (초대형차, 플래그십 세단)";
}

// 과속 여부 판단
void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "과속 경고! (제한 속도: " << speedLimit << " km/h)" << endl;
    else
        cout << "정상 주행" << endl;
}

void Car::checkSpeeding() {
    checkSpeeding(60); // 기본 제한속도 60으로 호출
}

// 객체 정보를 출력하는 연산자 오버로딩 (<<)
// <<는 비멤버 함수(non-member function) 로 구현해야 함.
// 왜냐하면 cout << car에서 cout은 Car 객체가 아니라 ostream 객체이기 때문
ostream& operator<<(ostream& os, const Car& car) {
    os << "제조사 = " << car.manufacturer
       << ", 모델 = " << car.model
       << ", 중량 = " << car.weight << " kg"
       << ", 전장 = " << car.length << " mm"
       << ", 전폭 = " << car.width << " mm"
       << ", 속도 = " << car.speed << " km/h";
    return os; // cout << car1 << car2; 처럼 연결 출력이 가능하려면 반드시 ostream을 반환
}

// =============================
// 메인 함수
// =============================
int main() {
    // 자동차 객체 생성 (매개변수 있는 생성자 사용)
    Car car1("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car car2("BMW", "M3", 1200, 4500, 1700, 110);

    // 객체 멤버 변경 (속도 및 제조사 변경) (Setter 사용)
    car1.setSpeed(80);
    car2.setManufacturer("Mercedes");

    cout << "수정된 차량 정보:" << endl;
    cout << car1 << endl;
    cout << car2 << endl;

    // 기본 생성자 사용
    Car c1;
    c1.setManufacturer("Toyota");
    c1.setModel("Camry");
    c1.setSpeed(70);

    cout << "기본 생성자로 생성된 차량 정보:" << endl;
    cout << c1 << endl;

    return 0;
}
