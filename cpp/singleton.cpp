#include <iostream>

class Singleton {
    private:
        inline static Singleton* instance = nullptr;
        
        Singleton() {}
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton(); 
            }
            return instance; 
        }
};

int main() {
    Singleton* sig = Singleton::getInstance();
    Singleton* sig1 = Singleton::getInstance();

    std::cout << "sig-i hascen: " << sig << std::endl;
    std::cout << "sig1-i hascen: " << sig1 << std::endl;

    if (sig == sig1) {
        std::cout << "cuyca talis nuyn obj i vra:" << std::endl;
    } else {
        std::cout << "tarber obj ner en:" << std::endl;
    }

    return 0;
}
