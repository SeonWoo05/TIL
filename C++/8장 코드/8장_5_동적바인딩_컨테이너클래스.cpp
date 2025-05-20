#include <iostream>
#include <cstring>
using namespace std;

// =========================
// Vehicle 추상 클래스
// =========================
class Vehicle {
protected:
    double engineSize;
    int speed;

public:
    Vehicle(double e = 0.0, int s = 0) : engineSize(e), speed(s) {}
    virtual ~Vehicle() {} // 가상 소멸자
    virtual void show() const = 0;  // 순수 가상 함수
    /// virtual 유무의 차이 이해하기
    /// =0 표기는 가상함수 선언만하고 함수 body는 이 클래스에서 구현하지 않는다.
    /// Vehicle 객체를 생성할 수 없다 => 추상클래스 (9장 다시 공부)
};

// =========================
// Car 클래스
// =========================
class Car : public Vehicle {
private:
    char* model;
    int year;

public:
    Car(const char* m, int y, double e, int s)
        : Vehicle(e, s), year(y) {
        model = new char[strlen(m) + 1];
        strcpy(model, m);
    }

    ~Car() override {
        delete[] model;
    }

    void show() const override { // override?
        cout << "🚗 Car - Model: " << model << ", Year: " << year
            << ", Engine: " << engineSize << "L, Speed: " << speed << "km/h\n";
    }
};

// =========================
// Truck 클래스
// =========================
class Truck : public Vehicle {
private:
    double capacity;

public:
    Truck(double e, int s, double c)
        : Vehicle(e, s), capacity(c) {}

    void show() const override {
        cout << "🚚 Truck - Capacity: " << capacity << " tons, Engine: "
            << engineSize << "L, Speed: " << speed << "km/h\n";
    }
};

// =========================
// 차량 저장소 클래스 (정적 배열 사용)
// // 중고차 등록 저장 삭제 출력 ... 클래스 만들기
// =========================
class UsedVehicleStore {
private:
    Vehicle* table[10];  // 최대 10대 저장
    int count;

public:
    UsedVehicleStore() : count(0) {
        for (int i = 0; i < 10; ++i)
            table[i] = nullptr;
    }

    ~UsedVehicleStore() {
        for (int i = 0; i < count; ++i)
            delete table[i];  // 객체 메모리 해제
    }

   /* void delete(char* )*/
    Vehicle* search(char*);
    void add(Vehicle* v) {
        if (count < 10) {
            table[count++] = v;
        }
        else {
            cout << "저장소가 가득 찼습니다.\n";
        }
    }

    void showAll() const {
        cout << "\n[전체 차량 목록]\n";
        for (int i = 0; i < count; ++i) {
            table[i]->show();  // 🔥 동적 바인딩
        }
    }
};

// =========================
// 메인 함수
// =========================
int main() {
    UsedVehicleStore store;

    store.add(new Car("Avante", 2020, 1.6, 180));
    store.add(new Car("K5", 2018, 2.0, 170));
    store.add(new Truck(5.0, 140, 12.0));
    store.add(new Truck(3.5, 130, 8.5));

    store.showAll();
    //store.delete("현대"); // enum써서 메뉴만들고...
    
    return 0;
}