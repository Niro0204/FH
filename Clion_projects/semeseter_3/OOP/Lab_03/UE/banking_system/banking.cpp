//
// Created by nico on 18.10.24.
//

#include <iostream>
#include <string>
#include <fstream>
#include "banking.h"

int Konto::saveInFile(){

    std::ofstream file;

    file.open("tasks.txt",std::ios::app);

    if(!file.is_open()){
        std::cerr << "opening file failed" << std::endl;
        return -1;
    }
    else{
        std::cout << "file opened successfully" << std::endl;
    }

    file << "Kontoinhaber: " << name << std::endl;
    file << "Betrag: " << betrag << std::endl;
    file << "\n";

    file.close();

    return 0;
}

