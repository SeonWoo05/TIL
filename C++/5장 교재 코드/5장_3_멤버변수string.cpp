// 5_3_클래스private_string.cpp - std::string 버전

/*
< string 버전의 장점 >
메모리 관리 : new와 delete를 사용할 필요 없음
안전성 : 버퍼 오버플로우, strncpy 등 고민 불필요
간결성 : 코드가 짧고 읽기 쉬움
기능 풍부 : +, ==, size() 등 다양한 연산 가능
*/

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string manufacturer;   // 제조사 (std::string 사용)
    string model;          // 모델명 (std::string 사용)
    double weight;         // 차중량 (kg)
    int length;            // 전장(mm)
    int width;             // 전폭(mm)
    int speed;             // 속도

public:
    // 생성자와 소멸자
    Car();  // 기본 생성자
    Car(string m, string mod, double w, int l, int wdt, int s);  // 매개변수 생성자

    // Getter & Setter
    void setManufacturer(string m);
    string getManufacturer() const;

    void setModel(string mod);
    string getModel() const;

    void setWeight(double w);
    double getWeight() const;

    void setLength(int l);
    int getLength() const;

    void setWidth(int w);
    int getWidth() const;

    void setSpeed(int s);
    int getSpeed() const;

    // 전장 기준으로 차급 세그먼트 분류
    string getSegment() const;

    // 과속 여부 판단
    void checkSpeeding(int speedLimit) const;
    void checkSpeeding() const;

    // 출력 연산자 오버로딩
    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// 멤버 함수 정의
// =============================

Car::Car() {
    manufacturer = "";
    model = "";
    weight = 0.0;
    length = 0;
    width = 0;
    speed = 0;
}

Car::Car(string m, string mod, double w, int l, int wdt, int s)
    : manufacturer(m), model(mod), weight(w), length(l), width(wdt), speed(s) {}

void Car::setManufacturer(string m) {
    manufacturer = m;
}

string Car::getManufacturer() const {
    return manufacturer;
}

void Car::setModel(string mod) {
    model = mod;
}

string Car::getModel() const {
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

string Car::getSegment() const {
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

void Car::checkSpeeding(int speedLimit) const {
    if (speed > speedLimit)
        cout << "과속 경고! (제한 속도: " << speedLimit << " km/h)" << endl;
    else
        cout << "정상 주행" << endl;
}

void Car::checkSpeeding() const {
    checkSpeeding(60);
}

// 출력 연산자 오버로딩
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
    Car car1("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car car2("BMW", "M3", 1200, 4500, 1700, 110);

    car1.setSpeed(80);
    car2.setManufacturer("Mercedes");

    cout << "수정된 차량 정보:" << endl;
    
    // Car는 사용자 정의 타입(클래스) 이기 때문에, 컴파일러는 << 연산을 어떻게 해야 할지 모르기 때문에 에러가 발생
    // 이 문장이 문법적으로 가능하고 의미 있게 동작하는 이유
    // 출력 연산자 오버로딩 함수 덕분
    cout << car1 << endl;
    cout << car2 << endl;

    Car c1;
    c1.setManufacturer("Toyota");
    c1.setModel("Camry");
    c1.setSpeed(70);

    cout << "기본 생성자로 생성된 차량 정보:" << endl;
    cout << c1 << endl;

    return 0;
}
