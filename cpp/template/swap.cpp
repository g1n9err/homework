#include <iostream>

template <typename T>
void swapVal(T& a, T& b) { 
    T temp = a;            
    a = b;                 
    b = temp;             
}

int main() {
    int a = 20;
    int b = 40;

    swapVal(a, b);
    
    std::cout << a << " " << b << std::endl; 
    
    return 0;
}
