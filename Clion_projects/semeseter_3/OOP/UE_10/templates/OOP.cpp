#include <algorithm>
#include <array>
#include <iostream>
#include <functional>
#include <cmath>




template<typename T>
std::array<T,3>SortThree(const T& a, const T& b, const T& c)
{
    std::array<T,3> result = {a,b,c};
    std::sort(result.begin(),result.end(),std::greater<T>());

    return result;
}

template<typename T>
bool Swap3(T& a, T& b, T& c){

    bool swap = false;
    if(a>b){
        std::swap(a,b);
        swap = true;
    }
    if(b>c){
        std::swap(b,c);
        swap = true;
    }
    if(a>c){
        std::swap(a,c);
        swap = true;

    }
    return swap;
}

template<typename T1, typename T2>
int SizeCompare(const T1& a, const T2& b){

    if(sizeof(a) < sizeof(b)){
        return -1;
    }
    if(sizeof(a) == sizeof(b))
    {
        return 0;
    }
    return 1;
}

template <typename T>
T TRound(T a, int b) {
    T factor = std::pow(10, -b);
    return std::round(a * factor) / factor;
}

template <typename T>
T TTrunc(T a, int b) {

    int numDigits = std::floor(std::log10(std::abs(a))) + 1;

    if (b > numDigits) {
        b = numDigits-1;
    }

    T factor = std::pow(10, b);

    if (b >= 0) {
        return std::floor(a / factor) * factor;
    } else {
        return std::floor(a * factor) / factor;
    }
}


int main()
{
    int a = 5, b = 3, c = 8;
    auto sorted = SortThree(a, b, c);

    for(auto i : sorted)
    {
        std::cout << i << std::endl;
    }

    bool result = Swap3(a, b, c);

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    std::cout << "Werte wurden getauscht: " << std::boolalpha << result << std::endl;

    int x = 42;
    double y = 3.14;

    auto result2 = SizeCompare(x, y);

    std::cout << "Ergebnis: " << result2 << std::endl;

    double ad = 567.89 ;

    std::cout << "ad = " << ad << std::endl;
    std::cout << "Rundung auf Hunderter: " << TRound(ad, 2) << std::endl;
    std::cout << "Rundung auf Zehner: " << TRound(ad, 1) << std::endl;
    std::cout << "Rundung auf Einer: " << TRound(ad, 0) << std::endl;
    std::cout << "Rundung auf 1/10: " << TRound(ad, -1) << std::endl;
    std::cout << "Rundung auf 1/100: " << TRound(ad, -2) << std::endl;

    std::cout << "ad = " << ad << std::endl;
    std::cout << "Abschneiden auf Hunderter: " << TTrunc(ad, 2) << std::endl;  // 500.00
    std::cout << "Abschneiden auf Zehner: " << TTrunc(ad, 1) << std::endl;     // 560.00
    std::cout << "Abschneiden auf Einer: " << TTrunc(ad, 0) << std::endl;      // 567.00
    std::cout << "Abschneiden auf 1/10: " << TTrunc(ad, -1) << std::endl;      // 567.80
    std::cout << "Abschneiden auf 1/100: " << TTrunc(ad, -2) << std::endl;     // 567.89

    std::cout << "Test mit 10: " << TTrunc(ad, 10) << std::endl;

    return 0;
}
