#include <iostream>

using namespace std;

class Complex {

    int real;
    int imag;

  public:
    Complex() {}
    Complex(int real, int imag) {
        this->real = real;
        this->imag = imag;
    }
    Complex operator+(Complex c2) {
        Complex temp;
        temp.real = this->real + c2.real;
        temp.imag = this->imag + c2.imag;
    }

    void print() { cout << this->real << " + " << this->imag << "i" << endl; }
};

int main() {
    Complex c1(1, 2);

    Complex c2(3, 4);

    // Complex c3 = c1 + c2;

    // cout << c3.real << " "<<c3.imag;

    return 0;
}