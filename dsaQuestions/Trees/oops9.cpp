#include <iostream>
using namespace std;

class Test {
private:
    float value;

public:
    // Constructor to initialize the value
    Test(float v = 0.0) : value(v) {}

    // Conversion operator to convert Test object to float, using 'this' pointer
    operator float() {
        return this->value;  // Using 'this' pointer to access the member variable
    }

    void display() const {
        cout << "Value in Test object: " << this->value << endl;  // Using 'this' pointer to access the member variable
    }
};

int main() {
    Test t(5.67);  // Create Test object with value 5.67
    t.display();

    // Convert Test object to float using the conversion operator
    float num = t;  // Implicitly calls the operator float()
    cout << "Converted value to float: " << num << endl;

    return 0;
}