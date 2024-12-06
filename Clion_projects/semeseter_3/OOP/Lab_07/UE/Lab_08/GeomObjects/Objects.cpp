//
// Created by nico on 06.12.24.
//
#include <iostream>
#include <cmath>
#include "Objects.h"

double GeoRect::area(double a, double b) const  {

    return a * b;
}

double GeoRect::circumference(double a, double b) const {
    return 2*a + 2*b;
}

void GeoRect::output() const{
    std::cout << "Rechteck" << std::endl;
    std::cout << "Seite a: " << getA() << ", Seite b: " << getB() << std::endl;
    std::cout << "Umfang: " << circumference(a,b) << std::endl;
    std::cout << "Fläche: " << area(a,b) << std::endl;
    std::cout << std::endl;
}

double GeoSquare::area(double a) const {
    return a * a;
}

double GeoSquare::circumference(double a) const {
    return a * 4;
}

void GeoSquare::output() const{
    std::cout << "Quadrat" << std::endl;
    std::cout << "Seite a: " << getA() << std::endl;
    std::cout << "Umfang: " << circumference(a) << std::endl;
    std::cout << "Fläche: " << area(a) << std::endl;
    std::cout << std::endl;
}

double GeoEllipse::area(double maR, double miR) const {
    return maR * miR * M_PI;
}

double GeoEllipse::circumference(double maR, double miR) const {
    return M_PI * sqrt(2* (pow(maR, 2) + pow(miR, 2)));
}

void GeoEllipse::output() const {
    std::cout << "Ellipse" << std::endl;
    std::cout << "Major Radius: " << getmaR() << ", Minor Radius: " << getmiR() << std::endl;
    std::cout << "Umfang: " << circumference(maR,miR) << std::endl;
    std::cout << "Fläche: " << area(maR,miR) << std::endl;
    std::cout << std::endl;
}