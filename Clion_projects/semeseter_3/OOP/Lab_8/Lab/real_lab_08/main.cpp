#include <iostream>


double division(double a, double b) {
    double erg = 0;
    if (b != 0) {
        erg = a / b;
    }
    return erg;
}


int main() {
    std::cout << division(3, 5) << std::endl;
    return 0;
}
