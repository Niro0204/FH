//
// Created by nico on 03.11.24.
//
#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <ctime>
#include <sstream>

/*

enum class TransactionType {
    Deposit,      // Einzahlung
    Withdrawal,   // Auszahlung
    Transfer,     // Überweisung
};

class Transaction{
private:
    //int id{};
    //std::string accountName;
    double amount;
    TransactionType type;
    std::string timestamp;

    std::string getCurrentTime();

    public:
    Transaction(double amount, const TransactionType type){ this->amount = amount, this->type = type, this->timestamp = getCurrentTime(); };

    /*void displayTransaction() const {
        //std::cout << "Transaktion: " <<  type << "\n"
            << "Betrag: " << amount << "\n"
            << "Datum: " << timestamp << "\n";
    }
*/
 /*   void saveToFile() const {
        std::ofstream logFile("transactionLog.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << "Transaktion: " << type << "\n"
                << "Kontoinhaber: " << accountName << "\n"
                << "Betrag: " << amount << "\n"
                << "Datum: " << timestamp << "\n\n";
            logFile.close();
        }
        else {
            std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        }
    }

};

class Konto {
private:
    int id;
    static int nextId;
    std::string name;
    double betrag{};
    std::vector<Transaction> transactions;

public:
    explicit Konto(std::string name) {this->name=std::move(name); this->betrag=0; this->id = nextId++;}
    explicit Konto(std::string name,const double betrag){this->name=std::move(name); this->betrag=betrag; this->id = nextId++;}

    double get_betrag()const{return this->betrag;}
    std::string get_name()const{return this->name;}
    int getID()const{return this->id;}

    double deposMoney(double);
    double withdrawMoney(double);
    //int saveInFile() const;
    //static std::vector<std::shared_ptr<Konto>>  readFromFile(const std::string& fileName);
    int logTransaction(const std::string&, double) const;
   // void addTransaction(double newBetrag, TransactionType type);

    void Konto::addTransaction(double newBetrag, TransactionType type){

        //auto newTransaction = new class Transaction(newBetrag, type);
        //transactions.push_back(newTransaction);
    }
};*/

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
        : amount(amount), type(type), timestamp(getCurrentTime()) {}

    double getAmount() const{return this->amount;}
    TransactionType getType() const{return this->type;}
    std::string getTimestamp() const{return this->timestamp;}


    std::stringstream displayTransaction() const {
        std::stringstream ss;
        ss << ";" <<  static_cast<int>(type) << ";" << amount << ";" << timestamp << ";";
        return ss;
    }


};

class Konto {
private:
    int id;
    static int nextId;
    std::string name;
    double betrag{};


public:
    std::vector<Transaction> transactions;

    explicit Konto(std::string name) : name(std::move(name)), betrag(0), id(nextId++) {}
    explicit Konto(int id,std::string name, double betrag) : id(id),name(std::move(name)), betrag(betrag){addNextId();}

    double get_betrag() const { return this->betrag; }
    std::string get_name() const { return this->name; }
    int getID() const { return this->id; }

    double deposMoney(double);
    double withdrawMoney(double);

    void addTransaction(double newBetrag, TransactionType type);
    static void addNextId() {
        nextId++;
    }

    std::stringstream displayTransactions() const {
        std::stringstream ss;
        for (const auto& transaction : transactions) {
            ss << transaction.displayTransaction().str(); // Anhängen der Transaktion an den Stringstream
        }
        return ss;
    }
};



#endif