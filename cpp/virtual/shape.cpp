#include <iostream>

const double PI = 3.14159;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * PI * radius;
    }
    void draw() const override {
        std::cout << "Drawing Circle with radius " << radius << "\n";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void draw() const override {
        std::cout << "Drawing Rectangle " << width << "x" << height << "\n";
    }
};

class Triangle : public Shape {
    double sideA, sideB, sideC; 
    double base, height;        
public:
    Triangle(double a, double b, double c, double base, double height)
        : sideA(a), sideB(b), sideC(c), base(base), height(height) {}

    double area() const override {
        return 0.5 * base * height;
    }
    double perimeter() const override {
        return sideA + sideB + sideC;
    }
    void draw() const override {
        std::cout << "Drawing Triangle with base " << base << " and height " << height << "\n";
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5, 4, 3); 

    Shape* shapes[] = { &c, &r, &t };

    for (Shape* s : shapes) {
        s->draw();
        std::cout << "Area: " << s->area() << ", Perimeter: " << s->perimeter() << "\n\n";
    }

    return 0;
}
