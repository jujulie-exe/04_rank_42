#ifndef DOG_H
#define DOG_H
#include "../include/Animal.hpp"
 
class Dog : public Animal
{
	public:
		Dog();	//cannon
		Dog(Dog const & src);	//Cannon
		Dog& operator=(Dog const & rsh);	//Cannon
		virtual void		makeSound( void ) const;
		virtual ~Dog();	//Cannon
	private:
};
#endif // DOG_H

