//
// Created by nico on 13.12.24.
//

#pragma once
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
public:
    double a, b;

    Complex()
    {
        this->a = 0; this->b = 0;
        std::cout << "Constructor called" << std::endl;
    };
    Complex(double a, double b){ this->a = a; this->b = b; };
    ~Complex(){};

    void input(std::string&);

    Complex operator+(const Complex& other) const
    {
        std::cout << this->a + other.a << std::endl;
        std::cout << this->b + other.b << std::endl;
        return {a+other.a, b+other.b};
    };

    friend std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        return os << c.a << (c.b >= 0 ? "+" : "-") << "i" << c.b;

    }
};



#endif //COMPLEX_H
