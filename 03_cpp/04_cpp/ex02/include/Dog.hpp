#ifndef DOG_H
#define DOG_H
#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
 
class Dog : public Animal
{
	public:
		Dog();	//cannon
		Dog(Dog const & src);	//Cannon

		//FUNZIONI
		virtual void		makeSound( void ) const override;
		void				setIdeas(size_t index, const std::string& idea);
		std::string			getIdeas(size_t index) const;
		Brain&				getPtrIdeas( void ) const;


		//OPERATOR
		Dog& operator=(Dog const & rsh);	//Cannon
		
		//DTOR	
		virtual ~Dog();	//Cannon
	private:
		//VARIABLE
		Brain	*b;
};
#endif // DOG_H

