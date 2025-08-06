#include <iostream>
#include <cmath> // for cos and sin functions
using namespace std;

class Polar {
private:
    float radius, angle;

public:
    // Constructor to initialize Polar coordinates
    Polar(float r, float theta) : radius(r), angle(theta) {}

    // Getter functions to access radius and angle
    float getRadius() const { return radius; }
    float getAngle() const { return angle; }
};

class Cartesian {
private:
    float x, y;

public:
    // Conversion constructor to convert Polar to Cartesian
    Cartesian(const Polar& p) {
        // Convert Polar to Cartesian coordinates
        x = p.getRadius() * cos(p.getAngle());
        y = p.getRadius() * sin(p.getAngle());
    }

    // Function to display Cartesian coordinates
    void show() const {
        cout << "Cartesian Coordinates: x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Polar p(10, 5);  // Create a Polar object with radius 10 and angle 5
    Cartesian c = p; // Implicitly calls the conversion constructor
    c.show();        // Display the Cartesian coordinates

    return 0;
}