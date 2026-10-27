#include <iostream> 

template<typename T,size_t N>
void  printArray(T(&arr)[N]) {
    for(size_t i{}; i < N; ++i){
        std::cout <<arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int a[] = {1, 2, 3};
    double b[] = {1.1, 2.2, 3.3};
    char c[] = {'a', 'b', 'c'};

    printArray(a);
    printArray(b);
    printArray(c);

    return 0;
}
