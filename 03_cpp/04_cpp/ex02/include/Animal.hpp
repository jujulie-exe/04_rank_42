#ifndef ANIMAL_H
#define ANIMAL_H
 
#include <ostream>
#include <iostream>
#include <string>
#include <iomanip>

class Animal
{
	public:
		// COSTRUTTORI
		Animal();	//cannon
		Animal(Animal const & src);	//Cannon

		//FUNZIONI
		virtual std::string	getType( void ) const;
		virtual void		makeSound( void ) const = 0;

		//OPERATORI
		Animal& operator=(Animal const & rsh);	//Cannon

		//DTOR
		virtual ~Animal();	//Cannon
	protected:
		std::string	type;
		Animal(std::string type_);

	private:
};
#endif // ANIMAL_H

