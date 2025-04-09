// 5_3_클래스private_charptr.cpp - char* 버전의 캡슐화 구현

// 이제는 포인터이기 때문에 문자열 저장 공간이 없음 → new 이용해 직접 메모리를 할당해줘야 함

#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* manufacturer;   // 제조사 (char* 포인터)
    char* model;          // 모델명 (char* 포인터)
    double weight;        // 차중량 (kg)
    int length;           // 전장(mm)
    int width;            // 전폭(mm)
    int speed;            // 속도

public:
    // 생성자와 소멸자
    Car();  // 기본 생성자
    Car(const char* m, const char* mod, double w, int l, int wdt, int s);  // 매개변수 생성자
    ~Car(); // 소멸자

    // Setter & Getter
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

    // 과속 여부 판단
    void checkSpeeding(int speedLimit);
    void checkSpeeding(); // 기본 제한속도

    // 출력 연산자 오버로딩
    // friend로 선언된 함수는 클래스 외부에서 정의되지만, 마치 클래스의 멤버처럼 내부 접근이 가능함
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// Car 클래스 멤버 함수 정의
// =============================

// 기본 생성자
Car::Car() {
    manufacturer = new char[8];
    strcpy(manufacturer, "Unknown");

    model = new char[8];
    strcpy(model, "Unknown");

    weight = 0.0;
    length = 0;
    width = 0;
    speed = 0;
}

// 매개변수 생성자
Car::Car(const char* m, const char* mod, double w, int l, int wdt, int s) {
    manufacturer = new char[strlen(m) + 1];
    strcpy(manufacturer, m);

    model = new char[strlen(mod) + 1];
    strcpy(model, mod);

    weight = w;
    length = l;
    width = wdt;
    speed = s;
}

// 소멸자 (동적 메모리 해제)
Car::~Car() {
    delete[] manufacturer;
    delete[] model;
}

// Setter & Getter 구현

void Car::setManufacturer(const char* m) {
    delete[] manufacturer;
    manufacturer = new char[strlen(m) + 1];
    strcpy(manufacturer, m);
}

const char* Car::getManufacturer() const {
    return manufacturer;
}

void Car::setModel(const char* mod) {
    delete[] model;
    model = new char[strlen(mod) + 1];
    strcpy(model, mod);
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

// 차급 분류 (전장 기준)
const char* Car::getSegment() {
    if (length < 4200)
        return "B-세그먼트 (소형차)";
    else if (length < 4600)
        return "C-세그먼트 (준중형)";
    else if (length < 4900)
        return "D-세그먼트 (중형)";
    else if (length < 5100)
        return "E-세그먼트 (대형)";
    else
        return "F-세그먼트 (초대형)";
}

// 과속 판단
void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "과속 경고! (제한 속도: " << speedLimit << " km/h)" << endl;
    else
        cout << "정상 주행" << endl;
}

void Car::checkSpeeding() {
    checkSpeeding(60); // 기본 제한 속도
}

// 출력 연산자 오버로딩
// friend로 선언된 함수는 클래스 외부에서 정의되지만, 마치 클래스의 멤버처럼 내부 접근이 가능함
ostream& operator<<(ostream& os, const Car& car) {
    os << "제조사 = " << car.manufacturer
       << ", 모델 = " << car.model
       << ", 중량 = " << car.weight << " kg"
       << ", 전장 = " << car.length << " mm"
       << ", 전폭 = " << car.width << " mm"
       << ", 속도 = " << car.speed << " km/h";
    return os;
}

// =============================
// 메인 함수
// =============================
int main() {
    // 자동차 객체 생성 (매개변수 생성자)
    Car car1("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car car2("BMW", "M3", 1200, 4500, 1700, 110);

    // 멤버 변경
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