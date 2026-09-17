#include <iostream>
#include <string>
#include <vector>

class IPrintable{
    public:
        virtual void  print() = 0;
        virtual ~IPrintable() = default;
};

class ISerializable{
    public:
        virtual std::string serialize() = 0;
        virtual ~ISerializable() = default;

};

class Document : public IPrintable, public ISerializable {
    private:
        std::string title;
    public:
        Document(std::string t) {
            title = t;
        }
        void print() override {
            std::cout << "printing document: " << title << std::endl;
        }
        std::string serialize() override {
            return "title: " + title;
        }
    };

class Image : public IPrintable{
    private:
        std::string fileName;
    public:
        Image(std::string f):fileName(f){}
        void print() override{
            std::cout << "printing image: " << fileName << std::endl;
        }
};
class Video : public IPrintable {
private:
    std::string vidName;
public:
    Video(std::string v) : vidName(v){} 
    void print() override {
        std::cout << "playing video: " << vidName << std::endl;
    }
};

void checkSerializable(IPrintable* ptr) {
    ISerializable* serPtr = dynamic_cast<ISerializable*>(ptr);
    if (serPtr != nullptr) {
        std::cout << "this obj is serializable: " << serPtr->serialize() << std::endl;
    } else {
        std::cout << "this obj is not serializable." << std::endl;
    }
}

int main() {
    IPrintable* p1 = new Document("Report");
    IPrintable* p2 = new Image("photo.jpg");
    IPrintable* p3 = new Video("clip.mp4");

    checkSerializable(p1);
    checkSerializable(p2); 
    checkSerializable(p3); 

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
