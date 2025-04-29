#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Complex {
private:
    float real;
    float imaginary;

    float magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

public:
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imaginary = i;
    }

    void print() const {
        cout << fixed << setprecision(2);
        cout << real << " + " << imaginary << " i";
    }

    void printWithMagnitude() const {
        print();
        cout << " (magnitude: " << fixed << setprecision(2) << magnitude() << ")";
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        float r = real * other.real - imaginary * other.imaginary;
        float i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    friend void sortByMagnitude(Complex* table[], int size);
};

float randomFloat() {
    return static_cast<float>(rand()) / RAND_MAX * 10.0f;
}

void generateComplex(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        float r = randomFloat();
        float i_ = randomFloat();
        table[i] = new Complex(r, i_);
    }
}

Complex sumComplex(Complex* table[], int size) {
    Complex sum;
    for (int i = 0; i < size; ++i) {
        sum = sum + *table[i];
    }
    return sum;
}

Complex multiplyComplex(Complex* table[], int size) {
    Complex prod(1, 0);
    for (int i = 0; i < size; ++i) {
        prod = prod * *table[i];
    }
    return prod;
}

void sortByMagnitude(Complex* table[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            float mag1 = table[j]->magnitude();
            float mag2 = table[j + 1]->magnitude();
            if (mag1 > mag2) {
                Complex* temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
    cout << "Sorted by Magnitude:" << endl;
    for (int i = 0; i < size; ++i) {
        table[i]->printWithMagnitude();
        cout << endl;
    }
}

void showComplexWithMagnitude(Complex* table[], int size) {
    cout << "Complex Numbers:" << endl;
    for (int i = 0; i < size; ++i) {
        table[i]->print();
        cout << endl;
    }
}

void freeTable(Complex* table[], int size) {
    for (int i = 0; i < size; ++i) {
        delete table[i];
    }
}

enum Menu { SHOW_COMPLEX = 1, SUM, PRODUCT, SORT, EXIT };

int main() {
    int seed, command;
    cin >> seed >> command;
    srand(seed);

    const int N = 5;
    Complex* table[N];
    generateComplex(table, N);

    switch (command) {
        case SHOW_COMPLEX:
            showComplexWithMagnitude(table, N);
            break;

        case SUM: {
            Complex sum = sumComplex(table, N);
            cout << "Sum: ";
            sum.print();
            cout << endl;
            break;
        }

        case PRODUCT: {
            Complex product = multiplyComplex(table, N);
            cout << "Product: ";
            product.print();
            cout << endl;
            break;
        }

        case SORT:
            sortByMagnitude(table, N);
            break;

        case EXIT:
            cout << "[Program terminated.]" << endl;
            break;

        default:
            cout << "[Invalid command]" << endl;
    }

    freeTable(table, N);
    return 0;
}