#include <iostream>

class Uniqueptr{
    int* ptr;
    public:
        Uniqueptr(int* p = nullptr):ptr(p){} 
        ~Uniqueptr() {
            delete ptr;
        }
        Uniqueptr(const Uniqueptr&) = delete;
        Uniqueptr& operator=(const Uniqueptr&) = delete;
        Uniqueptr(Uniqueptr&& other) : ptr(other.ptr) { other.ptr = nullptr; }
        Uniqueptr& operator =(Uniqueptr&& other){
            if(this != &other){
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }
        int* getptr () const {return ptr;}
        int* release() {
            int* r = ptr;
            ptr = nullptr;
            return r;
        }
        void reset(int* p = nullptr) {
            if (ptr != p) {
                delete ptr;
                ptr = p;
            }
        }
        int& operator*() const { return *ptr; }
        int* operator->() const { return ptr; }
};

int main() {
    Uniqueptr a(new int(42));
    std::cout << *a << "\n";              // 42

    Uniqueptr b = std::move(a);           // move constructor
    std::cout << (a.getptr() == nullptr) << " " << *b << "\n";  // 1 42

    Uniqueptr c;
    c = std::move(b);                     // move assignment
    std::cout << *c << "\n";              // 42

    c.reset(new int(7));
    std::cout << *c << "\n";              // 7

    int* raw = c.release();
    std::cout << (c.getptr() == nullptr) << " " << *raw << "\n";  // 1 7
    delete raw;
}
