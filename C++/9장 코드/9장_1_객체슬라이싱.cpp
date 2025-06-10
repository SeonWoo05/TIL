#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 Animal
class Animal {
protected:
    double weight;
    string color;

public:
    Animal(double w, const string& c) : weight(w), color(c) {}

    // 순수 가상 함수
    virtual void show()const {}

    // 가상 소멸자
    virtual ~Animal() {}
};

// Cow 클래스는 Animal을 상속
class Cow : public Animal {
private:
    int id;
    string owner;
    int age;

public:
    Cow(double w, const string& c, int i, const string& o, int a)
        : Animal(w, c), id(i), owner(o), age(a) {} /// 슈퍼클래스의 생성자를 부르고 내꺼는 뒤에 그대로 대입
    //override: 필수는 아니지만, 실수를 방지하고 가독성을 높이기 위해 항상 쓰는 것이 좋음
    void show()const override{
        cout << "Cow details:\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Color: " << color << endl;
        cout << "ID: " << id << endl;
        cout << "Owner: " << owner << endl;
        cout << "Age: " << age << " years\n";
    }
};

// MilkCow 클래스는 Cow을 상속
class MilkCow : public Cow {
private:
    int milkProduct;

public:
    MilkCow(double w, const string& c, int i, const string& o, int a, int m)
        : Cow(w, c, i, o, a), milkProduct(m) {} /// 상위 클래스 생성자 호출

    void show()const{ /// 밀크카우의 show는 카우의 show를 부름
        Cow::show();
        cout << "Milk Production: " << milkProduct << " liters/day\n";
    }
};

// Dog 클래스는 Animal을 상속
class Dog : public Animal {
private:
    int id;
    string owner;
    int age;

public:
    Dog(double w, const string& c, int i, const string& o, int a)
        : Animal(w, c), id(i), owner(o), age(a) {}

    void show() const {
        cout << "Dog details:\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Color: " << color << endl;
        cout << "ID: " << id << endl;
        cout << "Owner: " << owner << endl;
        cout << "Age: " << age << " years\n";
    }
};
/// 위를 지우고 animal에 Dog와 petdog 만들기
/// 각 서브 클래스의 데이터 멤버 어떤걸 만들어라 주어지면 생성하기
/// 다른 클래스에 하위 클래스 추가하는것도 나옴


/* 여기 중요
// slicing 발생 (subclass 정보 잘림)
void printByValue(Animal a) { //객체 값을 복사하여 전달: Animal 객체 부분만 복사되고 subclass 데이터 멤버는 잘림
    cout << "\n[SLICED VERSION: Passed by Value]\n";
    a.show();  // always calls Animal's base version (if not abstract)
}

// slicing 방지 (정상 polymorphism)
//참조로 전달하면 슬라이싱이 일어나지 않는 이유:
//참조(&)로 전달하면 객체 복사 없이 원래 객체를 가리키므로,
//파생 클래스 정보도 유지되고,
//슬라이싱이 발생하지 않으며,
//동적 바인딩이 제대로 작동.
void printByReference(const Animal& a) {
    cout << "\n[POLYMORPHIC VERSION: Passed by Reference]\n";
    a.show();  // virtual dispatch works correctly
}

// Animal 배열 출력
void showAll(Animal* animals[], int size) { /// 애니멀의 포인터를 전달받는데 포인터로 안받으면 어떤 문제가 발생하는지
    for (int i = 0; i < size; ++i) {
        animals[i]->show(); /// animals[i].show() 는 동적 바인딩 처리 안됨
        /// 객체면 동적바인딩 안하고 포인터면 동적 바인딩함
        cout << endl;
    }
}
*/

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // 동적 객체 생성
    animals[0] = new Cow(500, "Brown", 101, "John Doe", 5);
    animals[1] = new Cow(520, "Black", 102, "Alice Smith", 4);
    animals[2] = new Cow(480, "White", 103, "Bob Johnson", 6);

    animals[3] = new MilkCow(530, "Brown", 104, "Charlie Rose", 3, 20);
    animals[4] = new MilkCow(510, "Spotted", 105, "Diana Ross", 5, 25);
    animals[5] = new MilkCow(495, "White", 106, "Emily Clark", 4, 22);

    animals[6] = new Dog(30, "Black", 201, "Jane Smith", 3);
    animals[7] = new Dog(28, "Brown", 202, "Emily Davis", 2);
    animals[8] = new Dog(35, "White", 203, "Frank White", 4);
    animals[9] = new Dog(32, "Gray", 204, "Grace Lee", 5);

    cout << "\n▶▶ 모든 Animal 출력 (정상 polymorphism)\n";
    showAll(animals, numAnimals); /// 클래스의 멤버함수가 아니라 전역

    cout << "\n▶▶ 개별 객체 전달 실험\n";

    /// 객체를 복사해서 발생하면 animal말고 잘리는데 참조를 이용하면 올바른것에 접근하니까 문제없음!
    // slicing 발생
    printByValue(*animals[3]);      // MilkCow → Animal by value → slicing 발생
    printByValue(*animals[6]);      // Dog → Animal by value → slicing 발생

    // slicing 방지
    printByReference(*animals[3]);  // MilkCow → Animal& → polymorphism 유지
    printByReference(*animals[6]);  // Dog → Animal& → polymorphism 유지

    // 메모리 해제
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }
    int choice; 
    cin >> choice;
    return 0;
}
