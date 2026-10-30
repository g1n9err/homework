#include <iostream>

template<int N>
    constexpr bool isEven() {
        return N % 2 == 0;
}

int main() {
    static_assert(isEven<10>());
    static_assert(!isEven<7>());  

    return 0;
}
