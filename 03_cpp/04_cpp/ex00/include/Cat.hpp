#ifndef CAT_H
#define CAT_H
#include "../include/Animal.hpp"
 
class Cat : public Animal
{
	public:
		Cat();	//cannon
		Cat(Cat const & src);	//Cannon
		Cat& operator=(Cat const & rsh);	//Cannon
		virtual void		makeSound( void ) const override;
		virtual ~Cat();	//Cannon
	private:
};
#endif // CAT_H

