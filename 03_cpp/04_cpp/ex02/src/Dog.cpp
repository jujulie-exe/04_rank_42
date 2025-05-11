#include "../include/Dog.hpp"
#include "../include/Brain.hpp"


Dog::Dog()
	: Animal("Dog"), b(new Brain())
{
    std::cout << this->getType() << " Default constructor called" << std::endl;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
    // ctor
}

Dog::Dog(Dog const & src)
	: Animal("Copy Dog"), b(new Brain(src.getPtrIdeas()))
{
    std::cout << this->getType() << " Copy constructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Houf Houf Houf" << std::endl;
}

void	Dog::setIdeas(size_t index, const std::string& idea)
{
	if ( index < MAX_IDEA)
	{
		this->b->ideas[index] = idea;
	}
	return ;
}

std::string	Dog::getIdeas(size_t index) const
{
	if ( index < MAX_IDEA)
		return b->ideas[index];
	else
		return b->ideas[MAX_IDEA - 1];
}

Brain&	Dog::getPtrIdeas( void ) const
{
	return *this->b;
}

Dog &Dog::operator=( Dog const &rhs)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
         this->type = rhs.getType();
		 if (b != nullptr);
			delete this->b;
		 this->b = new Brain();
		 *this->b = *rhs.b;
    }
    return *this;
}

Dog::~Dog()
{
	std::cout << "\033[35m" <<std::string(50, '-') << std::endl;
    std::cout << this->getType() <<" Destructor called" << std::endl;
	delete b;
    // dtor
}

