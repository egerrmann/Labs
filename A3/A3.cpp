#include <iostream>

using namespace std;

extern "C" {
    void __cdecl ArrayMult(int* array1, int* array2, int amount, int* result1);
    void __cdecl CheckSum1(unsigned int a, unsigned int b, unsigned int c, int result);
    void __cdecl CheckSum2(unsigned int a, unsigned int b, unsigned int c, int result);
    void __cdecl CheckSum3(unsigned int a, unsigned int b, unsigned int c, int result);
}

int main()
{
    int arr1[4] = { 2000001, -3000000, -1000000, 1 }, arr2[4] = { 2000000, 2000000, -2000000, 2 }, n = 4, result1[3] = { 0, 0, 0 };
    ArrayMult(arr1, arr2, n, result1);
    std::cout << result1[0] << std::endl;
    std::cout << result1[1] << std::endl;
    std::cout << result1[2] << std::endl;
    unsigned int a = 2000000000, b = 2000000000, c = 3000000000;
    int result = 0;
    CheckSum1(a, b, c, result);
    if (result == 1)
    {
        std::cout << "False" << std::endl;
        return 0;
    }
    CheckSum2(a, b, c, result);
    if (result == 1)
    {
        std::cout << "False" << std::endl;
        return 0;
    }
    CheckSum3(a, b, c, result);
    if (result == 1)
    {
        std::cout << "False" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "True" << std::endl;
    }
    return 0;
}
