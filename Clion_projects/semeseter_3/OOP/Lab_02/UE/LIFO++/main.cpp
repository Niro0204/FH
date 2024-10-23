
#include <iostream>
#include <vector>
#include <stack>
#include <memory>

// Struktur eines Artikels
struct article {
    int article_num;      // Artikelnummer
    std::string article_name; // Artikelname
    double article_weight; // Artikelgewicht
};

/*
    benutzung von shared in diesem programm speziell unnötig,
    sinnvoll aber falls das programm erweitert wird. So besteht
    die Möglichkeit in mehreren Fächern das gleiche Produkt zu lagern.
    unique_ptr für das Lager selber, da, auch wenn mehrere Regale gleiche Artikellagern können,
    ist trotzdem jedes Regal eindeutig zu unterscheiden.
*/

// alias für die Verwendung von Smart Pointern
using article_ptr = std::shared_ptr<article>;
using shelf = std::stack<article_ptr>;
using warehouse = std::vector<std::unique_ptr<shelf>>;

// Funktion zum Hinzufügen eines neuen Regals
void addShelf(warehouse& wh) {
    wh.push_back(std::make_unique<shelf>());
    std::cout << "Number of shelves: " << wh.size() << std::endl;
}

// Funktion zum Hinzufügen eines Artikels zu einem Regal
void addArticle(warehouse& wh, int shelfNum) {
    shelfNum -= 1; // Regalnummer anpassen (0-basierter Index)

    // Zugriff auf das Regal
    auto& shelf = wh[shelfNum];
    int art_num;
    std::string art_name;
    double art_weight;

    // Benutzereingabe für Artikelinformationen
    std::cout << "Article number: ";
    std::cin >> art_num;
    std::cout << "Article name: ";
    std::cin >> art_name;
    std::cout << "Article weight (kg): "; // Einheit hinzufügen
    std::cin >> art_weight;

    // Neuen Artikel erstellen und zum Regal hinzufügen
    article_ptr new_article = std::make_shared<article>(article{art_num, art_name, art_weight});
    shelf->push(new_article);
}

// Funktion zum Entnehmen eines Artikels aus einem Regal
std::shared_ptr<article> takeArticle(warehouse& wh, int shelfNum) {
    shelfNum -= 1; // Regalnummer anpassen
    auto& shelf = wh[shelfNum];

    // Überprüfen, ob das Regal leer ist
    if (shelf->empty()) {
        std::cerr << "Shelf " << (shelfNum + 1) << " is empty." << std::endl;
        return nullptr; // Rückgabe eines Nullzeigers, wenn das Regal leer ist
    }

    std::shared_ptr<article> ret_article = shelf->top(); // Obersten Artikel entnehmen
    shelf->pop(); // Artikel aus dem Regal entfernen
    return ret_article; // Rückgabe des entnommenen Artikels
}

// Funktion zum Anzeigen der Artikel in einem Regal
void showShelf(warehouse& wh, int shelfNum) {
    shelfNum -= 1; // Regalnummer anpassen
    auto& shelf = wh[shelfNum];

    // Überprüfen, ob das Regal gültig ist
    if (shelfNum < 0 || shelfNum >= wh.size()) {
        std::cerr << "Invalid shelf number." << std::endl;
        return;
    }

    // Überprüfen, ob das Regal leer ist
    if (shelf->empty()) {
        std::cerr << "Shelf " << (shelfNum + 1) << " is empty." << std::endl;
        return;
    }

    std::cout << "Shelf " << shelfNum + 1 << " contents:" << std::endl;

    // Kopie des Stacks für die Iteration
    auto tempStack = *shelf;
    while (!tempStack.empty()) {
        std::shared_ptr<article> article = tempStack.top(); // Zugriff auf den Artikel
        // Ausgabe der Artikelinformationen
        std::cout << "Article Nr: " << article->article_num
                  << ", Name: " << article->article_name
                  << ", Weight: " << article->article_weight << " kg" << std::endl;
        tempStack.pop(); // Nächstes Element im Stack
    }
}

// Funktion zum Anzeigen des gesamten Lagers -- tipp von stack overflow
void showWarehouse(warehouse& wh) {
    std::cout << "Warehouse contents:" << std::endl;
    for (size_t i = 0; i < wh.size(); ++i) {
        showShelf(wh, i + 1); // Zeige die Inhalte jedes Regals an
    }
}

// Hauptfunktion zur Steuerung des Programms
int main() {
    warehouse wh; // Lager initialisieren

    while (true) {
        int choice = 0; // Benutzerwahl
        int shelfNum = 0; // Regalnummer für Benutzeraktionen
        std::shared_ptr<article> takenArticle;

        // Menüausgabe
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add shelf" << std::endl;
        std::cout << "2. Add article" << std::endl;
        std::cout << "3. Take article" << std::endl;
        std::cout << "4. Show shelf" << std::endl;
        std::cout << "5. Show warehouse" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cin >> choice; // Benutzereingabe

        // Überprüfen auf Eingabefehler
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50, '\n');
            continue; // Fortfahren bei Fehler
        }

        // Auswahl des Benutzerkommandos
        switch (choice) {
            case 1:
                addShelf(wh);
                break;
            case 2:
                std::cout << "Enter shelf number: ";
                std::cin >> shelfNum;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                    std::cerr << "Invalid input" << std::endl;
                    continue;
                }
                addArticle(wh, shelfNum);
                break;
            case 3:
                std::cout << "Enter shelf number: ";
                std::cin >> shelfNum;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                    std::cerr << "Invalid input" << std::endl;
                    continue;
                }
                takenArticle = takeArticle(wh, shelfNum); // Artikel entnehmen
                if (takenArticle) {
                    // Ausgabe der entnommenen Artikelinformationen
                    std::cout << "Taken article: " << takenArticle->article_num
                              << ", Name: " << takenArticle->article_name
                              << ", Weight: " << takenArticle->article_weight << " kg" << std::endl;
                }
                break;
            case 4:
                std::cout << "Enter shelf number: ";
                std::cin >> shelfNum;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(50, '\n');
                    std::cerr << "Invalid input" << std::endl;
                    continue;
                }
                showShelf(wh, shelfNum); // Regalinhalt anzeigen
                break;
            case 5:
                showWarehouse(wh); // Lagerinhalt anzeigen
                break;
            case 6:
                std::cout << "Exiting..." << std::endl; // Beenden des Programms
                return 0;
            default:
                std::cerr << "Invalid choice." << std::endl; // Ungültige Auswahl
        }
    }
    return 0; // Beenden des Programms
}

