#include <iostream>
using namespace std;

class Test {
private:
    int value;

public:
    Test(int v = 0) : value(v) {}

    friend void operator-(Test &x);
    
    void display() const {
        cout << "Value: " << value << endl;
    }
};

void operator-(Test &x) {
    x.value = -(x.value);  // Using 'this' pointer to access the member
}

int main() {
    Test x1(5);
    x1.display();
    
    -x1;  // Applying the overloaded operator
    x1.display();

    return 0;
}