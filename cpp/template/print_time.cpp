#include <iostream>

template <int N,typename T>
    void printNTimes(T val){
        for (int i{}; i < N; ++i) {
            std::cout << val << " " << std::endl;
        }
    }
int main() {
    printNTimes<3>(10);
    printNTimes<5>('A');
    return 0;
}
