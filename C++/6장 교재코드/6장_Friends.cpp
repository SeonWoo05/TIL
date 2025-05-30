#include <iostream>
#include <cstring>

using namespace std;

/*──────────────────────── Vehicle ────────────────────────*/
class Vehicle {
protected:
    double engineSize;
    int    speed;

public:
    Vehicle(double e = 0.0, int s = 0) {
        engineSize = e;
        speed      = s;
    }

    void showSpecs() const {
        cout << "Engine: " << engineSize << "L, Speed: "
             << speed << "km/h";
    }
};

/*───────── 사전 선언 (friend·포워드) ─────────*/
class Car;                       // UsedCar에서 필요
class UsedCar;
bool isExpensive(const Car&, int, int);

/*──────────────────────── Car ───────────────────────────*/
class Car : public Vehicle {
private:
    char* manufacturer;   // 동적 문자열 → Rule of Three 필요
    char* model;
    int   madeYear;
    int   price;

public:
    /* friend 선언 */
    friend class UsedCar;                         // 재고 관리자가 내부 데이터 열람
    friend bool isExpensive(const Car&, int, int); // 외부 가격 판별 함수

    /* 일반 생성자 */
    Car(const char* m  = "",  const char* md = "",
        int  y = 0,          int  p  = 0,
        double e = 0.0,      int  s  = 0) {
        // Vehicle 부분 직접 대입
        engineSize = e;
        speed      = s;

        madeYear = y;
        price    = p;

        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);

        model = new char[strlen(md) + 1];
        strcpy(model, md);
    }

    /* 복사 생성자 ― 깊은 복사 */
    Car(const Car& other) {
        // Vehicle 부분 복사
        engineSize = other.engineSize;
        speed      = other.speed;

        madeYear = other.madeYear;
        price    = other.price;

        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);

        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    /* 대입 연산자 ― 깊은 복사 */
    Car& operator=(const Car& other) {
        if (this != &other) {
            // Vehicle 부분 복사
            engineSize = other.engineSize;
            speed      = other.speed;

            madeYear = other.madeYear;
            price    = other.price;

            delete[] manufacturer;
            delete[] model;

            manufacturer = new char[strlen(other.manufacturer) + 1];
            strcpy(manufacturer, other.manufacturer);

            model = new char[strlen(other.model) + 1];
            strcpy(model, other.model);
        }
        return *this;
    }

    /* 소멸자 */
    ~Car() {
        delete[] manufacturer;
        delete[] model;
    }

    /* 출력 */
    void show() const {
        cout << manufacturer << ' ' << model
             << " (" << madeYear << "), "
             << price << "만원 | ";
        showSpecs();
        cout << '\n';
    }
};

/*────────────────── friend 함수: 고가 + 노후 차 판별 ─────────────────*/
bool isExpensive(const Car& c, int priceThreshold, int currentYear) {
    return (c.price > priceThreshold) &&            // 가격이 높고
           (c.madeYear <= currentYear - 5);         // 5년 이상 경과
}

/*──────────────────────── UsedCar ────────────────────────*/
class UsedCar {
private:
    Car* stock;
    int  numberCars;

public:
    /* 생성자: 외부 Car 배열을 깊게 복사 */
    UsedCar(Car* cars, int n) {
        numberCars = n;
        stock = new Car[numberCars];
        for (int i = 0; i < numberCars; ++i)
            stock[i] = cars[i];         // Car::operator= 호출 → 깊은 복사
    }

    ~UsedCar() { delete[] stock; }

    void showAllCars() const {
        cout << "\n[전체 차량 목록]\n";
        for (int i = 0; i < numberCars; ++i)
            stock[i].show();
    }

    void showExpensiveOldCars(int minPrice, int currentYear) const {
        cout << "\n[5년 이상 경과 & " << minPrice << "만원 초과 차량]\n";
        for (int i = 0; i < numberCars; ++i)
            if (isExpensive(stock[i], minPrice, currentYear))
                stock[i].show();
    }
};

/*──────────────────────── main ───────────────────────────*/
int main() {
    Car cars[5] = {
        Car("Hyundai", "Grandeur", 2018, 3200, 2.4, 180),
        Car("Kia",     "K5",       2019, 2500, 1.6, 170),
        Car("Renault", "SM6",      2021, 2300, 1.8, 160),
        Car("GM",      "Malibu",   2017, 3100, 2.0, 175),
        Car("KGM",     "Torres",   2020, 3600, 1.5, 165)
    };

    UsedCar store(cars, 5);                // 재고 초기화(깊은 복사)
    store.showAllCars();

    store.showExpensiveOldCars(3000, 2025); // 5년↑ & 3000만원↑ 차량만 표시
    return 0;
}
