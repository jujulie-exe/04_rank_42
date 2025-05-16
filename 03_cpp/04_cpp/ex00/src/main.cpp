#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int	main()
{
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	const Animal* meta = new Animal();
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	const Animal* j = new Dog();
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	const Animal* i = new Cat();
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	delete meta;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	delete i;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	delete j;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	const WrongAnimal* f = new WrongCat();
	std::cout << f->getType() << " " << std::endl;
	f->makeSound();
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	delete f;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	return 0;
}
