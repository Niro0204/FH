#include <iostream>
#include "Complex.h"

int main() {
    Complex x, y;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    std::cout << z << std::endl;
    return 0;
}
