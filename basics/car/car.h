#pragma once
#include <string>
#include <iostream>

class Car
{
private:
    int speed;         // Speed of the car
    std::string model; // Model of the car
    int passangers;    // Number of passengers
    float fuel;        // Amount of fuel

public:
    // Constructor to initialize speed, model, and passengers
    Car(int s, std::string m, int p)
        : speed(s), model(m), passangers(p), fuel(0.0f) {}
    ~Car()
    {
        std::cout << "Car destroyed" << std::endl;
    };
    // Member functions
    void accelerate(int amount);
    void fillTank(float amount);
    void brake();
    void AddPassanger(int num);
    void Dashboard();
};
