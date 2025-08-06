#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int real = 0, int imag = 0) : real(real), imag(imag) {}

    Complex operator+(Complex const &obj) {
        Complex c;
        c.real = real + obj.real;
        c.imag = imag + obj.imag;
        return c;
    }

    void display() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6), c3;
    c3 = c1 + c2;
    c3.display();

    return 0;
}