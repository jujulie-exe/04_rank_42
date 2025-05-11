#include "../include/WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
	: type ("WrongAnimal")
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
    // ctor
}

WrongAnimal::WrongAnimal(std::string  type_)
		: type( type_)
{
    std::cout << "WrongAnimal Param constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

std::string	WrongAnimal::getType( void ) const
{
	return type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Just a WrongAnimal don't sound sorry sorry xoxo" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
    // dtor
}

