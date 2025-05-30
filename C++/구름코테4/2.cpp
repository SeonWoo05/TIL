#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// --- Item 및 하위 클래스 ---
class Item {
protected:
    string name;
    double price;
    int stockQuantity;
public:
    Item(const string& name, double price, int stock)
        : name(name), price(price), stockQuantity(stock) {}
    virtual ~Item() {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }
    void reduceStock(int quantity) {
        if (stockQuantity >= quantity)
            stockQuantity -= quantity;
        else
            cout << "Insufficient stock for " << name << endl;
    }
    virtual void show() const {
        cout << name << " - W" << price << " 재고량: " << stockQuantity;
    }
};

class Book : public Item {
protected:
    string author, publisher;
public:
    Book(const string& name, const string& author, const string& publisher, double price, int stock)
        : Item(name, price, stock), author(author), publisher(publisher) {}
    void show() const override {
        cout << "[Book] " << name << " (" << author << ", " << publisher << ") - W" << price << " 재고:" << stockQuantity;
    }
};

class Bag : public Item {
    string model, color;
public:
    Bag(const string& name, const string& model, const string& color, double price, int stock)
        : Item(name, price, stock), model(model), color(color) {}
    void show() const override {
        cout << "[Bag] " << name << " (" << model << ", " << color << ") - W" << price << " 재고:" << stockQuantity;
    }
};

class EBook : public Book {
    string media, capacity;
public:
    EBook(const string& name, const string& media, const string& capacity, const string& author, const string& publisher, double price, int stock)
        : Book(name, author, publisher, price, stock), media(media), capacity(capacity) {}
    void show() const override {
        cout << "[EBook] " << name << " (" << author << ", " << publisher << ", " << media << ", " << capacity << ") - W" << price << " 재고:" << stockQuantity;
    }
};

// --- Customer 및 하위 클래스 ---
class Customer {
protected:
    string name;
public:
    Customer(const string& name) : name(name) {}
    virtual ~Customer() {}
    string getName() const { return name; }
    virtual double applyDiscount(double price) const = 0;
};

class RegularCustomer : public Customer {
    string city;
    int mileage;
public:
    RegularCustomer(const string& name, const string& city, int mileage)
        : Customer(name), city(city), mileage(mileage) {}
    double applyDiscount(double price) const override {
        return price * 0.03; // 3% 할인
    }
};

class VIPCustomer : public Customer {
    double discountRate;
public:
    VIPCustomer(const string& name, double discountRate)
        : Customer(name), discountRate(discountRate) {}
    double applyDiscount(double price) const override {
        return price * discountRate;
    }
};

// --- Order ---
class Order {
    static const int N = 20;
    Customer* customer;
    Item* items[N]{};
    int quantities[N]{};
    int count = 0;
public:
    Order(Customer* customer) : customer(customer) {}
    string getCustomerName() const { return customer->getName(); }
    void addItem(Item* item, int quantity) {
        if (count < N) {
            items[count] = item;
            quantities[count] = quantity;
            item->reduceStock(quantity);
            ++count;
        }
    }
    void printOrderSummary() const {
        cout << "\n=== 주문 요약 ===\n";
        cout << "고객: " << customer->getName() << endl;
        double total = 0;
        for (int i = 0; i < count; ++i) {
            double basePrice = items[i]->getPrice();
            double discount = customer->applyDiscount(basePrice);
            double finalPrice = basePrice - discount;
            total += finalPrice * quantities[i];
            cout << fixed << setprecision(2);
            cout << "- ";
            items[i]->show();
            cout << " x " << quantities[i]
                 << "개: 원가 W" << basePrice
                 << ", 할인 W" << discount
                 << ", 최종 W" << finalPrice << endl;
        }
        cout << "총 지불 금액: W" << total << endl;
    }
    bool matchCustomer(string target) const {
        return customer->getName() == target;
    }
    bool operator>(const Order& other) const {
        return customer->getName() > other.customer->getName();
    }
};

// --- OrderTable ---
class OrderTable {
    static const int N = 20;
    Order* orders[N];
    int count = 0;
public:
    OrderTable() {}
    ~OrderTable() {
        for (int i = 0; i < count; ++i) delete orders[i];
    }
    void add(Order* o) {
        if (count < N) orders[count++] = o;
    }
    void printAll() const {
        cout << "\n=== 전체 주문 출력 ===\n";
        for (int i = 0; i < count; ++i)
            orders[i]->printOrderSummary();
    }
    Order* search(string name) {
        for (int i = 0; i < count; ++i)
            if (orders[i]->matchCustomer(name))
                return orders[i];
        return nullptr;
    }
    int remove(string name) {
        int delCount = 0;
        for (int i = 0; i < count; ) {
            if (orders[i]->matchCustomer(name)) {
                delete orders[i];
                for (int j = i; j < count-1; ++j)
                    orders[j] = orders[j+1];
                --count;
                ++delCount;
            } else {
                ++i;
            }
        }
        return delCount;
    }
    void sort() {
        for (int i = 0; i < count-1; ++i) {
            for (int j = 0; j < count-i-1; ++j) {
                if (*orders[j] > *orders[j+1]) {
                    Order* tmp = orders[j];
                    orders[j] = orders[j+1];
                    orders[j+1] = tmp;
                }
            }
        }
    }
};

// --- main ---
enum Menu { INPUT = 1, PRINT, SEARCH, DELETE, SORT, EXIT };

int main() {
    OrderTable table;
    Item* items[] = {
        new Book("자바의정석", "남궁성", "도우출판", 30000, 50),
        new EBook("알고리즘", "PDF", "2GB", "홍길동", "한빛", 25000, 100),
        new Bag("에코백", "Large", "화이트", 12000, 80)
    };
    Customer* rc = new RegularCustomer("홍길동", "서울", 1000);
    Customer* vip = new VIPCustomer("이순신", 0.1);

    Order* order1 = new Order(rc);
    order1->addItem(items[0], 1);
    order1->addItem(items[2], 2);

    Order* order2 = new Order(vip);
    order2->addItem(items[1], 1);

    int select;
    while (true) {
        cout << "\n1. 객체 입력, 2. 전체 출력, 3. 검색, 4. 삭제, 5. 정렬, 6. 종료: ";
        cin >> select;

        switch (static_cast<Menu>(select)) {
        case INPUT:
            table.add(order1);
            table.add(order2);
            cout << "주문 입력 완료.\n";
            break;

        case PRINT:
            table.printAll();
            break;

        case SEARCH: {
            string name;
            cout << "검색할 고객명: ";
            cin >> name;
            Order* found = table.search(name);
            if (found) found->printOrderSummary();
            else cout << name << " 을(를) 찾을 수 없습니다.\n";
            break;
        }

        case DELETE: {
            string name;
            cout << "삭제할 고객명: ";
            cin >> name;
            int count = table.remove(name);
            cout << "삭제된 주문 수: " << count << "\n";
            break;
        }

        case SORT:
            table.sort();
            cout << "정렬 완료.\n";
            break;

        case EXIT:
            return 0;
        }
    }
}
