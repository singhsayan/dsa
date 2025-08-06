#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) {
        this->value = v;
    }

    void show() const {
        cout << "Value: " << value << endl;
    }

    void operator ++() {
        ++value;
    }

    MyClass operator ++(int) {
        MyClass temp = *this;
        value++;
        return temp;
    }
};

int main() {
    MyClass obj1(10), obj2(20);

    cout << "Initial values:" << endl;
    obj1.show();
    obj2.show();

    ++obj1;
    cout << "After prefix increment (obj1):" << endl;
    obj1.show();

    obj2 = obj1++;
    cout << "After postfix increment (obj1):" << endl;
    obj1.show();
    cout << "Value of obj2 after assignment:" << endl;
    obj2.show();

    return 0;
}