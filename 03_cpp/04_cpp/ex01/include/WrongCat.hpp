#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "../include/WrongAnimal.hpp"
 
class WrongCat : public WrongAnimal
{
	public:
		WrongCat();	//cannon
		WrongCat(WrongCat const & src);	//Cannon
		WrongCat& operator=(WrongCat const & rsh);	//Cannon
		void		makeSound( void ) const;
		virtual ~WrongCat();	//Cannon
	private:
};
#endif // CAT_H

