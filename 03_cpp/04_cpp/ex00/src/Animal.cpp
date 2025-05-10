#include "../include/Animal.hpp"


Animal::Animal()
	: type ("Animal")
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
    // ctor
}

Animal::Animal(std::string  type_)
		: type( type_)
{
    std::cout << "Animal Param constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::string	Animal::getType( void ) const
{
	return type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Just a Animal don't sound sorry sorry xoxo" << std::endl;
}

Animal &Animal::operator=( Animal const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
    // dtor
}

