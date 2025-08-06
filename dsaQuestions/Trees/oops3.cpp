#include <iostream>
using namespace std;

class Distance {
private:
    int feet, inches;

public:
    Distance(int feet = 0, int inches = 0) {
        this->feet = feet;
        this->inches = inches;
    }

    Distance operator-() {
        feet = -feet;
        inches = -inches;
        return Distance(feet, inches);
    }

    void display() const {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(10, 20), d2;
    d2 = -d1;
    d2.display();

    return 0;
}