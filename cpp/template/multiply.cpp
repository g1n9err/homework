#include <iostream>
#include <iomanip>      // std::fixed / std::setprecision
#include <string>

template <typename T, typename U>
T multiply(T a, U b) {
    return a * b;       
}


template <>
std::string multiply<std::string, int>(std::string s, int n) {
    std::string result;
    for (int i{}; i < n; ++i) {
        result += s;            
    }
    return result;        
}

int main() {
    std::cout << multiply(5, 3) << '\n';                      // 15
    std::cout << std::fixed << std::setprecision(2)
              << multiply(2.345, 3.0) << '\n';               // 7.04
    std::cout << multiply(std::string("Hi"), 3) << '\n';      // HiHiHi

    return 0;
}
