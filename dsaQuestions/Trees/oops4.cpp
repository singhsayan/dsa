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

    Distance operator+(const Distance& d) {
        int totalInches = (feet + d.feet) * 12 + (inches + d.inches);
        return Distance(totalInches / 12, totalInches % 12);
    }

    Distance operator-(const Distance& d) {
        int totalInches = (feet - d.feet) * 12 + (inches - d.inches);
        return Distance(totalInches / 12, totalInches % 12);
    }

    Distance operator*(int multiplier) {
        int totalInches = ((feet * 12 + inches) * multiplier);
        return Distance(totalInches / 12, totalInches % 12);
    }

    Distance operator/(int divisor) {
        int totalInches = (feet * 12 + inches) / divisor;
        return Distance(totalInches / 12, totalInches % 12);
    }

    bool operator<(const Distance& d) const {
        if (feet < d.feet) return true;
        if (feet == d.feet && inches < d.inches) return true;
        return false;
    }

    bool operator>(const Distance& d) const {
        return !(*this < d) && !(*this == d);
    }

    bool operator==(const Distance& d) const {
        return (feet == d.feet && inches == d.inches);
    }

    bool operator<=(const Distance& d) const {
        return (*this < d) || (*this == d);
    }

    bool operator&&(const Distance& d) const {
        return (feet && d.feet) && (inches && d.inches);
    }

    bool operator||(const Distance& d) const {
        return (feet || d.feet) || (inches || d.inches);
    }

    void display() const {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 10), d2(3, 4), d3;
    
    d3 = d1 + d2;
    d3.display();

    d3 = d1 - d2;
    d3.display();

    d3 = d1 * 2;
    d3.display();

    d3 = d1 / 2;
    d3.display();

    if (d1 < d2) cout << "d1 is smaller than d2" << endl;
    if (d1 > d2) cout << "d1 is greater than d2" << endl;
    if (d1 == d2) cout << "d1 is equal to d2" << endl;
    if (d1 <= d2) cout << "d1 is less than or equal to d2" << endl;

    if (d1 && d2) cout << "Both d1 and d2 have non-zero values" << endl;
    if (d1 || d2) cout << "Either d1 or d2 has a non-zero value" << endl;

    return 0;
}