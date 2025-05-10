#include "../include/Brain.hpp"


Brain::Brain()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Brain::Brain(Brain const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Brain &Brain::operator=( Brain const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor called" << std::endl;
	//delete this->ideas;
    // dtor
}

