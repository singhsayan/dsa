#include <iostream>
using namespace std;

class Distance {
private:
    int x, y;

public:
    Distance(int x = 0, int y = 0) : x(x), y(y) {}

    Distance operator+(const Distance& d) {
        Distance temp;
        temp.x = this->x + d.x;
        temp.y = this->y + d.y;
        return temp;
    }

    void display() const {
        cout << "Distance: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Distance d1(10, 20), d2(30, 40), d3;
    d3 = d1 + d2;
    d3.display();

    return 0;
}