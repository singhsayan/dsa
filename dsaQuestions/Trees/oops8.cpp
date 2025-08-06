#include <iostream>
using namespace std;

class Test {
private:
    float value;

public:
    // Constructor to convert float to Test object
    Test(float data) {
        value = data;
    }

    void display() const {
        cout << "Converted value: " << value << endl;
    }
};

int main() {
    float num = 5.67;
    
    // Convert float to Test object
    Test t(num);
    t.display();

    return 0;
}