//
// Created by nico on 03.11.24.
//
//
// Created by nico on 18.10.24.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include "banking.h"

#include <vector>

double Konto::deposMoney(const double addMny)
{
    betrag += addMny;
    logTransaction("Einzahlung", addMny);
    return betrag;
}

double Konto::withdrawMoney(const double withdrMny)
{
    if (withdrMny > betrag){
        std::cerr << "Nicht genügend Guthaben für diese Transaktion!" << std::endl;
        return betrag;
    }
    betrag -= withdrMny;
    logTransaction("Auszahlung", withdrMny);
    return betrag;
}


int Konto::logTransaction(const std::string& transactionType, double amount) const {
    std::ofstream file("transactionLog.txt", std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei." << std::endl;
        return -1;
    }
    file << "Konto: " << name << "\n"
         << "Transaktion: " << transactionType << "\n"
         << "Betrag: " << amount << "\n"
         << "Neuer Kontostand: " << betrag << "n\n";
    file.close();
    return 0;
}

