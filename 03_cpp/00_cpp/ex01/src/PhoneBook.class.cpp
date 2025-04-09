#include "../include/PhoneBook.class.hpp"
#include "../include/Contac.class.hpp"
#include <iostream>


PhoneBook::PhoneBook( void )
	: index( 0 ) {
}

void	PhoneBook::exit( void )
{
}

bool	PhoneBook::_all_digit(const std::string& str) const
{
	size_t i = 0;

	if (str.empty())
        	return false;
	while (i < str.length()) 
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
        	i++;
	}
	return (true);
}

bool	PhoneBook::_getline_value(std::string& str)
{
	
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "\033[31m Value empty is not allowed ʕっ•ᴥ•ʔっ\033[0m" << std::endl;
		return false;
	}
	str.erase(0, str.find_first_not_of(" 	"));
	str.erase(str.find_last_not_of(" 	") + 1);
	return true;
}

void	PhoneBook::add ( void )
{
	size_t	i = 0;
	while (!_list[i].get_fname().empty() && i < 8)
		i++;
	if (i >= 8)
	{
		std::cout << "List of contact is full" << std::endl;
		i = 0;
	}

	std::string fname, lname, nname, dsc, input_nbr;
	size_t nbr = 0;
	
	std::cout << "\033[1;36mInserisci First Name: \033[0m";
	if (_getline_value(fname) == false)
		return ;
	std::cout << "\033[1;36mInserisci Last Name: \033[0m";
	if (_getline_value(lname) == false)
		return ;
	std::cout << "\033[1;36mInserisci Nickname: \033[0m";
	if (_getline_value(nname) == false)
		return ;
	std::cout << "\033[41mInserisci Numero: \033[0m";
	std::getline(std::cin, input_nbr);
	if (_all_digit(input_nbr) == false || input_nbr.length() > 10)
	{
		std::cout << "\033[31m JUST DIGIT && LENGTH < 10 ʕっ•ᴥ•ʔっ\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;36mInserisci Dark Secret: \033[0m";
	if (_getline_value(dsc) == false)
		return ;
	
	nbr = std::stol(input_nbr);
	_list[i] = Contact(fname.c_str(), lname.c_str(), nname.c_str(), nbr, dsc.c_str());
	
	std::cout << "Contatto aggiunto all’indice " << i << std::endl;
}


void	PhoneBook::_print_frmt(const std::string& str) const
{
	if (str.length() > 10)
		std::cout << std::setfill ( ' ' ) << std::setw (10) << str.substr(0, 8) + ".";
	else
		std::cout << std::setfill ( ' ' ) << std::setw (10) << str;
	std::cout << "|";
	return ;
}

void	PhoneBook::search( void ) const
{
	int	y;

	y = 0;
	if (_list[0].get_fname().empty())
		return ;
	while (!_list[y].get_fname().empty())
	{
		 //std::cout << std::setfill ('x') << std::setw (10);
		std::cout << "\033[32m" <<std::string(50, '-') << std::endl;
		std::cout << " | " <<  std::setfill ( ' ' ) << std::setw (10) << y << "|";
		_print_frmt(_list[y].get_fname());
		_print_frmt(_list[y].get_lname());
		_print_frmt(_list[y].get_nname());
		std::cout << std::endl;
		y++;
	}
	std::cout << std::string(50, '-') << "\033[0m" << std::endl;
	std::string input;
	std::cout << "Please, enter index: ";
	std::getline (std::cin, input);
	if (_all_digit(input) == false)
		return ;
	int i = std::stoi(input);
	if (i > y)
		std::cout << "index don't exist" << std::endl;
	else
		_list[i].get_info_contact();
}

PhoneBook::~PhoneBook( void )
{
	return ;
}
