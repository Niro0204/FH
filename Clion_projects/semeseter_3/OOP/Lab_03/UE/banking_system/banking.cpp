//
// Created by nico on 18.10.24.
//

#include <iostream>
#include <string>
#include <fstream>
#include "banking.h"

int Konto::addMoney(const int addMny)
{
    betrag += addMny;
    return betrag;
}

int Konto::withdrawMoney(const int withdrMny)
{
    if (withdrMny > betrag)
    {
        std::cerr << "Nicht genügend Guthaben für diese Transaktion!" << std::endl;
    }
    else
    {
        betrag -= withdrMny;
    }
    return betrag;
}



int Konto::saveInFile() const{

    std::ofstream file;

    file.open("savedAccounts.txt",std::ios::app);

    if(!file.is_open()){
        std::cerr << "opening file failed" << std::endl;
        return -1;
    }
    else{
        std::cout << "file opened successfully" << std::endl;
    }

    file << "Kontoinhaber: " << name << std::endl;
    file << "Betrag: " << betrag << std::endl;
    file << "\n";

    file.close();

    return 0;
}

