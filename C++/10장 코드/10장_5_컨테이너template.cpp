#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // 템플릿 컨테이너가 최대 100개까지 객체 포인터를 저장하도록 크기를 한정

// ====================================
// 템플릿 객체 테이블 클래스 정의
// ====================================
template <typename T> // 형식 매개변수 T—컨테이너에 담을 “기본 타입(베이스 클래스)” 지정
class ObjectTable {
private:
    T* data[MAX]; // 서로 다른 T의 파생형을 담아도 ‘슬라이싱’ 발생 X. -- why?
                  // 파생 클래스가 가진 추가 데이터(멤버 변수)와 가상 함수 테이블 정보가 잘려 나간 채 기반 클래스 부분만 복사된다. ????
                  // 정렬·삭제 시 주소만 교환/해제 ↔ 값 복사보다 효율적
    int size;

public:
    ObjectTable() : size(0) { // 클래스의 데이터 멤버(member) 를 초기화하는 문법
        for (int i = 0; i < MAX; i++)
            data[i] = nullptr;
    }

    ~ObjectTable() { // 컨테이너가 파괴될 때 소유한 모든 객체를 delete. 가상 소멸자를 가진 T라면 파생 클래스까지 안전하게 삭제
        for (int i = 0; i < size; i++)
            delete data[i];
    }

    void add(T* obj) {
        if (size < MAX) 
            data[size++] = obj; // 현재 위치에 포인터 저장
        else
            cout << "📛 테이블 용량 초과\n";
    }

    void remove(int index) {
        if (index >= 0 && index < size) {
            delete data[index]; // 실객체 해제
            for (int i = index; i < size - 1; i++)
                data[i] = data[i + 1]; // 뒤 원소 한 칸씩 앞으로
            data[--size] = nullptr; // size 감소 & 꼬리 null
        }
    }

    void update(int index, T* obj) {
        if (index >= 0 && index < size) {
            delete data[index];
            data[index] = obj;
        }
    }

    int search(T* target) {
        for (int i = 0; i < size; i++)
            if (*data[i] == *target) // 값 비교
                return i;
        return -1;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (*data[i] > *data[j])
                    swap(data[i], data[j]); // 주소를 교환
    }

    void showAll() const {
        for (int i = 0; i < size; i++)
            data[i]->show(); // 가상 show() 호출
    }
};

// ====================================
// Vehicle 클래스 계층
// ====================================
class Vehicle {
protected:
    string model;
public:
    Vehicle(string m) : model(m) {}
    virtual void show() const {
        cout << "🚗 Vehicle: " << model << endl; // 공통 속성: model
    }
    virtual string getModel() const { return model; }
    virtual bool operator>(const Vehicle& other) const {
        return model > other.model;
    }
    virtual bool operator==(const Vehicle& other) const {
        return model == other.model;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int year;
public:
    Car(string m, int y) : Vehicle(m), year(y) {}
    void show() const override {
        //////////////////////////////////////////////////////////////////////
        Vehicle::show(); // 부모 부분 출력
        cout << ", Year: " << year << endl; // 이렇게 해라
        //cout << "🚘 Car: " << model << ", Year: " << year << endl;
    }
    bool operator>(const Vehicle& other) const override {
        if (model == other.getModel()) {
            const Car* pCar = dynamic_cast<const Car*>(&other); // dynamic cast 빼면 어떻게 되는지
            /*
            논리적 비교 규칙은 모델명이 같으면 연식(year)이 큰 Car가 우선.
            year 멤버에 접근하려면 other가 실제로 Car인가? 를 먼저 확인하고 맞다면 Car* 로 안전하게 바꿔야 한다.
            
            정적(컴파일 타임) 타입은 언제나 Vehicle => 런타임에 “other 가 실제로 Car냐?” 를 점검해야 함
            이때 사용하는 것이 dynamic_cast.getModel

            업캐스트는 그냥 가능한데, 다운캐스트는 그게 아니라서 검사
            */
            return pCar ? year > pCar->year : false; // pCar가 null-ptr인지 검사하고, 참이면 조건식 결과 반환, 거짓이면 false 반환.
        }
        return model > other.getModel();
    }
    bool operator==(const Vehicle& other) const override {
        if (model != other.getModel()) return false;
        const Car* pCar = dynamic_cast<const Car*>(&other);
        return pCar && year == pCar->year;
    }
};

class Truck : public Vehicle {
    int capacity;
public:
    Truck(string m, int c) : Vehicle(m), capacity(c) {}
    void show() const override {
        cout << "🚚 Truck: " << model << ", Capacity: " << capacity << " ton" << endl;
    }
    bool operator>(const Vehicle& other) const override {
        if (model == other.getModel()) {
            const Truck* pTruck = dynamic_cast<const Truck*>(&other);
            return pTruck ? capacity > pTruck->capacity : false;
        }
        return model > other.getModel();
    }
    bool operator==(const Vehicle& other) const override {
        if (model != other.getModel()) return false;
        const Truck* pTruck = dynamic_cast<const Truck*>(&other);
        return pTruck && capacity == pTruck->capacity;
    }
};

// ====================================
// Animal 클래스 계층
// ====================================
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void show() const {
        cout << "🐾 Animal: " << name << endl;
    }
    virtual string getName() const { return name; }
    virtual bool operator>(const Animal& other) const {
        return name > other.name;
    }
    virtual bool operator==(const Animal& other) const {
        return name == other.name;
    }
    virtual ~Animal() {}
};

