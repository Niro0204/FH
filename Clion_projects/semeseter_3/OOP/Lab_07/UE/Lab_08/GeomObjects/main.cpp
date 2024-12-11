#include <iostream>

#include "Objects.h"

int main() {
    GeoRect rect(5.0, 3.0);
    GeoSquare square(4.0);
    GeoEllipse ellipse(6.0, 4.0);
    GeoCircle circle(5.0);

    rect.output();
    square.output();
    ellipse.output();
    circle.output();

    return 0;
}
