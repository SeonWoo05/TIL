#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* manufacturer;
    char* model;
    double weight;
    int length;
    int width;
    int speed;

public:
    Car();
    Car(const char* m, const char* mod, double w, int l, int wdt, int s);
    ~Car();

    void setManufacturer(const char* m);
    const char* getManufacturer() const; // get은 return으로 주니까

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

    const char* getSegment();
    void checkSpeeding(int speedLimit);
    void checkSpeeding();

    friend ostream& operator<<(ostream& os, const Car& car);
};

// =============================
// 멤버 함수 정의
// =============================

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

Car::Car(const char* m, const char* mod, double w, int l, int wdt, int s) {
    manufacturer = new char[strlen(m) + 1]; // 문자열의 길이(문자 수)만 계산하고, 널 종료 문자 포함하지 않음
    strcpy(manufacturer, m); // 따라서 +1 해서 할당해줘야함.
    // 하지만 strcpy는 널문자까지 복사하기에 그냥 복사하면 됨.

    model = new char[strlen(mod) + 1];
    strcpy(model, mod);

    weight = w;
    length = l;
    width = wdt;
    speed = s;
}

Car::~Car() {
    delete[] manufacturer;
    delete[] model;
}

void Car::setManufacturer(const char* m) {
    delete[] manufacturer;
    manufacturer = new char[strlen(m) + 1];
    strcpy(manufacturer, m);
}

const char* Car::getManufacturer() const { // 뒤의 const는 이 멤버 함수가 객체의 멤버를 변경하지 않음을 보장한다는 의미
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

double Car::getWeight() const { // 여기도 const는 붙음
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

void Car::checkSpeeding(int speedLimit) {
    if (speed > speedLimit)
        cout << "과속 경고! (제한 속도: " << speedLimit << " km/h)" << endl;
    else
        cout << "정상 주행" << endl;
}

void Car::checkSpeeding() {
    checkSpeeding(60); // 인자가 없으면 
}

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
// 메인 함수 (동적 객체 사용)
// =============================
int main() {
    // 자동차 객체 동적 생성 (이렇게 하면 heap에 생성됨)
    Car* car1 = new Car("Hyundai", "Sonata", 1400, 4600, 1800, 95);
    Car* car2 = new Car("BMW", "M3", 1200, 4500, 1700, 110);

    // 멤버 변경
    // . : 멤버 접근 연산자
    // -> : 포인터 멤버 접근 연산자
    car1->setSpeed(80);
    car2->setManufacturer("Mercedes");

    cout << "수정된 차량 정보:" << endl;
    cout << *car1 << endl;
    cout << *car2 << endl;

    // 기본 생성자 사용
    Car* c1 = new Car();
    c1->setManufacturer("Toyota");
    c1->setModel("Camry");
    c1->setSpeed(70);

    cout << "기본 생성자로 생성된 차량 정보:" << endl;
    cout << *c1 << endl;

    // 동적 객체 해제 (소멸자 호출)
    delete car1;
    delete car2;
    delete c1;

    return 0;
}
