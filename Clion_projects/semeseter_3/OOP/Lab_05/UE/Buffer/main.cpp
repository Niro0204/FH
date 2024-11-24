#include <array>
#include <iostream>
#include <vector>
#include "Buffer.h"

void useBuffer(const Buffer& v) { // die übergabe als Referenz verhindert das redundante Kopieren des Objektes
    constexpr unsigned char pattern[] = {':', ')', ' '};
    v.fillPattern(pattern, sizeof(pattern));  // Buffer mit einem Muster füllen

    std::cout << "Buffer mit Muster: " << std::endl;
    v.print();

    // einzelne Zeichen ersetzen
    v.setData(2, '@');
    v.setData(5, '#');

    std::cout << "Buffer nach Änderungen:" << std::endl;
    v.print();

    // Buffer mit einem neuen Muster füllen
    constexpr unsigned char newPattern[] = {'1', '2', '3'};
    v.fillPattern(newPattern, sizeof(newPattern));  // Neues Muster füllen

    std::cout << "Buffer mit neuem Muster:" << std::endl;
    v.print();
}

Buffer createBuffer() {
    Buffer buff(2,5);
    //Buffer buff (5);

    buff.fill('A');

    return buff; // hier wird der move Konstruktor aufgerufen
}

int main() {
    const Buffer buffer(1, 12);
    useBuffer(buffer); // hier wird kein konstruktor aufgerufen da nur eine Referenz übergeben wird
    Buffer buff = createBuffer();

    //Wie kann bei einer Zuweisung die Anwendung eines Move-Constructors erzwungen werden?
    const Buffer buff2 = std::move(buff); // aufrufen des move Konstruktors, hier wird auch der Zeiger auf allokierte daten übernommen


    std::cout << "Buffer tests: " << std::endl;
    buff.print();
    buff2.print();
    buff2.setData(0,'B'); // ersten buchstaben von A auf B setzen
    buff2.print();

    unsigned char pattern[] = {':', '<', '>', ' '};
    std::vector<Buffer> buffVec;

    /*buffVec.push_back(Buffer(1,pattern, sizeof(pattern)));
    buffVec.push_back(Buffer(2,'C', 5));
    buffVec.push_back(Buffer(3,'D', 5));*/

    buffVec.emplace_back(pattern, sizeof(pattern));
    buffVec.emplace_back('C', 5);
    buffVec.emplace_back('D', 5);

    std::cout << "Ausgabe Vector: " << std::endl;
    for (const auto& e : buffVec) {
        e.print();
    }

    const std::array<Buffer, 3> buffArr = {
        /*Buffer(1, 'A', 3),
        Buffer(2, 'B', 3),
        Buffer(3, 'C', 3)*/
        Buffer('A', 3),
        Buffer('B', 3),
        Buffer('C', 3)
    };

    std::cout << "Ausgabe Array: " << std::endl;
    for (const auto& e : buffArr) {
        e.print();
    }

    /*
     * Werden bei der Iteration auch Move- und Copy-Operatoren aufgerufen?
     *      Ja
     *
     * Was passiert, wenn Sie Move- oder Copy-Konstruktoren ausdrücklich unterbinden oder wechselseitig forcieren?
     *      Wenn mv oder cp Konstruktoren unterbunden werden kann man keine Containerklassen mehr verwenden.
     *
     * Können dann C++ Container verwendet werden?
     *      Nein.
     *
     */

    return 0;
}
