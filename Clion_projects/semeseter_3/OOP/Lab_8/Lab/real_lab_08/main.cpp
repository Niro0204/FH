#include <iostream>
#include <cassert>

class MyException : public std::exception {
public:
    std::string fehlermeldung;

    /*const char* what () const override {
        return "Division by zero";
    }*/
};

double division(const double a,const double b) {
    double erg = 0;
    if (b != 0) {
        erg = a / b;
    }
    else {
        throw std::invalid_argument("division by zero, from invalid argument");
       // throw std::invalid_argument("Division by zero");
        //throw std::string("Division by zero, from string");
        //throw false;
        //MyException mec;
        // IMPORTANT: throw by value
        //throw mec;

    }
    return erg;
}

class Demo {
    public:
    Demo(){std::cout << "ich wurde erzeugt" << std::endl;}
    ~Demo() {
        std::cout << "ich wurde zerstört" << std::endl;
        //throw "Fehler";
    }
};

double foo(double a, double b) {
    try {
        return division(a,b);
    }
    catch (std::invalid_argument& e) {
        std::cerr << "exception from foo:" << e.what() << std::endl;
        //rethrow exeption
        throw;
    }

}

void doSomething(const int* ptr) {
    assert(ptr != nullptr); // darf nicht auftreten, kann aber unter umständen passieren
}

int main() {
    try {
        doSomething(nullptr);
        Demo demo;
        foo(5,0);
        std::cout << division(3, 0)<< std::endl;
        //delete demo;
    }
    catch (std::invalid_argument& e) {  // können durchaus auftreten, vllt durch falschen user input
        std::cerr << e.what() << std::endl;
    }
    catch (std::string& str) {
        std::cerr << str << std::endl;
    }
    catch(MyException& mec) {
        std::cerr << mec.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Error" << std::endl;
    }

    return 0;
}
