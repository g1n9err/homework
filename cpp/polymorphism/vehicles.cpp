#include <iostream>

class Vehicle {
public:
    virtual void startEngine() {
        std::cout << "Շարժիչը միացված է" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Մեքենայի շարժիչը գործարկվեց բանալիով" << std::endl;
    }
};

class ElectricCar : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Էլեկտրամեքենան միացավ լուռ (լիցքը պատրաստ է)" << std::endl;
    }
};
void testVehicle(Vehicle* v) {
    v->startEngine();
}

int main() {
    Car c1;
    testVehicle(&c1);
    ElectricCar c2;
    testVehicle(&c2);

    return 0;
}
