#include <iostream>
#include <string>

class IPrintable{
    public:
        virtual void  print() = 0;
        virtual ~IPrintable() = default;
};
class ISavable{
    public:
        virtual void save() = 0;
        virtual ~ISavable() = default; 
};
class ISerializable{
    public:
        virtual std::string serialize() = 0;
        virtual ~ISerializable() = default;

};

class Document : public IPrintable, public ISavable, public ISerializable {
    private:
        std::string title;
        std::string content;
    public:
        Document(std::string t, std::string c) {
            title = t;
            content = c;
        }
        void print() override {
            std::cout << "printing document: " << title << " - " << content << std::endl;
        }
        void save() override {
            std::cout << "document saved: " << title << std::endl;
        }
        std::string serialize() override {
            return "title: " + title + ", content: " + content ;
        }
    };  

class Image : public IPrintable, public ISavable, public ISerializable{
    private:
        std::string fileName;
        std::string resolution;
    public:
        Image(std::string f,std::string r):fileName(f),resolution(r) {}
        void print() override{
            std::cout << "printing image: " << fileName << " - " << resolution << std::endl;
        }
        void save() override {
            std::cout << "image saved: "  << fileName << std::endl;
        }
        std::string serialize() override {
            return "name: " + fileName + ", resolutin: " + resolution; 
        }
};

int main() {
    Document* doc = new Document("Report", "Important content here");
    Image* img = new Image("photo.jpg", "1920x1080");
    
    doc->print();
    doc->save();
    std::cout << doc->serialize() << std::endl;
    
    img->print();
    img->save();
    std::cout << img->serialize() << std::endl;
    
    delete doc;
    delete img;
    
    return 0;
}
