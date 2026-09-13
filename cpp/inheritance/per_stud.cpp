#include <iostream>
#include <string>

class Person {
private:
    int age;
    std::string name;

public:
    // constructors
    Person() : age(0), name("") {}
    Person(std::string name, int age) : name(std::move(name)), age(age) {}

    // Getter - Setter
    int getAge() const {
        return age;
    }

    void setAge(int new_age) {
        if (new_age > 0) {
            age = new_age;
        }
    }

    const std::string& getName() const {
        return name;
    }

    void setName(std::string new_name) {
        name = std::move(new_name);
    }

    void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : public Person {
private:
    int stub_num;
    std::string uni;

public:
    // constructors
    Student() : Person(), stub_num(0), uni("") {}
    Student(std::string name, int age, std::string uni, int stub_num)
        : Person(name, age), uni(std::move(uni)), stub_num(stub_num) {}

    // Getter - Setter
    int getStubNum() const { return stub_num; }
    void setStubNum(int num) { stub_num = num; }

    const std::string& getUni() const { return uni; }
    void setUni(std::string new_uni) { uni = std::move(new_uni); }

    void printStudentInfo() const {
        printInfo();
        std::cout << "University: " << uni << ", Student ID: " << stub_num << std::endl;
    }

    void changeUniversity(std::string new_uni) {
        uni = std::move(new_uni);
    }

    void changeUniversity(std::string new_uni, int new_stub_num) {
        uni = std::move(new_uni);
        stub_num = new_stub_num;
    }
};

int main() {
    // --- Person class test ---
    std::cout << "=== Person tests ===" << std::endl;

    Person p1; // default constructor
    p1.printInfo(); // Name: , Age: 0

    Person p2("Anna", 25); // parameterized constructor
    p2.printInfo(); // Name: Anna, Age: 25

    p2.setAge(30);
    p2.setName("Anna Petrosyan");
    p2.printInfo(); // Name: Anna Petrosyan, Age: 30

    p2.setAge(-5); // invalid value, should be ignored
    p2.printInfo(); // Age stays 30, since setAge only accepts positive numbers

    std::cout << "Age via getAge(): " << p2.getAge() << std::endl;
    std::cout << "Name via getName(): " << p2.getName() << std::endl;

    std::cout << std::endl;

    // --- Student class test ---
    std::cout << "=== Student tests ===" << std::endl;

    Student s1; // default constructor
    s1.printStudentInfo();

    Student s2("Davit", 20, "YSU", 12345); // parameterized constructor
    s2.printStudentInfo();

    s2.setStubNum(54321);
    s2.setUni("AUA");
    s2.printStudentInfo();

    std::cout << "Uni via getUni(): " << s2.getUni() << std::endl;
    std::cout << "StubNum via getStubNum(): " << s2.getStubNum() << std::endl;

    // Test inherited Person methods on a Student object
    s2.setName("Davit Hakobyan");
    s2.setAge(21);
    s2.printInfo(); // inherited from Person

    // Test the two changeUniversity overloads
    s2.changeUniversity("Yerevan State University");
    s2.printStudentInfo(); // uni changes, stub_num stays the same

    s2.changeUniversity("Polytechnic", 99999);
    s2.printStudentInfo(); // both uni and stub_num change

    return 0;
}
