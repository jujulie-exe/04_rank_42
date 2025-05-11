#include "../include/Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
    // ctor
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
	size_t	i = 0;
	while (i < MAX_IDEA)
	{
		this->ideas[i] = src.ideas[i];
		i++;
	}
//    *this = src;
}

Brain &Brain::operator=( Brain const &rhs)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		size_t	i = 0;
		while (i < MAX_IDEA)
		{
			this->ideas[i] = rhs.ideas[i];
			i++;
		}
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
	//delete this->ideas;
    // dtor
}

