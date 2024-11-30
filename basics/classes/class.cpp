#include <stdio.h>
#include <string>
#include <iostream>

class Cookie
{
private:
    std::string color_name;

public:
    Cookie(const std::string &color) : color_name(color) {}
    std::string getName()
    {
        return this->color_name;
    }
    void setName(const std::string &color)
    {
        this->color_name = color;
    }
};

int main(int argc, char *argv[])
{
    Cookie *cookie1 = new Cookie("blue");
    Cookie *cookie2 = new Cookie("red");
    std::cout << cookie1->getName() << std::endl;
    cookie2->setName("black");
    std::cout << cookie2->getName() << std::endl;

    return 0;
}