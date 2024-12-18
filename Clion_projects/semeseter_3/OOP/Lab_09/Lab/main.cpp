// Templates

#include <iostream>

class Demo {
public:
    int val;
};


// c-basiert
int maxIntC(const int a, const int b) {
    return a > b ? a : b;
}

double maxDoubleC(const double a, const double b) {
    return a > b ? a : b;
}

// klassisch C++
// static ad-hoc polymorphisms
int maxCpp(const int a, const int b) {
    return a > b ? a : b;
}

double maxCpp(const double a, const double b) {
    return a > b ? a : b;
}

// Templates
// funktionsfamilie mit den folgenden generischen Datentypen
template <typename T>
//template <class T> // in diesem Fall macht class das gleiche wie typename
// Best practice: "const by reference"
const T& max(const T& a, const T& b) {
    return a > b ? a : b;
}

// Template spezialisierung
template <>
const Demo& max(const Demo& a, const Demo& b) {
    return a.val > b.val ? a : b;
}

template <>
const std::string& max(const std::string& a, const std::string&b ) {
    std::cerr << "Für String nicht anwendbar!" << std::endl;
    return "";
}

// template nimmt mehrere datentypen
template <typename T1, typename T2>
const T1& foo(const T1& a, const T2& b, int c) { // reihenfolge ist wichtig, erster übergebender Datentyp ist auch der Rückgabedatentyp
    return a > b ? a + c : b + c;
}


int main() {

    // implizite instanziierung
    int a = max(123, 551);
    float f = max(34.56f, 65.56f);
    double d = max(85.5, 34.56);
    // Template argument deduction funktioniert hier nicht
    //weil es kein Template für zwei unterschiedliche Parameter
    //-typen hat
    //static parametric Polymorphism
    // auto a = max(5,3.5)

    // expliziter
    auto a2 = max<>(34, 65);

    // explizite instanziierung
    auto a3 = max<double>(65, 78.7);
    //auto a4 = max<std::string>("Nico","Anel");

    //std::cout << a4 << std::endl;

    Demo d1;
    d1.val = 1;
    Demo d2;
    d2.val = 45;

    auto a5 = max<Demo>(d1, d2);

    auto test1 = foo(2, 1.5, 123);
    std::cout << test1 << std::endl;

    return 0;
}
