#include <iostream>
#include <string>

class Employee {
    protected:
        std::string name;
    public:
        Employee(std::string n):name(n){}
        virtual double calculateSalary() {
            return 0.0;
        }
        std::string getName(){
            return name;
        }
};

class FullTimeEmployee : public Employee {
    private:
        double monthlySalary;
    public:
        FullTimeEmployee(std::string n, double salary) : Employee(n) {
            monthlySalary = salary;
    }
    double calculateSalary() override {
        return monthlySalary;
    }
};

class HourlyEmployee : public Employee{
    private:
        double hourlyRate;
        double hoursWorked;
    public:
        HourlyEmployee(std::string n, double hRate, double hWorked):Employee(n){
            hourlyRate = hRate;
            hoursWorked = hWorked;
        }
        double calculateSalary() override{
            return hourlyRate * hoursWorked;
        }

};

int main() {
    Employee* emp1 = new FullTimeEmployee("Anna",300000); 
    Employee* emp2 = new HourlyEmployee("Sona",1000, 8);
    std::cout << emp1->getName() << ": " << emp1->calculateSalary() << std::endl;
    std::cout << emp2->getName() << ": " << emp2->calculateSalary() << std::endl;

    return 0;
}
