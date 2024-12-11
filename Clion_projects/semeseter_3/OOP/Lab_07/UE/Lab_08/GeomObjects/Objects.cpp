//
// Created by nico on 06.12.24.
//
#include <iostream>
#include <cmath>
#include "Objects.h"

unsigned int UniqueID::id = 1;

double GeoRect::area() const  {

    return a * b;
}

double GeoRect::circumference() const {
    return 2*a + 2*b;
}

void GeoRect::output() const{
    std::cout << "Rechteck, ID: " << getID() << std::endl;
    std::cout << "Seite a: " << getA() << ", Seite b: " << getB() << std::endl;
    std::cout << "Umfang: " << circumference() << std::endl;
    std::cout << "Fläche: " << area() << std::endl;
    std::cout << std::endl;
}

double GeoSquare::area() const {
    return a * a;
}

double GeoSquare::circumference() const {
    return a * 4;
}

void GeoSquare::output() const{
    std::cout << "Quadrat, ID: " << getID() << std::endl;
    std::cout << "Seite a: " << getA() << std::endl;
    std::cout << "Umfang: " << circumference() << std::endl;
    std::cout << "Fläche: " << area() << std::endl;
    std::cout << std::endl;
}

double GeoEllipse::area() const {
    return maR * miR * M_PI;
}

double GeoEllipse::circumference() const {
    return M_PI * sqrt(2* (pow(maR, 2) + pow(miR, 2)));
}

void GeoEllipse::output() const {
    std::cout << "Ellipse, ID: " << getID() << std::endl;
    std::cout << "Major Radius: " << getmaR() << ", Minor Radius: " << getmiR() << std::endl;
    std::cout << "Umfang: " << circumference() << std::endl;
    std::cout << "Fläche: " << area() << std::endl;
    std::cout << std::endl;
}

double GeoCircle::area() const {
    return pow(r, 2)*M_PI;
}

double GeoCircle::circumference() const {
    return 2*M_PI*r;
}

void GeoCircle::output() const
{
    std::cout << "Kreis, ID: " << getID() << std::endl;
    std::cout << "Radius: " << getR() << std::endl;
    std::cout << "Umfang: " << circumference() << std::endl;
    std::cout << "Fläche: " << area() << std::endl;
    std::cout << std::endl;
}