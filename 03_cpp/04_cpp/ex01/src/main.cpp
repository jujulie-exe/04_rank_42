#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* f = new Dog();
	const Animal* i = new Cat();
	f = j;
	delete j;//should not create a leak
	delete i;
	delete f;
	return 0;
}
