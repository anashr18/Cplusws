#include <iostream>
#include "integer/Integer.h"

int main()
{
    Integer num1(5);
    Integer num2 = num1;
    Integer num3(num2);
    std::cout << "num2 value: " << num1.getValue() << std::endl;
    return 0;
}