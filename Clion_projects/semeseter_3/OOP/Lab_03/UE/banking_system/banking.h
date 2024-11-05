/*

#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <utility>

class Konto {
    private:
        std::string name;
        double betrag{};
    public:
    explicit Konto(std::string name){this->name=std::move(name);}
    explicit Konto(std::string name,double betrag){this->name=std::move(name);this->betrag=betrag;}

    int get_betrag()const{return this->betrag;}
    std::string get_name()const{return this->name;}

    double deposMoney(double);
    double withdrawMoney(double);
    int saveInFile(std::string&) const;
};


#endif

*/

#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <utility>

class Konto {
private:
    std::string name;
    double betrag{};
public:
    explicit Konto(std::string name){this->name=std::move(name);}
    explicit Konto(std::string name,double betrag){this->name=std::move(name);this->betrag=betrag;}

    int get_betrag()const{return this->betrag;}
    std::string get_name()const{return this->name;}

    double deposMoney(double);
    double withdrawMoney(double);
    int saveInFile() const;
};


#endif