#include <iostream>
#include <vector>
#include <memory>
#include <fstream> // Für das Lesen der Transaktionsdatei
#include <limits>
#include <sstream>
#include "banking.h"

// Funktion zum Erstellen eines neuen Kontos
void openAccount(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::getline(std::cin, accountName);

    if (accountName.empty()) {
        std::cout << "Der Kontoinhabername darf nicht leer sein!" << std::endl;
        return;
    }

    auto newAccount = std::make_shared<Konto>(accountName);
    kontos.push_back(newAccount);
    /*if(newAccount->saveInFile() != 0) {
        std::cerr << "Error during saveInFile" << std::endl;
    };  // Konto beim Erstellen speichern*/
    std::cout << "Konto für " << accountName << " erfolgreich erstellt!" << std::endl;
}


int saveInFile(const std::vector<std::shared_ptr<Konto>>& kontos,const std::string& fileName){

    std::ofstream file("/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab04/bankingSystem_v3/savedAccounts.txt", std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei" << std::endl;
        return -1; // Fehlercode zurückgeben
    }

    for(auto& konto : kontos)
    {

        std::cout << konto->get_name();
        double dbetrag = konto->get_betrag();

        file << konto->getID() << "," << konto->get_name() << "," << std::to_string(dbetrag) << "," << konto->displayTransactions().str() << "\n";

        if (file.fail()) {
            throw std::runtime_error("Fehler beim schreiben in die Datei");
        }
    }

    file.close();

    std::cout << "saved in file" << std::endl;

    return 0;
}



std::vector<std::shared_ptr<Konto>>&  readFromFile(std::vector<std::shared_ptr<Konto>>& newkontos,const std::string& fileName){


    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Fehler beim Öffnen der Datei");
    }

    std::string line;
    while (std::getline(file, line)) {
        // Leere Zeilen überspringen
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string idstr, name, betragStr;
        int id = 0;
        double betrag = 0.0;

        // ID einlesen und konvertieren
        if (std::getline(ss, idstr, ',')) {
            try {
                id = std::stoi(idstr);
            } catch (const std::invalid_argument&) {
                std::cerr << "Ungültiges Format für ID: '" << idstr << "'\n";
                continue;
            } catch (const std::out_of_range&) {
                std::cerr << "ID außer Reichweite: '" << idstr << "'\n";
                continue;
            }
        }

        // Name einlesen
        if (!std::getline(ss, name, ',')) {
            std::cerr << "Fehler beim Einlesen des Namens\n";
            continue;
        }

        // Betrag einlesen und konvertieren
        if (std::getline(ss, betragStr, ',')) {
            try {
                betrag = std::stod(betragStr);
            } catch (const std::invalid_argument&) {
                std::cerr << "Ungültiges Format für Betrag: '" << betragStr << "'\n";
                continue;
            } catch (const std::out_of_range&) {
                std::cerr << "Betrag außer Reichweite: '" << betragStr << "'\n";
                continue;
            }
        } else {
            std::cerr << "Fehler beim Einlesen des Betrags\n";
            continue;
        }

        // Neues Konto-Objekt erstellen und in den Vektor einfügen
        auto newKonto = std::make_shared<Konto>(id, name, betrag);
        newkontos.push_back(newKonto);
    }

    file.close();
    std::cout << "read from file" << std::endl;
    return newkontos;
}



// Funktion zum Auflisten aller Konten
void listAccounts(const std::vector<std::shared_ptr<Konto>>& kontos) {
    std::cout << "Verfügbare Konten:" << std::endl;
    for (size_t i = 0; i < kontos.size(); ++i) {
        std::cout << kontos[i]->getID() << ": " << kontos[i]->get_name() << "Guthaben: "<< kontos[i]->get_betrag()<< std::endl;
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, accountName);

    auto currentKonto = findAccount(kontos, accountName);
    if (!currentKonto) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return -1;
    }

    std::cout << "Betrag zum Einzahlen: ";
    std::cin >> amount;
    //std::cin.ignore(); // Puffer leeren

    if (amount <= 0) {
        std::cerr << "Der Betrag muss positiv sein!" << std::endl;
        return -1; // oder eine andere Fehlerbehandlung
    }

    double newBetrag = currentKonto->deposMoney(amount);
    std::cout << "Betrag erfolgreich eingezahlt! Neuer Kontostand: " << newBetrag << std::endl;

    // Hier Transaktion in die Logdatei schreiben
  /*  std::ofstream logFile("transactionLog.txt", std::ios::app);
    logFile << "Einzahlung: " << amount << " auf Konto von " << currentKonto->get_name() << "\n";
    logFile.close();
    */
    currentKonto->addTransaction(newBetrag,TransactionType::Deposit);

    return newBetrag;
}


// Funktion zum Abheben von Geld
double takeMoney(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;
    double amount;

    std::cout << "Geben Sie den Namen des Kontoinhabers ein: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, accountName);

    auto currentKonto = findAccount(kontos, accountName);
    if (!currentKonto) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return -1;
    }

    while (true) {
        std::cout << "Betrag zum Abheben: ";
        std::cin >> amount;

        if (std::cin.fail()) {
            // Eingabefehler (z. B. Text statt Zahl)
            std::cin.clear(); // Fehlerstatus zurücksetzen
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
            std::cerr << "Ungültige Eingabe! Bitte eine Zahl eingeben." << std::endl;
        } else if (amount <= 0) {
            // Geschäftliche Regel: Betrag muss positiv sein
            std::cerr << "Der Betrag muss positiv sein!" << std::endl;
        } else {
            // Gültiger, positiver Betrag
            break;
        }
    }

    double newBetrag = currentKonto->withdrawMoney(amount);

    /*if (newBetrag != -1) {
        std::cout << "Betrag erfolgreich abgehoben! Neuer Kontostand: " << newBetrag << std::endl;

        // Hier Transaktion in die Logdatei schreiben
        std::ofstream logFile("transactionLog.txt", std::ios::app);
        logFile << "Abhebung: " << amount << " von Konto von " << currentKonto->get_name() << "\n";
        logFile.close();
    }*/

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
    try
    {
        std::vector<std::shared_ptr<Konto>> kontos;
        kontos = readFromFile(kontos,"/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab04/bankingSystem_v3/savedAccounts.txt");
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

            /*if (std::cin.fail()) {
                std::cin.clear(); // Fehlerstatus zurücksetzen
                std::cin.ignore(100, '\n'); // Gesamten Puffer leeren
                std::cerr << "Ungültige Eingabe!" << std::endl;
            }*/

            if (std::cin.fail())  {
                std::cin.clear();             // Setzt den Fehlerzustand von std::cin zurück
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl zwischen 1 und 6 ein." << std::endl;
                continue;// Leert den Eingabepuffer// Schleifenanfang neu beginnen
            }

            // Puffer leeren

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
            //std::cout << std::endl;
        } while (choice != 6);

        saveInFile(kontos,"/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab04/bankingSystem_v3/savedAccounts.txt");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
