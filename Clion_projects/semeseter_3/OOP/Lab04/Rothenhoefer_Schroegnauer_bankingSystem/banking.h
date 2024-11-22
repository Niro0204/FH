#ifndef BANKING_H
#define BANKING_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

enum class TransactionType {
    Deposit,      // Einzahlung
    Withdrawal,   // Auszahlung
    Transfer      // Überweisung
};

class Transaction {
private:
    double amount;
    TransactionType type;
    std::string timestamp;

    std::string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

public:
    Transaction(double amount, TransactionType type)
        : amount(amount), type(type), timestamp(getCurrentTime()) {
    }

    double getAmount() const { return this->amount; }
    TransactionType getType() const { return this->type; }
    std::string getTimestamp() const { return this->timestamp; }


    std::stringstream displayTransaction() const {
        std::stringstream ss;
        ss << ";" << static_cast<int>(type) << ";" << amount << ";" << timestamp << ";";
        return ss;
    }


};

class Konto {
private:
    int id;
    std::string name;
    double betrag;
    bool isClosed; // Neuer Status: Ob das Konto geschlossen ist
    std::vector<std::pair<double, TransactionType>> transactions;

public:
    // Konstruktoren
    Konto(const std::string& name) : id(nextID()), name(name), betrag(0.0), isClosed(false) {}
    Konto(int id, const std::string& name, double betrag)
        : id(id), name(name), betrag(betrag), isClosed(false), transactions() {
    }

    //copy constructor
    Konto(const Konto& other) : id(nextID()),name(other.name),betrag(0.0),isClosed(false),transactions() {}

    // Methoden
    int getID() const { return id; }
    std::string get_name() const { return name; }
    double get_betrag() const { return betrag; }
    bool getIsClosed() const { return isClosed; }

    double deposMoney(const double addMny);
    double withdrawMoney(const double withdrMny);
    void addTransaction(double newBetrag, TransactionType type);
    bool closeAccount();

    std::stringstream displayTransactions() const;

    // Statische Methode zur ID-Generierung
    static int nextID() {
        static int currentID = 0;
        return ++currentID;
    }
};

#endif