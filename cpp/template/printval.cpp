#include <iostream>
#include <string>

template<typename T> 
void printValue( T n) {  
    std::cout << "Unknown type" << std::endl;
}

template<>
void printValue<int>(int val){
    std::cout << "integer: " << val << std::endl;    
}

template<>
void printValue<double>(double val){
    std::cout << "Double: " << std::fixed << std::setprecision(2) << val << std::endl;
}

template<>
void printValue<const char*>(const char* arr){
    std::string s(arr);
    for(char& c : s){
        if(c >= 'a' && c <= 'z'){
            c = c - 'a' + 'A';
        }
    }

    std::cout << "char*: " << s << std::endl;   
}

int main(){
    printValue(42);
    printValue(3.14159);
    printValue("helLo");
    printValue(std::string("Hello"));  
    printValue(3.14f);              

    return 0;
}
