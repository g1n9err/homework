#include <iostream>
#include <utility>

class Date {
private:
    int* hour;
    int* minute;

public:
    // Default Constructor
    Date() : hour(new int(0)), minute(new int(0)) {}

    // Parametric Constructor
    Date(int h, int m) : hour(new int((h % 24 + 24) % 24)), minute(new int(m)) {
        if (*minute >= 60) {
            *hour = (*hour + *minute / 60) % 24;
            *minute %= 60;
        }
    }

    //Copy Constructor 
    Date(const Date& other) : hour(new int(*other.hour)), minute(new int(*other.minute)) {}

    //Move Constructor
    Date(Date&& other) noexcept : hour(other.hour), minute(other.minute) {
        other.hour = nullptr;
        other.minute = nullptr;
    }

    //Copy Assignment Operator
    Date& operator=(const Date& other) {
        if (this != &other) {
            *hour = *other.hour;
            *minute = *other.minute;
        }
        return *this;
    }

    //Move Assignment Operator
    Date& operator=(Date&& other) noexcept {
        if (this != &other) {
            delete hour;
            delete minute;

            hour = other.hour;
            minute = other.minute;

            other.hour = nullptr;
            other.minute = nullptr;
        }
        return *this;
    }

    //Destructor
    ~Date() {
        delete hour;
        delete minute;
    }

    //Prefix ++
    Date& operator++() {
        *hour = (*hour + 1) % 24;
        return *this;
    }

    //Postfix ++
    Date operator++(int) {
        Date temp(*this);
        ++(*this);
        return temp;
    }

    // Prefix --
    Date& operator--() {
        *hour = (*hour - 1 + 24) % 24;
        return *this;
    }

    // Postfix --
    Date operator--(int) {
        Date temp(*this);
        --(*this);
        return temp;
    }

    //Operator +
    Date operator+(const Date& other) const {
        int totalMinutes = *minute + *other.minute;
        int extraHours = totalMinutes / 60;
        int newMinute = totalMinutes % 60;

        int newHour = (*hour + *other.hour + extraHours) % 24;

        return Date(newHour, newMinute);
    }

    //Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Date& d) {
        if (d.hour && d.minute) {
            os << "Hour " << *d.hour << " Minute " << *d.minute;
        } else {
            os << "Invalid Date (Null pointers)";
        }
        return os;
    }
};

int main() {

}
