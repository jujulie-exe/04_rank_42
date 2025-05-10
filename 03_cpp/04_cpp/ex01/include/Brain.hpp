#ifndef BRAIN_H
#define BRAIN_H
#include "../include/Animal.hpp"
 
class Brain
{
	public:
		//CTOOR
		Brain();	//cannon
		Brain(Brain const & src);	//Cannon
		

		//OPERATOR
		Brain& operator=(Brain const & rsh);	//Cannon
		
		//VARIABLE
		std::string	ideas[100];

		//DTOR
		virtual ~Brain();	//Cannon
	private:
};
#endif // BRAIN_H

