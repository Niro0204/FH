#include <iostream>
#include <vector>

class IPrintable{
public:
    virtual void print() = 0;

};

class Mensch : public IPrintable{
public:
    std::string name;

    void print(){std::cout<< "ich bin ein mensch"<< std::endl;}
    void beHuman(){
        std::cout<< "krass menschlich von mir"<< std::endl;
    }
};

class Tier : public IPrintable
{
public:
    std::string rasse;
    void print(){std::cout<< "ich bin ein tier"<< std::endl;}
};

class Fahrzeug : public IPrintable
{
public:
    std::string typ;
    void print(){std::cout<< "brum brum"<< std::endl;}
};


class Konto
{
public:
    double saldo;

    Konto operator+(const double betrag)
    {
        this->saldo += betrag;
        return *this;
    };

    Konto operator+=(Konto& b)
    {
        this->saldo += b.saldo;
        b.saldo = 0;
        return *this;
    }

    Konto& operator=(const Konto& b)
    {
        this->saldo = b.saldo;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& ostr,const Konto& k)
    {
       ostr << "das ist eine veränderte Ausgabe von Konto, Saldo: "<<k.saldo << std::endl;
        return ostr;
    }

    friend std::istream& operator>>(std::istream& istr, Konto& k)
    {
        istr >> k.saldo;
        return istr;
    }
};

std::string operator>>(std::string& str, int len)
{
    str.insert(0,len,' ');
    return str;
}


int main()
{
    std::vector<IPrintable*> collection;
    collection.push_back(new Mensch);
    collection.push_back(new Tier);


    for (auto& i : collection)
    {
        i->print();
        if(dynamic_cast<Mensch*>(i)!= nullptr)
        {
            dynamic_cast<Mensch*>(i)->beHuman();
        };
    }

    Konto k1;
    Konto k2;
    Konto k3;

    k1.saldo = 1000;
    
    k2.saldo = 200;
    k1 + 500;

    std::cout << k1.saldo << std::endl;
    std::cout << k2.saldo << std::endl;

    k1 += k2;
    k3 = k1; // wenn dies direkt bei de initialisierung gemacht wird, wird nur der copy constructor aufgerufen, in diesem fall aber speziell der überladene zuweisungsoperator

    std::cout << k1.saldo << std::endl;
    std::cout << k2.saldo << std::endl;
    std::cout << k3.saldo << std::endl;

    std::cout << k1;
    std::cin >> k1;
    std::cout << k1;

    std::string str = "Hallo";

    str >> 5;
    std::cout << str << std::endl;


    return 0;
}
