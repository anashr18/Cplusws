#include "car.h"
#include <iostream>

void Car::accelerate(int amount)
{
    speed += amount;
    fuel -= 0.5f;
}

void Car::fillTank(float amount)
{
    fuel += amount;
}

void Car::brake()
{
    speed = 0;
}

void Car::AddPassanger(int num)
{
    passangers += num;
}

void Car::Dashboard()
{
    std::cout << "Speed: " << speed << ", Fuel: " << fuel << ", Passengers: " << passangers << std::endl;
}
