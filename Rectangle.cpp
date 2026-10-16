#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    Rectangle() : width(0.0), length(0.0) {}

    void setWidth(double w) {
        if (w >= 0) width = w;
        else cout << "Width cannot be negative!"<<endl;
    }

    void setLength(double l) {
        if (l >= 0) length = l;
        else cout << "Length cannot be negative!"<<endl;
    }

    double getWidth() const { return width; }
    double getLength() const { return length; }
  
    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * (width + length); }
};

int main() {
    Rectangle rect;

    rect.setWidth(5.0);
    rect.setLength(10.0);

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Length: " << rect.getLength() << endl;
    cout << "Area: " << rect.calculateArea() << endl;
    cout << "Perimeter: " << rect.calculatePerimeter() << endl;

    return 0;
}