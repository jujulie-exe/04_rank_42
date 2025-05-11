#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
 
#include <ostream>
#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		// COSTRUTTORI
		WrongAnimal();	//cannon
		WrongAnimal(WrongAnimal const & src);	//Cannon

		//FUNZIONI
		 std::string	getType( void ) const;
		 void		makeSound( void ) const;

		//OPERATORI
		WrongAnimal& operator=(WrongAnimal const & rsh);	//Cannon

		//DTOR
		virtual ~WrongAnimal();	//Cannon
	protected:
		std::string	type;
		WrongAnimal(std::string type_);

	private:
};
#endif // ANIMAL_H

