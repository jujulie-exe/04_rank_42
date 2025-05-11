#ifndef CAT_H
#define CAT_H
#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
 
class Cat : public Animal
{
	public:
		Cat();	//cannon
		Cat(Cat const & src);	//Cannon
		Cat& operator=(Cat const & rsh);	//Cannon

		// FUNZ
		virtual void		makeSound( void ) const override;
		void				setIdeas(size_t index, const std::string& idea);
		std::string			getIdeas(size_t index) const;
		Brain&				getPtrIdeas( void ) const;

		virtual ~Cat();	//Cannon
	private:
		Brain *b;
};
#endif // CAT_H

