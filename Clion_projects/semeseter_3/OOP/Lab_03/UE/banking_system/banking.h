#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <utility>

class Konto {
    private:
        std::string name;
        int betrag{};
    public:
    explicit Konto(std::string name){this->name=std::move(name);}
    explicit Konto(std::string name,int betrag){this->name=std::move(name);this->betrag=betrag;}

    int get_betrag()const{return this->betrag;}
    std::string get_name()const{return this->name;}

    int addMoney(int);
    int withdrawMoney(int);
    int saveInFile() const;
};


#endif