#include <iostream> 
#include <string>
#include <vector>

class Sensor{
    public:
        virtual double readData() {
            return 0.0;
        }
        virtual std::string getType(){
        return "chlp";
        }
        virtual ~Sensor()= default;
};

class TemperatureSensor:public Sensor{
    public:
        double readData() override {
            return 24.5;
        }
        std::string getType()override{
            return "Ջերմաստիճան";
        }
};

class MotionSensor:public Sensor{
    bool detect;
    public:
        MotionSensor(bool d):detect(d){}
        std::string getType() override{
            return "Շարժման սենսոր";
        }
        double readData() override{
            if(detect){return 1.0; }
            else{return 0.0; }
        }

};

int main() {
    std::vector<Sensor*> sen;
    
    sen.push_back(new MotionSensor(true));
    sen.push_back(new TemperatureSensor);
    
    for(int i = 0; i< sen.size(); ++i){
        std::cout<<"type: " << sen[i]->getType() << " data: " << sen[i]->readData()<<std::endl;
    }
    return 0;
}
