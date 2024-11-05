//
// Created by nico on 03.11.24.
//
#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <fstream>
#include <utility>

class Konto {
private:
    std::string name;
    double betrag{};
public:
    explicit Konto(std::string name){this->name=std::move(name); this->betrag=0;}
    explicit Konto(std::string name,double betrag){this->name=std::move(name);this->betrag=betrag;}

    double get_betrag()const{return this->betrag;}
    std::string get_name()const{return this->name;}

    double deposMoney(double);
    double withdrawMoney(double);
    int saveInFile() const;
    int logTransaction(const std::string&, double) const;
};


#endif