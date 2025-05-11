#ifndef BRAIN_H
#define BRAIN_H
#include "../include/Animal.hpp"
#define MAX_IDEA 100
 
class Brain
{
	public:
		//CTOOR
		Brain();	//cannon
		Brain(Brain const & src);	//Cannon
		

		//OPERATOR
		Brain& operator=(Brain const & rsh);	//Cannon
		
		//VARIABLE
		std::string	ideas[MAX_IDEA];

		//DTOR
		virtual ~Brain();	//Cannon
	private:
};
#endif // BRAIN_H

