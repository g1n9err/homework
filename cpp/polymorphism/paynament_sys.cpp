#include <iostream>
#include <vector>

class PaymentMethod{
    public:
        virtual void processPayment(double amount) {
            std::cout<<"Վճարումը մշակվում է:"<<std::endl;
        }
};

class CreditCard:public PaymentMethod{
    public:
        void processPayment(double amount) override {
            std::cout << "Վճարվեց "<< amount<< " դրամ բանկային քարտով" <<std::endl;
        }
};

class PayPal:public PaymentMethod{
    public:
        void processPayment(double amount) override {
            std::cout << "Վճարվեց" << amount << "դրամ PayPal հաշվի միջոցով";
        } 
};

int main() {
    std::vector<PaymentMethod*>m;
    m.push_back(new CreditCard);
    m.push_back(new PayPal);
    for(int i = 0; i < m.size(); ++i) {
        m[i]->processPayment(100.0);
    }

    return 0;
}