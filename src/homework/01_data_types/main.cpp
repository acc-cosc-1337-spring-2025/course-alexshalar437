#include "data_types.h"
#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    int result = multiply_numbers(num);
    std::cout << "Result: " << result << "\n";

    int num1 = 4;
    result = multiply_numbers(num1);
    std::cout << "Result: " << result << "\n";

    return 0;
}
