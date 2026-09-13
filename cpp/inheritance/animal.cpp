#include <iostream>
#include <string>

class Animal {
    private:
        std::string name;
        int age;
    public:
       
};

class Cat:public Animal{
    bool patched;
};

class Dog:public Animal{
    private:
        std::string breed;
};

class Bird:public Animal{
    private:
        bool canfly;
};
