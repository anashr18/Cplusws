#include <iostream>
#include <cstdint>
#include "my_lib.h"

void print_hello_world()
{
    std::cout << "FRESHHHH test!!! Hello World again with options!\n";
}

std::uint32_t factorial(std::uint32_t number)
{
    return number <= 1 ? 1 : factorial(number - 1) * number;
}