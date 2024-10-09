#include <array>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

int main() {

    std::vector<std::string> zeilen;

    std::ifstream datei("/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_02/Lab_files/text.txt");
    if (!datei.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }

    std::string zeile;

    while(std::getline(datei, zeile)) {
        zeilen.push_back(zeile);
    }

    // c style
    std::cout << "c style: " << std::endl;
    for(int i = 0; i < zeilen.size(); i++) {
        std::cout << zeilen[i] << std::endl;
    }

    std::cout << std::endl;

    // c++ style
    std::cout << "c++ style: " << std::endl;
    for(auto iter = zeilen.begin(); iter != zeilen.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    // for each
    std::cout << "for each: " << std::endl;
    for(auto& elem : zeilen) {
        std::cout << elem << std::endl;
    }

    std::cout << std::endl;

    int i = 5;
    // c style "raw" pointer
    int* ptr = &i;
    //c++ reference
    int& ref = i;  // referenz muss immer direkt initialisiert werden
    ref = 15;      // referenz kann nicht im nachhinein auf eine ander variable zeigen
                   // referenz ist also nur ein alias für eine variable

    std::cout << i << std::endl;

    const int& constRef = i; // kann nur mehr gelesen und nicht verändert werden

    std::shared_ptr<std::array<int,10>>sptr = std::make_shared<std::array<int,10>>();

    std::cout << sptr.use_count() << std::endl;

    auto sptrCpy = sptr;

    std::cout << sptrCpy.use_count() << std::endl;


    //std::weak_ptr<int> wptr = sptr;
    //std::cout << sptr.use_count() << std::endl;

    std::unique_ptr<int> uptr;

    datei.close();

    return 0;
}
