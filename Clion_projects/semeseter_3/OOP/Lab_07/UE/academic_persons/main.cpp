#include <iostream>
#include <vector>
#include <memory>

#include "people.h"

int main() {

    std::vector<std::shared_ptr<Person>> vPeople;
    // Erstelle eine Person ohne Sozialversicherungsnummer
    vPeople.push_back(std::make_shared<Person>("John","Doe",'M',"1990-01-01"));
    // Erstelle eine Person mit Sozialversicherungsnummer
    vPeople.push_back(std::make_shared<Person>("Jane", "Smith", 'F', "2005-05-05", 1234566845));
    // Erstelle einen Studenten ohne Sozialversicherungsnummer
    vPeople.push_back(std::make_shared<Student>("Alice", "Johnson", 'F', "2000-09-09", 1001, "2020-09-01", "FH-Salzburg"));
    // Erstelle einen Studenten mit Sozialversicherungsnummer
    vPeople.push_back(std::make_shared<Student>("Bob", "Brown", 'M', "1903-03-03", 9876546581, 1002, "2019-03-15", "Technical Institute"));

    // jede Person im Vektor stellt sich vor
    for (const auto& person : vPeople)
    {
        person->whoAmI();
    }

    if (auto lastStudent = std::dynamic_pointer_cast<Student>(vPeople.back())) // checkt, ob die letzte Person im Vektor ein Student ist
    {
        auto newAlumnus = Student::promoteToAlumnus(*lastStudent,"2024-11-30");
        vPeople.push_back(std::make_shared<Alumnus>(newAlumnus)); // Bob ist jetzt mit seinem Studium fertig
    }
    else
    {
        std::cout<<"last element in Vector is not a Student"<< std::endl;
    }

    // ausgabe nach änderung von Bob
    for (const auto& person : vPeople)
    {
        person->whoAmI();

    }





    return 0;
}

