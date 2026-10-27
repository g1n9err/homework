#include <iostream> 

class score {
    int point;
    public:
        score(int b):point(b){}

        bool operator>(const score& other) const{
            return point > other.point;
        }

        friend std::ostream& operator<<(std::ostream& os, const score& s) {
            os << s.point;
            return os;
    }
};

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}


int main() {
    
    score a(83);
    score b(92);
    
    score  max = maximum(a, b);
    std::cout<<"max score: " << max <<std::endl; 

    std::cout << maximum(10,20) << std::endl;
    std::cout << maximum(3.5, 2.1) << std::endl;
    std::cout << maximum('d', 'a') << std::endl;
    std::cout << maximum<double>(10,2.5) << std::endl;
    
    return 0;
}


