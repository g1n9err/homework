#include <iostrem>
#include <string>

class Employee {
    private:
        std::string name;
    public:
        Employee(str::string n):name(n){}
        virtual calculateSalary() {
            return 0.0;
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

}
