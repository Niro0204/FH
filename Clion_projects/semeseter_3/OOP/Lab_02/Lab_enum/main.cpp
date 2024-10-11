#include <iostream>
#include <vector>


enum color {
    red,
    blue,
    green
};

void printColor(color c) {

    switch (c) {
        case red:
            std::cout << "Rot";
        break;
        case blue:
            std::cout << "Blau";
        break;
        case green:
            std::cout << "Grün";
        break;
    }

}

int main() {

    auto c = green;
    std::cout << c << std::endl;

    printColor(c);

    int ivar = 5;

    // implizite typ umwandlung
    double dvar = ivar;
    // explizit im c style --> nix gut, nix machen
    dvar = (double)ivar;
    // explizite typumwandlung c++ style
    dvar = static_cast<double>(ivar); // --> diese gut, static-> zur programmierzeit

    return 0;
}
