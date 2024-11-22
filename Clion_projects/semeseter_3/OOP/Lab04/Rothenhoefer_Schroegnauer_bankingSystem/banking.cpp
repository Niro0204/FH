#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include "banking.h"

#include <vector>



double Konto::deposMoney(const double addMny) {
    if (isClosed) {
        std::cerr << "Konto ist geschlossen. Einzahlung nicht möglich!" << std::endl;
        return betrag;
    }

    betrag += addMny;
    addTransaction(betrag, TransactionType::Deposit);
    return betrag;
}

double Konto::withdrawMoney(const double withdrMny) {
    if (isClosed) {
        std::cerr << "Konto ist geschlossen. Abhebung nicht möglich!" << std::endl;
        return betrag;
    }

    if (betrag < withdrMny) {
        std::cerr << "Nicht genügend Guthaben!" << std::endl;
        return betrag;
    }

    betrag -= withdrMny;
    addTransaction(betrag, TransactionType::Withdrawal);
    return betrag;
}

void Konto::addTransaction(double newBetrag, TransactionType type) {
    transactions.push_back({ newBetrag, type });
}

bool Konto::closeAccount() {
    if (betrag == 0.0) {
        isClosed = true; // Konto als geschlossen markieren
        std::cout << "Konto '" << name << "' wurde erfolgreich geschlossen." << std::endl;
        return true;
    }
    else {
        std::cerr << "Konto '" << name << "' kann nicht geschlossen werden, da der Kontostand nicht 0.00 ist." << std::endl;
        return false; // Konto kann nicht geschlossen werden, wenn der Kontostand nicht 0.00 ist
    }
}

std::stringstream Konto::displayTransactions() const {
    std::stringstream ss;
    for (const auto& transaction : transactions) {
        std::string type = transaction.second == TransactionType::Deposit ? "Einzahlung" : "Abhebung";
        ss << type << ": " << transaction.first << ":";
    }

    ss << std::endl;
    return ss;
}