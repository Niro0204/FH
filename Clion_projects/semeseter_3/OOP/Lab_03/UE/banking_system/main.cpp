//
// Created by nico on 23.10.24.
//
#include <iostream>
#include <vector>
#include <memory>
#include "banking.h"


void openAccount(std::vector<std::shared_ptr<Konto>>& kontos) {

    std::string accountName;
    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);


    if (accountName.empty()) {
        std::cout << "Der Kontoinhabername darf nicht leer sein!" << std::endl;
        return;
    }

    std::shared_ptr<Konto> newAccount = std::make_unique<Konto>(accountName);

    kontos.push_back(std::move(newAccount));

    std::cout << "Konto für " << accountName << " erfolgreich erstellt!" << std::endl;

}

void listAccounts(const std::vector<std::shared_ptr<Konto>>& kontos) {
    std::cout << "Verfügbare Konten:" << std::endl;
    for (size_t i = 0; i < kontos.size(); ++i) {
        std::cout << i + 1 << ": " << kontos[i]->get_name() << std::endl;
    }
}


std::shared_ptr<Konto> findAccount(const std::vector<std::shared_ptr<Konto>>& kontos, const std::string& accountName)
{
    for (const auto& konto : kontos) {
        if (konto->get_name() == accountName) {
            return konto;
        }
    }
    return nullptr; // Konto nicht gefunden
}


double addMoney(std::vector<std::shared_ptr<Konto>>& kontos){

    std::string accountName;
    double amount;

    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);

    auto currentKonto = findAccount(kontos, accountName);
    if (!currentKonto) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return -1;
    }

    std::cout << "Betrag zum Einzahlen: ";
    std::cin >> amount;
    std::cin.ignore(); // Puffer leeren

    if (amount <= 0) {
        std::cerr << "Der Betrag muss positiv sein!" << std::endl;
        return -1; // oder eine andere Fehlerbehandlung
    }

    double newBetrag = currentKonto->deposMoney(amount);
    std::cout << "Betrag erfolgreich eingezahlt!" << std::endl;

    return newBetrag;//currentKonto->get_betrag();
}

double takeMoney(std::vector<std::shared_ptr<Konto>>& kontos)
{
    std::string accountName;
    double amount;

    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);

    auto currentKonto = findAccount(kontos, accountName);
    if (!currentKonto) {
        std::cout << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return -1;
    }

    std::cout << "Betrag zum Abheben: ";
    std::cin >> amount;
    std::cin.ignore(); // Puffer leeren

    if (amount <= 0) {
        std::cout << "Der Betrag muss positiv sein!" << std::endl;
        return -1; // oder eine andere Fehlerbehandlung
    }

    double newBetrag = currentKonto->withdrawMoney(amount);
    if (newBetrag != -1) {
        std::cout << "Betrag erfolgreich abgehoben! Neuer Betrag: " << newBetrag << std::endl;
    }

    return newBetrag;

}

//void save(std::vector<std::shared_ptr<Konto>>& kontos)

int main(){

    std::vector<std::shared_ptr<Konto>> kontos;
    int choice;

    do {
        std::cout << "\n--- Menü ---\n";
        std::cout << "1. Konto erstellen\n";
        std::cout << "2. Geld einzahlen\n";
        std::cout << "3. Geld abheben\n"; // Neue Option hinzufügen
        std::cout << "4. Konten auflisten\n";
        std::cout << "5. Beenden\n";
        std::cout << "Wählen Sie eine Option: ";
        std::cin >> choice;
        std::cin.ignore(); // Puffer leeren

        switch (choice) {
        case 1:
            openAccount(kontos);
            break;
        case 2:
            addMoney(kontos);
            break;
        case 3:
            takeMoney(kontos); // Funktion zum Geld abheben aufrufen
            break;
        case 4:
            listAccounts(kontos);
            break;
        case 5:
            std::cout << "Programm wird beendet." << std::endl;
            break;
        default:
            std::cout << "Ungültige Wahl, bitte versuchen Sie es erneut." << std::endl;
        }
    } while (choice != 5);

    return 0;
}