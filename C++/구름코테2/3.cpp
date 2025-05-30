#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Car {
private:
    char* manufacturer;
    char* model;
    double weight;
    int speed;

public:
    Car(const char* m, const char* mod, double w, int s) {
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);

        model = new char[strlen(mod) + 1];
        strcpy(model, mod);

        weight = w;
        speed = s;
    }

    ~Car() {
        delete[] manufacturer;
        delete[] model;
    }

    void setManufacturer(const char* m) {
        delete[] manufacturer;
        manufacturer = new char[strlen(m) + 1];
        strcpy(manufacturer, m);
    }

    void setModel(const char* mod) {
        delete[] model;
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    }

    const char* getManufacturer() const { 
        return manufacturer;
    }

    const char* getModel() const {
        return model;
    }

    double getWeight() const {
        return weight;
    }
    
    int getSpeed() const {
        return speed;
    }

    void print() const {
        cout << manufacturer << " " << model << ", "
             << weight << "kg, " << speed << "km/h" << endl;
    }
};

Car& findLightestFastCar(Car* cars[], int n) {
    Car* target = nullptr;
    for (int i = 0; i < n; ++i) {
        if (cars[i]->getSpeed() >= 200) {
            if (target == nullptr || cars[i]->getWeight() < target->getWeight()) {
                target = cars[i];
            }
        }
    }
    return *target; // *target은 Car 객체 그 자체이고, target은 Car* (포인터)
}

/*
정렬하려는 대상은 Car 객체의 내부 값이 아니라, 배열 내의 포인터 순서입니다.
포인터를 **교환(swap)**하는 것만으로도 정렬이 이뤄집니다.
객체의 내부를 바꾸는 것이 아니라 배열의 구조만 바꾸는 것이기 때문에 참조는 필요 없음
*/

void sortCars(Car* cars[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            int cmp = strcmp(cars[j]->getManufacturer(), cars[j + 1]->getManufacturer());
            if (cmp > 0 || (cmp == 0 && strcmp(cars[j]->getModel(), cars[j + 1]->getModel()) > 0)) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}

enum Menu { FindUpdateShow = 1, Sort, EXIT };

int main() {
    const int SIZE = 7;
    Car* cars[SIZE] = {
        new Car("현대", "Avante", 1250.5, 180),
        new Car("기아", "K5", 1300.0, 190),
        new Car("테슬라", "Model3", 1610.3, 250),
        new Car("벤츠", "E300", 1680.2, 240),
        new Car("BMW", "530i", 1655.0, 245),
        new Car("현대", "Sonata", 1430.7, 200),
        new Car("기아", "Sportage", 1500.0, 210)
    };
    
	int command;
	
    while (true) {
		cout << "\n1. FindUpdateShow\n2. Sort\n3. EXIT\n";
        cout << "Select menu: ";
        cin >> command;
			
        switch (static_cast<Menu>(command)) {
		    case FindUpdateShow: {
                Car& target = findLightestFastCar(cars, SIZE); // cars[]에 들어 있는 진짜 객체를 수정하기 위해
                target.setManufacturer("차세대");
                target.setModel("혁신");
                target.print();
                break;
	        }
        
			case Sort: {
                sortCars(cars, SIZE);
                for (int i = 0; i < SIZE; ++i)
                    cars[i]->print();
                break;
	        }
					
	        case EXIT: {
                for (int i = 0; i < SIZE; ++i)
                    delete cars[i];
                return 0;
	        }
		}
	}
}
