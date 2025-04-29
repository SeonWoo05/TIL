#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class Car {
private:
    char* manufacturer;
    char* model;
    double weight;
    int speed;

public:
    
    void print() const {
        cout << manufacturer << " " << model << ", " << weight << "kg, " << speed << "km/h" << endl;
    }
};

enum Menu {
    FindUpdateShow = 1,
    Sort,
    EXIT
};
int main() {
    const int SIZE = 7;
    Car* cars[SIZE];
    cars[0] = new Car("현대", "Avante", 1250.5, 180);
    cars[1] = new Car("기아", "K5", 1300.0, 190);
    cars[2] = new Car("테슬라", "Model3", 1610.3, 250);
    cars[3] = new Car("벤츠", "E300", 1680.2, 240);
    cars[4] = new Car("BMW", "530i", 1655.0, 245);
    cars[5] = new Car("현대", "Sonata", 1430.7, 200);
    cars[6] = new Car("기아", "Sportage", 1500.0, 210);

    int command;
    cin >> command;


        case FindUpdateShow: {

            target.print();
            break;
        }

        case Sort:

            break;

        case EXIT:
            cout << "[프로그램 종료]" << endl;
            break;




    return 0;
}
