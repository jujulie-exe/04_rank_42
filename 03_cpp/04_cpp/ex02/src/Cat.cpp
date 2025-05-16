#include "../include/Cat.hpp"


Cat::Cat()
	: Animal("Cat"), b(new Brain())
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
    // ctor
}

Cat::Cat(Cat const & src)
	: Animal("Cat Copy"), b(new Brain(*src.b))
{
    std::cout << this->getType() << " Copy constructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meoooow Meoooow Meoooow" << std::endl;
}

void	Cat::setIdeas(size_t index, const std::string& idea)
{
	if ( index < MAX_IDEA)
	{
		this->b->ideas[index] = idea;
	}
	return ;
}

std::string	Cat::getIdeas(size_t index) const
{
	if ( index < MAX_IDEA)
		return b->ideas[index];
	else
		return b->ideas[MAX_IDEA - 1];
}

Brain&	Cat::getPtrIdeas( void ) const
{
	return *this->b;
}

Cat &Cat::operator=( Cat const &rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
		 if (b != NULL)
			delete this->b;
		 this->b = new Brain();
		 *this->b = *rhs.b;
    }
    return *this;
}

Cat::~Cat()
{
	std::cout << "\033[32m" <<std::string(50, '-') << std::endl;
    std::cout << this->getType() <<" Destructor called" << std::endl;
	delete b;
    // dtor
}

