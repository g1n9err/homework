#include <iostream>

template<int N, typename T>
T power(T val) {
    T result = 1;
    for(int i{}; i < N; ++i) {
        result *= val;
    }
    return result;
}

int main() {
    std::cout << power<3>(2) << std::endl;
    std::cout << power<4>(3) << std::endl;
    std::cout << power<0>(10) << std::endl;
    return 0;
}
