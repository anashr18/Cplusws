#include <iostream>
#include "car/car.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello, Carinit!" << std::endl;

    Car car(20, "Honda", 50);
    car.fillTank(100);
    car.accelerate(10);
    car.Dashboard();
    car.accelerate(20);
    car.Dashboard();
    car.brake();
    car.Dashboard();

    return 0;
}
