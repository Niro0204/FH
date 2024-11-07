#include <iostream>
#include <memory>

class Demo {
private:
    int value;
public:
    Demo() {
        //init();
        value = 0;
    };

    // explicit verhindert die verwendung eines converting constructors
    explicit Demo(int value) : Demo() { // delegating constructor
        //init();
        if(value>=0 && value <= 10) {
            this->value = value;
        }
    }

    // converting constructor

    Demo(int value, int value2) : Demo() {
        this->value = value;

        //do something
    }

    operator bool() const {

        if(value<5) {
            return true;
        }
        else {
            return false;
        }
    }

    /*void init() {
        value = 0;
    }
    */
};

class Server {
private:
    std::string ip;

public:
    Server(const std::string& ip) : ip{ip} {}
    void setIP(const std::string& ip) {this->ip = ip;}
    auto getIP() const {return ip;}
};

class Automat {
private:
    std::shared_ptr<Server> server;

public:
    void setServer(std::shared_ptr<Server> server) {this->server = server;}
    auto getServer() const {return server;}

    // copy constructor
    Automat(){}
    Automat(const Automat& a) {
        server = std::make_shared<Server>("127.0.0.2");
    }
};

int main() {
    auto a = new Demo();
    auto b = new Demo(5);

    Demo d1(5, 4);
    //Demo d2 = 3; // geht nicht, weil explicit -> kein passender converting constructor
    Demo d3 = (Demo)7;

    auto server = std::make_shared<Server>("172.0.0.1");
    Automat a1;
    a1.setServer(server);

    Automat a2 = a1; // flache kopie eines objektes, alle member sind referenzen // durch copy constructor wird es eine tiefe kopie


    std::cout << "a1: " << a1.getServer()->getIP() << std::endl;

    a2.getServer()->setIP("127.0.0.2");

    std::cout << "a1: " << a1.getServer()->getIP() << std::endl;
    std::cout << "a2: " << a2.getServer()->getIP() << std::endl;

    return 0;
}
