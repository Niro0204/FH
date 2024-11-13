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
    //int saveInFile() const;
    //static std::vector<std::shared_ptr<Konto>>  readFromFile(const std::string& fileName);
    int logTransaction(const std::string&, double) const;
};

class Transaction{
private:
    int id;
    std::string accountName;
    double amount;
    std::string type;
    std::string timestamp;

    std::string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        std::tm* tm_now = std::localtime(&now);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_now);
        return std::string(buffer);
    }

    public:
    Transaction(const std::string& accountName, double amount, const std::string& type)
        : accountName(accountName), amount(amount), type(type), timestamp(getCurrentTime()) {}

    void displayTransaction() const {
        std::cout << "Transaktion: " << type << "\n"
            << "Kontoinhaber: " << accountName << "\n"
            << "Betrag: " << amount << "\n"
            << "Datum: " << timestamp << "\n";
    }

    void saveToFile() const {
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


#endif