#include "../include/Contac.class.hpp"
#include "../include/PhoneBook.class.hpp"
int	main()
{
	std::string	cmd;
	PhoneBook	istance;
	while (std::getline(std::cin, cmd) && !std::cin.eof())
	{
		if (cmd == "ADD")
			istance.add();
		if (cmd == "SEARCH")
			istance.search();
		if (cmd == "EXIT")
			break ;
	}
	return (0);
}