class Dog : public Animal { //////////////////////////// 이부분 이해해보기
    int age;
public:
    Dog(string n, int a) : Animal(n), age(a) {}
    void show() const override {
        cout << "🐶 Dog: " << name << ", Age: " << age << endl;
    }
    bool operator>(const Animal& other) const override {
        if (name == other.getName()) {
            const Dog* pDog = dynamic_cast<const Dog*>(&other);
            return pDog ? age < pDog->age : false; // 나이 적은 순 우선
        }
        return name > other.getName();
    }
    bool operator==(const Animal& other) const override {
        if (name != other.getName()) return false;
        const Dog* pDog = dynamic_cast<const Dog*>(&other);
        return pDog && age == pDog->age;
    }
};

class Cow : public Animal {
    double weight;
public:
    Cow(string n, double w) : Animal(n), weight(w) {}
    void show() const override {
        cout << "🐄 Cow: " << name << ", Weight: " << weight << "kg" << endl;
    }
    bool operator>(const Animal& other) const override {
        if (name == other.getName()) {
            const Cow* pCow = dynamic_cast<const Cow*>(&other);
            return pCow ? weight > pCow->weight : false;
        }
        return name > other.getName();
    }
    bool operator==(const Animal& other) const override {
        if (name != other.getName()) return false;
        const Cow* pCow = dynamic_cast<const Cow*>(&other);
        return pCow && weight == pCow->weight;
    }
};

// ====================================
// main 함수
// ====================================
int main() {
    ObjectTable<Vehicle> vTable; // T = Vehicle 이므로 컨테이너는 Vehicle* 배열을 가짐
    // <> 안에 t 대신에 넘겨줄 것 넣은게 컨테이너 클래스이다! 내부적으로 클래스가 두개 만들어짐
    vTable.add(new Car("Avante", 2020));
    vTable.add(new Truck("Porter", 2));
    vTable.add(new Car("Avante", 2018)); // 같은 이름, 다른 연도
    vTable.add(new Truck("Porter", 3));  // 같은 이름, 다른 용량

    cout << "\n[🚗 Vehicle 목록 (정렬 전)]\n";
    vTable.showAll();

    vTable.sort();
    cout << "\n[🚗 Vehicle 목록 (정렬 후)]\n";
    vTable.showAll();

    ObjectTable<Animal> aTable;
    aTable.add(new Dog("Buddy", 3));
    aTable.add(new Cow("Milky", 250.5));
    aTable.add(new Dog("Buddy", 2));     // 같은 이름, 나이 비교
    aTable.add(new Cow("Milky", 270.2)); // 같은 이름, 무게 비교

    cout << "\n[🐾 Animal 목록 (정렬 전)]\n";
    aTable.showAll();

    aTable.sort();
    cout << "\n[🐾 Animal 목록 (정렬 후)]\n";
    aTable.showAll();

    return 0;
}
