#include "../include/Dog.hpp"


Dog::Dog()
	: Animal("Dog")
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
    // ctor
}

Dog::Dog(Dog const & src)
	: Animal("Copy Dog")
{
    std::cout << this->getType() << " Copy constructor called" << std::endl;
    *this = src;
}
void	Dog::makeSound( void ) const
{
	std::cout << "Houf Houf Houf" << std::endl;
}

Dog &Dog::operator=( Dog const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << this->getType() <<" Destructor called" << std::endl;
    // dtor
}

