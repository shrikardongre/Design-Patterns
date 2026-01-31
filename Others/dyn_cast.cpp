#include <iostream> 
using namespace std ;

class Shape {
public:
    virtual ~Shape() = default;           // polymorphic!
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    double area() const override { return 3.14 * r * r; }
    double r = 5.0;
};

class Rectangle : public Shape {
public:
    double area() const override { return w * h; }
    double w = 4, h = 6;
};

void printIfCircle(Shape* s) {
    // Safe downcast
    Circle* c = dynamic_cast<Circle*>(s);
    
    if (c != nullptr) {
        std::cout << "It's a circle! radius = " << c->r << "\n";
    } else {
        std::cout << "Not a circle\n";
    }
}

int main() {
    Shape* shapes[2] = { new Circle, new Rectangle };

    for (auto s : shapes) {
        printIfCircle(s);
    }

    // Output:
    // It's a circle! radius = 5
    // Not a circle
}
