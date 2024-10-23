//
// Created by nico on 23.10.24.
//
#include <iostream>
#include <vector>
#include <memory>
#include "banking.h"


void openAccount(std::vector<std::unique_ptr<Konto>>& kontos) {

    std::string accountName;
    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);


    if (accountName.empty()) {
        std::cout << "Der Kontoinhabername darf nicht leer sein!" << std::endl;
        return;
    }

    std::unique_ptr<Konto> newAccount = std::make_unique<Konto>(accountName);

    kontos.push_back(std::move(newAccount));

    std::cout << "Konto für " << accountName << " erfolgreich erstellt!" << std::endl;

}

int main(){

    std::vector<std::unique_ptr<Konto>> kontos;

    char choice;
    do {
        openAccount(kontos);

        std::cout << "Möchten Sie ein weiteres Konto erstellen? (j/n): ";
        std::cin >> choice;
        std::cin.ignore();
    } while (choice == 'j' || choice == 'J');


    std::cout << "Erstellte Konten:" << std::endl;
    for (const auto& konto : kontos) {
        std::cout << "Kontoinhaber: " << konto->get_name() << ", Betrag: " << konto->get_betrag() << std::endl;
    }

    return 0;
}