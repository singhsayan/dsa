#include <iostream>
using namespace std;

class Time {
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0) : h(h), m(m), s(s) {}

    Time operator+(Time const &obj) {
        Time t;
        t.s = s + obj.s;
        t.m = m + obj.m + t.s / 60;  // carry over the seconds to minutes
        t.s = t.s % 60;  // keep seconds less than 60
        t.h = h + obj.h + t.m / 60;  // carry over the minutes to hours
        t.m = t.m % 60;  // keep minutes less than 60
        return t;
    }

    void show() const {
        cout << "Time: " << h << " hours, " << m << " minutes, " << s << " seconds" << endl;
    }
};

int main() {
    Time t1(5, 15, 34), t2(9, 53, 58), t3;
    t3 = t1 + t2;
    t3.show();

    return 0;
}