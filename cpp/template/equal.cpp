#include <iostream>

template <typename T, size_t N>
int countEqual(T (&arr)[N], T value) {
    int count{};
    for (size_t i{}; i < N; i++) {
        if (arr[i] == value) {
            count++; 
        }
    }    
    return count; 
}

int main() {
    int arr[] = {1, 2, 1, 3, 1};
    
    std::cout << countEqual(arr, 1) << std::endl; 
    
    return 0;
}
