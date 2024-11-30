#include <iostream>
#include <memory>

class Angestellter {
public:
    virtual ~Angestellter() {std::cout << "Angesteller zerstört" << std::endl;}

        virtual void print() {
            std::cout << "Angesteller" << std::endl;
        }
};

class Manager : public Angestellter {
public:
    ~Manager() {std::cout << "Manager zerstört" << std::endl;}

    void print() override final {
        std::cout << "Manager" << std::endl;
    }

    /*void foo() override {
        std::cout << "foo" << std::endl;
    }*/

};

class CTO : public Manager {
public:
    ~CTO() {std::cout << "CTO zerstört" << std::endl;}
    /*void print() override {
        std::cout << "CTO" << std::endl;
    }  */

};

class Abstract {
private:
    int x;

public:
    virtual void foo() = 0;
    virtual void goo(){};
};

class Concrete : public Abstract {
public:
    void foo() override {
        std::cout << "Concrete not abstract anymore" << std::endl;
    }
};

class Abstract2 : public Concrete {
public:
    void goo() override = 0;
};


class Konto {
public:
    double kontostand;
    double getKontostand() const{return kontostand;};
};

class Girokonto : virtual public Konto {
public:
};

class Sparkonto : virtual public Konto {
public:
};

class Kombokonto : public Sparkonto, public Girokonto {
public:

};


void output(Angestellter& a) {
    a.print();
}

int main() {

    /*Angestellter p1;
    Manager p2;

    /*p1.print();
    p2.print();*/

    /*output(p1);
    output(p2);*/

    std::unique_ptr<Angestellter> p = std::make_unique<Manager>();

    //Abstract a;
    Concrete c;
    c.foo();

    Abstract& ref = c;

    //Abstract2 a2;

    Kombokonto kk;
    kk.Girokonto::kontostand = 123;
    kk.Sparkonto::kontostand = 456;
   // kk.Konto::kontostand = 255;

    std::cout << kk.Girokonto::getKontostand() << std::endl;
    std::cout << kk.Sparkonto::getKontostand() << std::endl;

    return 0;
}
