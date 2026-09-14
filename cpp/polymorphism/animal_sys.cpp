#include <iostream>

class Animal {
    public:
        virtual void speak() {
            std::cout<<"Այս կենդանին ձայն է հանում"<<std::endl;
        }
        virtual ~Animal() = default;
};

class Dog:public Animal {
    public:
        void speak() override{
            std::cout << "Հաֆ-հաֆ!" << std::endl;
        }
};

class Cat:public Animal {
    public:
        void speak()override{
            std::cout<< "Մյաու-մյաու!" << std::endl;
        }

};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();
    myDog->speak();
    myCat->speak();
    delete myCat;
    delete myDog;

    return 0;
}