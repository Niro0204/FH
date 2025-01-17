#include <iostream>
#include <iomanip>

std::string& operator << (std::string& str, const int rotator)
{
    for (int i = 0; i < rotator; i++)
    {
        char temp = str.front();
        str.erase(str.begin());
        str.append(1, temp);
    }

    return str;
}

std::string& operator >> (std::string& str, const int rotator)
{
    for (int i = 0; i < rotator; i++)
    {
        char temp = str.back();
        str.pop_back();
        str.insert(str.begin(), temp);
    }

    return str;
}

int main()
{
    std::string input = "LET IT SNOW";

    std::string copy1 = input;
    std::string copy2 = input;

    std::cout << std::quoted(copy1 << 3) << '\n'; // " IT SNOWLET"
    std::cout << std::quoted(copy2 >> 10) << '\n'; // "ET IT SNOWL"
}
