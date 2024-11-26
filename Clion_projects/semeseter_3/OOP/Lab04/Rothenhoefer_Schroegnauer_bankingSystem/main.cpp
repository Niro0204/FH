#include <iostream>
#include <vector>
#include <memory>
#include <fstream> // Für das Lesen der Transaktionsdatei
#include <limits>
#include <sstream>
#include <algorithm>>
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


int saveInFile(const std::vector<std::shared_ptr<Konto>>& kontos, const std::string& fileName) {

    std::ofstream file(fileName, std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei" << std::endl;
        return -1; // Fehlercode zurückgeben
    }

    for (auto& konto : kontos)
    {

        //std::cout << konto->get_name();
        double dbetrag = konto->get_betrag();

        file << konto->getID() << "," << konto->get_name() << "," << std::to_string(dbetrag) << "\n";

        if (file.fail()) {
            throw std::runtime_error("Fehler beim schreiben in die Datei");
        }
    }

    file.close();

    std::cout << "saved in file" << std::endl;

    return 0;
}



std::vector<std::shared_ptr<Konto>>& readFromFile(std::vector<std::shared_ptr<Konto>>& newkontos, const std::string& fileName) {


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
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Ungültiges Format für ID: '" << idstr << "'\n";
                continue;
            }
            catch (const std::out_of_range&) {
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
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Ungültiges Format für Betrag: '" << betragStr << "'\n";
                continue;
            }
            catch (const std::out_of_range&) {
                std::cerr << "Betrag außer Reichweite: '" << betragStr << "'\n";
                continue;
            }
        }
        else {
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
    for (const auto& konto : kontos) {
        if (!konto->getIsClosed()) { // Nur offene Konten anzeigen
            std::cout << konto->getID() << ": " << konto->get_name()
                << " Guthaben: " << konto->get_betrag() << std::endl;
        }
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
    std::ofstream logFile("transactionLog.txt", std::ios::app);
    logFile << "Einzahlung: " << amount << " auf Konto von " << currentKonto->get_name() << "\n";
    logFile.close();

    currentKonto->addTransaction(newBetrag, TransactionType::Deposit);

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
        }
        else if (amount <= 0) {
            // Geschäftliche Regel: Betrag muss positiv sein
            std::cerr << "Der Betrag muss positiv sein!" << std::endl;
        }
        else {
            // Gültiger, positiver Betrag
            break;
        }
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

void copyAccount(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;

    std::cout << "Geben Sie den Namen des Kontoinhabers des Kontos ein, das Sie kopieren möchten: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, accountName);

    auto accountToCopy = findAccount(kontos, accountName);
    if (!accountToCopy) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return;
    }

    // Neues Konto erstellen, indem das alte Konto kopiert wird
    std::shared_ptr<Konto> copiedAccount = std::make_shared<Konto>(*accountToCopy); // Der Kopierkonstruktor wird hier verwendet
    kontos.push_back(copiedAccount);

    std::cout << "Konto für " << accountName << " erfolgreich kopiert!" << std::endl;
}

void closeAccount(std::vector<std::shared_ptr<Konto>>& kontos) {
    std::string accountName;

    std::cout << "Geben Sie den Namen des Kontoinhabers ein, dessen Konto geschlossen werden soll: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, accountName);

    auto it = std::find_if(kontos.begin(), kontos.end(),
        [&accountName](const std::shared_ptr<Konto>& konto) {
            return konto->get_name() == accountName;
        });

    if (it == kontos.end()) {
        std::cerr << "Konto mit dem Namen \"" << accountName << "\" nicht gefunden." << std::endl;
        return;
    }

    if ((*it)->getIsClosed()) {
        std::cerr << "Dieses Konto ist bereits geschlossen." << std::endl;
        return;
    }

    if ((*it)->closeAccount()) {
        kontos.erase(it); // Entferne das Konto aus der Liste, wenn es erfolgreich geschlossen wurde.
        std::cout << "Das Konto wurde erfolgreich geschlossen." << std::endl;
    }
}



int main() {
    try {

        // Laden der Konten aus der Datei
        std::vector<std::shared_ptr<Konto>> kontos;
        kontos = readFromFile(kontos, "savedAccounts.txt");

        int choice;

        while (true) {
            std::cout << "\n--- Banking System ---\n";
            std::cout << "1. Konto erstellen\n";
            std::cout << "2. Konten anzeigen\n";
            std::cout << "3. Geld einzahlen\n";
            std::cout << "4. Geld abheben\n";
            std::cout << "5. Transaktionshistorie anzeigen\n";
            std::cout << "6. Konto kopieren\n";
            std::cout << "7. Konto schließen\n";
            std::cout << "8. Speichern und Beenden\n";
            std::cout << "Bitte wählen Sie eine Option: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                openAccount(kontos);
                break;
            case 2:
                listAccounts(kontos);
                break;
            case 3:
                addMoney(kontos);
                break;
            case 4:
                takeMoney(kontos);
                break;
            case 5:
                showTransactionLog();
                break;
            case 6:
                copyAccount(kontos);  // Neue Funktion zum Kopieren eines Kontos aufrufen
                break;
            case 7:
                closeAccount(kontos);
                break;
            case 8:
                saveInFile(kontos, "savedAccounts.txt");
                std::cout << "Das Programm wird beendet." << std::endl;
                return 0;
            default:
                std::cerr << "Ungültige Auswahl, bitte erneut versuchen." << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }
}

