//
// Created by nico on 13.12.24.
//

#include <iostream>
#include "Complex.h"


void Complex::input(std::string& baseStr){

    constexpr char delimiter = 'i';

    if(baseStr.find(delimiter) == -1)
    {
        std::cerr << "Number must be in format a+ib or a-ib" << std::endl;
        return;
    }

    std::string str1 = baseStr.substr(0, baseStr.find(delimiter));
    std::string str2 = baseStr.substr(baseStr.find(delimiter) + 1);

    if(str1.back()== '-')
    {
        str2.insert(str2.begin(),'-');
        str1.pop_back();
    }

    a = std::stod(str1);
    b = std::stod(str2);
}

