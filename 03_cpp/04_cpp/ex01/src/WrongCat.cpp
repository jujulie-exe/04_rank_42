#include "../include/WrongCat.hpp"


WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
    // ctor
}

WrongCat::WrongCat(WrongCat const & src)
	: WrongAnimal("WrongCat")
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
void	WrongCat::makeSound( void ) const
{
	std::cout << "Meoooow Meoooow Meoooow" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << this->getType() <<" Destructor called" << std::endl;
    // dtor
}

