#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* manufacturer;
    char* licensePlate;
    int speed;
    static int count;

public:
    // 기본 생성자 (Default Constructor)
    Car() {
        manufacturer = new char[8];  // "Unknown"을 저장할 충분한 공간 (길이 7 + 1)
        strcpy(manufacturer, "Unknown");

        licensePlate = new char[5];  // "None"을 저장할 공간 (길이 4 + 1)
        strcpy(licensePlate, "None");

        speed = 0;
        ++count;
        cout << "Default Constructor 호출" << endl;
    }

    // 일반 생성자 (Parameterized Constructor)
    Car(const char* manufacturer, const char* licensePlate, int speed) {
        this->manufacturer = new char[strlen(manufacturer) + 1];
        strcpy(this->manufacturer, manufacturer);

        this->licensePlate = new char[strlen(licensePlate) + 1];
        strcpy(this->licensePlate, licensePlate);

        this->speed = speed;
        ++count;
        cout << "Parameterized Constructor 호출" << endl;
    }

    // 복사 생성자 (Deep Copy)
    Car(const Car& other) {
        // 동적 메모리 할당 후 내용을 복사하여 각각의 객체가 독립적인 메모리를 갖도록 함
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);

        licensePlate = new char[strlen(other.licensePlate) + 1];
        strcpy(licensePlate, other.licensePlate);

        speed = other.speed;
        ++count;
        cout << "Copy Constructor 호출 (Deep Copy)" << endl;
    }

    // 대입 연산자 (Assignment Operator) - Deep Copy 구현
    Car& operator=(const Car& other) {
        
        // 기존 동적 메모리 해제
        delete[] manufacturer;
        delete[] licensePlate;

        // 새 메모리 할당 후 deep copy
        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);

        licensePlate = new char[strlen(other.licensePlate) + 1];
        strcpy(licensePlate, other.licensePlate);

        speed = other.speed;
        
        return *this;
    }

    // 소멸자 (Destructor)
    ~Car() {
        cout << "Destructor 호출: " << manufacturer << " (" << licensePlate << ")" << endl;
        delete[] manufacturer;
        delete[] licensePlate;
        --count;
    }

    // setters
    Car& setManufacturer(const char* m) {
        delete[] manufacturer;  // 기존 메모리 해제
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
        return *this;
    }

    Car& setLicensePlate(const char* l) {
        delete[] licensePlate;
        licensePlate = new char[strlen(l) + 1];
        strcpy(licensePlate, l);
        return *this;
    }

    Car& setSpeed(int s) {
        speed = s;
        return *this;
    }

    // show: 객체 정보 출력
    void show() const {
        cout << "제조사: " << manufacturer
             << ", 번호판: " << licensePlate
             << ", 속도: " << speed << " km/h"
             << ", 전체 객체 수: " << count << endl;
    }

    // getters
    const char* getManufacturer() const {
        return manufacturer;
    }

    static int getCount() {
        return count;
    }
};

int Car::count = 0;

// 제조사 기준 정렬 함수 (버블 정렬)
void sortByManufacturer(Car* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            // 문자열 비교는 strcmp 사용
            if (strcmp(arr[j].getManufacturer(), arr[j + 1].getManufacturer()) > 0) {
                // swap: 임시 객체를 이용한 교환 (대입 연산자와 복사 생성자가 deep copy 수행)
                Car temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ===================== main =====================
int main() {
    const int SIZE = 3;
    // 힙에 Car 객체 배열 생성 (기본 생성자 호출, 3번)
    Car* carSet = new Car[SIZE];

    // 각각의 객체 정보를 setter로 갱신
    carSet[0].setManufacturer("Hyundai").setLicensePlate("12가3456").setSpeed(100);
    carSet[1].setManufacturer("Toyota").setLicensePlate("78나9012").setSpeed(120);
    carSet[2].setManufacturer("Kia").setLicensePlate("34다5678").setSpeed(90);

    cout << "\n=== Car 객체 정보 (정렬 전) ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].show();
    }

    // 제조사 기준 정렬 수행
    sortByManufacturer(carSet, SIZE);

    cout << "\n=== Car 객체 정보 (제조사 기준 정렬 후) ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        carSet[i].show();
    }

    cout << "\n현재 전체 Car 객체 수: " << Car::getCount() << endl;

    // 힙에 할당된 배열 해제 (소멸자 자동 호출)
    delete[] carSet;
    cout << "\n객체 삭제 후 수: " << Car::getCount() << endl;

    return 0;
}
