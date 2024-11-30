#include <iostream>
#include "Integer.h"

Integer::Integer(int value)
{
    this->m_pInt = new int(value);
}

int Integer::getValue() const
{
    return *m_pInt;
}

void Integer::setValue(int value)
{
    *m_pInt = value;
}

Integer::~Integer()
{
    std::cout << "Destructor called " << *m_pInt << std::endl;
    delete m_pInt;
}
// copy constructor
Integer::Integer(const Integer &other) : m_pInt(new int(*other.m_pInt))
{
    std::cout << "Copy constructor called" << std::endl;
}
// assignment copy = operator
Integer &Integer::operator=(const Integer &other)
{
    if (this != &other)
    {
        delete this->m_pInt;
        this->m_pInt = new int(*other.m_pInt);
    }
    return *this;
}

Integer::Integer(Integer &&other) : m_pInt(other.m_pInt)
{
    std::cout << "Move constructor called" << std::endl;
    other.m_pInt = nullptr;
}

// Integer &Integer::operator=(const Integer &&other)
// {
//     // TODO: insert return statement here
// }
