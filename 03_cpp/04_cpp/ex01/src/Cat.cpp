#include "../include/Cat.hpp"


Cat::Cat()
	: Animal("Cat")
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
    // ctor
}

Cat::Cat(Cat const & src)
	: Animal("Cat")
{
    std::cout << this->getType() << " Copy constructor called" << std::endl;
    *this = src;
}
void	Cat::makeSound( void ) const
{
	std::cout << "Meoooow Meoooow Meoooow" << std::endl;
}

Cat &Cat::operator=( Cat const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << this->getType() <<" Destructor called" << std::endl;
    // dtor
}

