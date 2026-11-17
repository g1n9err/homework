#include <iostream>

template <typename T>
constexpr bool isPrimeConstexpr(T n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (T i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    // FIX․ փակվող փակագծերը և «;»-ները բաց էին մնացել
    static_assert(isPrimeConstexpr(29));
    static_assert(!isPrimeConstexpr(30));

    // FIX․ ֆունկցիայի անունը isPrimeConstexpr է, ոչ թե isPrime
    std::cout << "29 is prime: " << std::boolalpha << isPrimeConstexpr(29) << std::endl;
    std::cout << "100 is prime: " << isPrimeConstexpr(100) << std::endl;

    return 0;
}
