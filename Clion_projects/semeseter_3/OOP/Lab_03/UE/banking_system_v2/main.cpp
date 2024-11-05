#include <iostream>
#include <vector>
#include <memory>
#include <fstream> // Für das Lesen der Transaktionsdatei
#include "banking.h"

// Funktion zum Erstellen eines neuen Kontos
void openAccount(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;
    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);

    if (accountName.empty()) {
        std::cout << "Der Kontoinhabername darf nicht leer sein!" << std::endl;
        return;
    }

    auto newAccount = std::make_shared<Konto>(accountName);
    kontos.push_back(newAccount);
    if(newAccount->saveInFile() != 0) {
        std::cerr << "Error during saveInFile" << std::endl;
    };  // Konto beim Erstellen speichern
    std::cout << "Konto für " << accountName << " erfolgreich erstellt!" << std::endl;
}

// Funktion zum Auflisten aller Konten
void listAccounts(const std::vector<std::shared_ptr<Konto>>& kontos) {
    std::cout << "Verfügbare Konten:" << std::endl;
    for (size_t i = 0; i < kontos.size(); ++i) {
        std::cout << i + 1 << ": " << kontos[i]->get_name() << std::endl;
    }
}

// Funktion zum Suchen eines bestimmten Kontos
std::shared_ptr<Konto> findAccount(const std::vector<std::shared_ptr<Konto>>& kontos, const std::string& accountName) {
    for (const auto& konto : kontos) {
        if (konto->get_name() == accountName) {
            return konto;
        }
    }
    return nullptr; // Konto nicht gefunden
}

// Funktion zum Einzahlen von Geld
double addMoney(std::vector<std::shared_ptr<Konto>>& kontos) {
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
    std::cout << "Betrag erfolgreich eingezahlt! Neuer Kontostand: " << newBetrag << std::endl;

    // Hier Transaktion in die Logdatei schreiben
    std::ofstream logFile("transactionLog.txt", std::ios::app);
    logFile << "Einzahlung: " << amount << " auf Konto von " << currentKonto->get_name() << "\n";
    logFile.close();

    return newBetrag;
}

// Funktion zum Abheben von Geld
double takeMoney(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;
    double amount;

    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);

    auto currentKonto = findAccount(kontos, accountName);
    if (!currentKonto) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return -1;
    }

    std::cout << "Betrag zum Abheben: ";
    std::cin >> amount;
    std::cin.ignore(); // Puffer leeren

    if (amount <= 0) {
        std::cerr << "Der Betrag muss positiv sein!" << std::endl;
        return -1; // oder eine andere Fehlerbehandlung
    }

    double newBetrag = currentKonto->withdrawMoney(amount);
    if (newBetrag != -1) {
        std::cout << "Betrag erfolgreich abgehoben! Neuer Kontostand: " << newBetrag << std::endl;

        // Hier Transaktion in die Logdatei schreiben
        std::ofstream logFile("transactionLog.txt", std::ios::app);
        logFile << "Abhebung: " << amount << " von Konto von " << currentKonto->get_name() << "\n";
        logFile.close();
    }

    return newBetrag;
}

// Funktion zur Anzeige des Transaktionslogs
void showTransactionLog() {
    std::ifstream file("transactionLog.txt");
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Transaktionsdatei." << std::endl;
        return;
    }

    std::string line;
    std::cout << "\n--- Transaktionshistorie ---\n";
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

int main() {
    std::vector<std::shared_ptr<Konto>> kontos;
    int choice;

    do {
        std::cout << "\n--- Menü ---\n";
        std::cout << "1. Konto erstellen\n";
        std::cout << "2. Geld einzahlen\n";
        std::cout << "3. Geld abheben\n";
        std::cout << "4. Konten auflisten\n";
        std::cout << "5. Transaktionshistorie anzeigen\n";
        std::cout << "6. Beenden\n";
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
            takeMoney(kontos);
            break;
        case 4:
            listAccounts(kontos);
            break;
        case 5:
            showTransactionLog();
            break;
        case 6:
            std::cout << "Programm wird beendet." << std::endl;
            break;
        default:
            std::cout << "Ungültige Wahl, bitte versuchen Sie es erneut." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
