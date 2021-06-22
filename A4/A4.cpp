#include <iostream>

extern "C" bool _cdecl IsPalindrom(char* s);
extern "C" int _cdecl DeleteBracers(char* s, int length);

int main()
{
    std::cout << "Enter the line to check if it's a polyndrom: " << std::endl;
    char c[100];
    std::cin >> c;
    if (IsPalindrom(c)) {
        std::cout << "It's a polyndrom" << std::endl;
    }
    else {
        std::cout << "It's not a polyndrom" << std::endl;
    }

    std::cout << "Enter the line (text in brackets will be deleted): " << std::endl;
    char d[100];
    std::cin >> d;

    std::cout << DeleteBracers(d, strlen(d)) << std::endl;
    std::cout << d;

    return 0;
}