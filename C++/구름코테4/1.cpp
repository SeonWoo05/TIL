#include <iostream>
#include <string>

using namespace std;

/*-------------------------------------------------
 * 1. Beverage (추상 클래스)
 *------------------------------------------------*/
class Beverage {
protected:
    string name;
    int    price;
public:
    Beverage(const string& name, int price) : name(name), price(price) {}
    virtual ~Beverage() {}

    virtual void show() const = 0;

    const string& getName() const { return name; }
    int  getPrice()              { return price; }
    void setPrice(int p)         { price = p;  }
};

/*-------------------------------------------------
 * 2. MilkBase  (virtual 다이아몬드 방지용)
 *------------------------------------------------*/
class MilkBase : virtual public Beverage {
protected:
    string milkType;
    bool   isFoamed;
public:
    MilkBase(const string& name, int price,
             const string& milkType, bool isFoamed)
        : Beverage(name, price),
          milkType(milkType), isFoamed(isFoamed) {}
};

/*-------------------------------------------------
 * 3. Coffee
 *------------------------------------------------*/
class Coffee : virtual public Beverage {
protected:
    string beanOrigin;
public:
    Coffee(const string& name, int price,
           const string& beanOrigin)
        : Beverage(name, price), beanOrigin(beanOrigin) {}

    void show() const override {
        cout << "커피: " << name
             << " (" << beanOrigin << ") - "
             << price << "원";
    }
};

/*-------------------------------------------------
 * 4. Tea
 *------------------------------------------------*/
class Tea : virtual public Beverage {
protected:
    string teaType;
public:
    Tea(const string& name, int price,
        const string& teaType)
        : Beverage(name, price), teaType(teaType) {}

    void show() const override {
        cout << "차: "  << name
             << " ("    << teaType << ") - "
             << price << "원";
    }
};

/*-------------------------------------------------
 * 5. Latte  (Coffee + MilkBase)
 *------------------------------------------------*/
class Latte : public Coffee, public MilkBase {
public:
    Latte(const string& name, int price,
          const string& beanOrigin,
          const string& milkType, bool isFoamed)
        : Beverage(name, price),
          Coffee(name, price, beanOrigin),
          MilkBase(name, price, milkType, isFoamed) {}

    void show() const override {
        cout << "라떼: " << name
             << " ("    << beanOrigin << " + "
             << milkType << ") - "
             << price << "원 ["
             << (isFoamed ? "폼 있음" : "폼 없음") << "]";
    }
};

/*-------------------------------------------------
 * 6. MilkTea (Tea + MilkBase)
 *------------------------------------------------*/
class MilkTea : public Tea, public MilkBase {
public:
    MilkTea(const string& name, int price,
            const string& teaType,
            const string& milkType, bool isFoamed)
        : Beverage(name, price),
          Tea(name, price, teaType),
          MilkBase(name, price, milkType, isFoamed) {}

    void show() const override {
        cout << "밀크티: " << name
             << " ("      << teaType  << " + "
             << milkType << ") - "
             << price << "원 ["
             << (isFoamed ? "폼 있음" : "폼 없음") << "]";
    }
};

/*-------------------------------------------------
 * 7. Utility – print by reference
b가 실제로 Latte 객체라면 Latte의 show()가,
MilkTea 객체라면 MilkTea의 show()가 호출되어,
각 서브 클래스의 모든 정보(원두, 우유, 폼 여부 등)가 출력됩니다.
 *------------------------------------------------*/
void printByReference(const Beverage& b) {
    b.show();
    cout << endl;
}

/*-------------------------------------------------
 * 8. BeverageStocks
 *------------------------------------------------*/
class BeverageStocks {
private:
    static const int N = 10;
    Beverage* beverages[N];
    int       count = 0;
public:
    BeverageStocks() {};

    ~BeverageStocks() {
        for (int i = 0; i < count; ++i) delete beverages[i];
    }

    void add(Beverage* arr[], int size) {
        for (int i = 0; i < size && count < N; ++i)
            beverages[count++] = arr[i];
        cout << "[음료 추가 완료]" << endl;
    }

    void delBeverage(const string& name) {
        for (int i = 0; i < count; ++i) {
            if (beverages[i]->getName() == name) {
                delete beverages[i];
                for (int j = i; j < count - 1; ++j)
                    beverages[j] = beverages[j + 1];
                --count;
                cout << "[삭제된 음료 : " << name << "]" << endl;
                return;
            }
        }
        cout << "[음료 없음]" << endl;
    }

    void update(const string& name, int price) {
        for (int i = 0; i < count; ++i) {
            if (beverages[i]->getName() == name) {
                cout << "[음료 가격 변경 : " << name << " "
                     << beverages[i]->getPrice() << "원 -> "
                     << price << "원]" << endl;
                beverages[i]->setPrice(price);
                return;
            }
        }
        cout << "[음료 없음]" << endl;
    }

    void search(const string& name) {
        for (int i = 0; i < count; ++i) {
            if (beverages[i]->getName() == name) {
                printByReference(*beverages[i]); // 역참조를 위해서 포인터를 넘긴게 아니라 객체를 넘김.
                return;
            }
        }
        cout << "[음료 없음]" << endl;
    }

    void showAll() {
        for (int i = 0; i < count; ++i) {
            beverages[i]->show();
            cout << endl;
        }
    }
};

/*-------------------------------------------------
 * 9. Main
 *------------------------------------------------*/
enum Menu { ADD = 1, DELETE, UPDATE, SEARCH, PRINTALL, EXIT };

int main() {
    const int numBeverages = 7;
    Beverage* beverages[numBeverages];
    BeverageStocks stock;

    // 초기 데이터
    beverages[0] = new Coffee("아메리카노", 3000, "에티오피아 예가체프");
    beverages[1] = new Coffee("콜드브루",   4900, "에티오피아 블렌드");
    beverages[2] = new Tea   ("얼그레이티", 3800, "얼그레이");
    beverages[3] = new Tea   ("우롱티",     3500, "우롱");
    beverages[4] = new Latte ("카페모카",   5000, "과테말라 안티구아", "초코 우유", true);
    beverages[5] = new Latte ("카페라떼",   4800, "에티오피아 예가체프", "우유", true);
    beverages[6] = new MilkTea("우롱밀크티", 6000, "우롱", "우유", true);

    int selection;
    while (true) {
        cout << "----------------------------------\n메뉴 입력: ";
        cin  >> selection;
        cout << "----------------------------------" << endl;

        string name;
        switch (static_cast<Menu>(selection)) {
        case ADD:
            stock.add(beverages, numBeverages);
            break;

        case DELETE:
            cout << "삭제할 음료 이름을 입력하세요: ";
            cin  >> name;
            stock.delBeverage(name);
            break;

        case UPDATE: {
            int price;
            cout << "변경할 음료 이름을 입력하세요: ";
            cin  >> name;
            cout << "변경할 가격을 입력하세요: ";
            cin  >> price;
            stock.update(name, price);
            break;
        }
        case SEARCH:
            cout << "검색할 음료 이름을 입력하세요: ";
            cin  >> name;
            stock.search(name);
            break;

        case PRINTALL:
            cout << "[모든 음료 리스트]" << endl;
            stock.showAll();
            break;

        case EXIT:
            cout << "[프로그램종료]";
            return 0;
        }
    }
    return 0;
}