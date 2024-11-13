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



/*int Konto::saveInFile() const{

    std::ofstream file("/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_03/UE/banking_system_v2/savedAccounts.txt", std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei" << std::endl;
        return -1; // Fehlercode zurückgeben
    }
    // Schreiben der Kontoinformationen in die Datei
   /* file << "Kontoinhaber: " << name << std::endl;
    file << "Betrag: " << betrag << std::endl;
    */
    /*file << name << "," << betrag << std::endl;
    file << "\n";
    // Überprüfen, ob das Schreiben erfolgreich war
    if (file.fail()) {
        std::cerr << "Fehler beim Schreiben in die Datei" << std::endl;
        return -1; // Fehlercode zurückgeben
    }

    file.close();

    std::cout << "saved in file" << std::endl;

    return 0;
}*/

/*std::vector<std::shared_ptr<Konto>>  readFromFile(const std::string& fileName){
    std::vector<std::shared_ptr<Konto>> kontos;
    std::ifstream file(fileName);

    if(!file.is_open())
    {
        std::cerr << "Fehler beim öffnen der Datei" << std::endl;
        return kontos;
    }

    std::string line;

    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name;
        double betrag;

        std::getline(ss, name, ',');
        ss >> betrag;

        if(ss.fail())
        {
           std::cerr << "Fehler beim lesen der Datei" << std::endl;
            return kontos;
        }

        auto newKonto =  std::make_shared<Konto>(name, betrag);
        kontos.push_back(newKonto);
    }

    file.close();
    std::cout << "read from file" << std::endl;
    return kontos;

}
*/

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

