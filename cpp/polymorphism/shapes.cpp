#include <iostream>
#include <vector>

class Shape{
    public:
        virtual double area() {
            return 0.0;
        }
};

class Rectangle:public Shape{
    private:
        double height;
        double width;
    public:
        double  area() override {
            return width * height;
        }
        Rectangle(double w, double h){
            width = w;
            height =h;
        }
};

class Circle:public Shape {
    private:
        double radius;
    public:
        Circle(double r):radius(r){}
        double area() override{
            return 3.14 * radius * radius;
        }
        
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(3));
    shapes.push_back(new Rectangle(4,5));

    for(int i = 0; i < shapes.size(); ++i){
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }

    return 0;
}
