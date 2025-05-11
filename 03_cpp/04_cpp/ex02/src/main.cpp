#include "../include/Dog.hpp"
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"
#define MAX_ARRAY 10

void	my_test_Cat( void )
{
	Cat l;
	Cat h;
	l.setIdeas(5, "I love lasagne");
	l.setIdeas(99, "Other idea");
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	h = l;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	std::cout << l.getIdeas(5) << std::endl;
	std::cout << h.getIdeas(5) << std::endl;
	std::cout << h.getIdeas(99) << std::endl;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	Cat y = h;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
	std::cout << y.getIdeas(99) << std::endl;
	std::cout << y.getType() << std::endl;
	std::cout << "\033[00m" <<std::string(50, '-') << std::endl;
}
void	my_test_Dog( void )
{
	Dog l;
	Dog h;
	l.setIdeas(5, "I love lasagne");
	l.setIdeas(99, "Other idea");
	h = l;
	std::cout << l.getIdeas(5) << std::endl;
	std::cout << h.getIdeas(5) << std::endl;
	std::cout << h.getIdeas(99) << std::endl;
	Dog y = h;
	std::cout << y.getIdeas(99) << std::endl;
}
int	main()
{
	std::cout << "MY OWN TEST" << std::endl;
	my_test_Dog();	
	my_test_Cat();	
	std::cout << "TEST MAIN EXE" << std::endl;
	size_t i = 0;

	Animal	*meta[MAX_ARRAY];
	// test for abstract class
	//Animal test;
	std::cout << "CTOR CALL " << MAX_ARRAY << std::endl;
	while(i < MAX_ARRAY)
	{
		if ((i % 2) == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < MAX_ARRAY)
	{
		meta[i]->makeSound();
		i++;
	}
	std::cout << i << std::endl;
	i = 0;
	std::cout << "CALL DCTOR" << std::endl;
	while ( i < MAX_ARRAY)
	{
		delete meta[i];
		i++;
	}
	return 0;
}
