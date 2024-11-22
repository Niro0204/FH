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



std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* tm_now = std::localtime(&now);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_now);
    return std::string(buffer);
}

int Konto::nextId = 1;

double Konto::deposMoney(const double addMny)
{
    betrag += addMny;
    //logTransaction("Einzahlung", addMny);
    return betrag;
}

double Konto::withdrawMoney(const double withdrMny)
{
    if (withdrMny > betrag){
        std::cerr << "Nicht genügend Guthaben für diese Transaktion!" << std::endl;
        return betrag;
    }
    betrag -= withdrMny;
    //logTransaction("Auszahlung", withdrMny);
    return betrag;
}

void Konto::addTransaction(double newBetrag, TransactionType type) {
    Transaction newTransaction(newBetrag, type);
    transactions.push_back(newTransaction);
}




