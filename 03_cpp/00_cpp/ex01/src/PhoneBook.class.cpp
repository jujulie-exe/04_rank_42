#include "../include/PhoneBook.class.hpp"
#include "../include/Contac.class.hpp"
#include <iostream>


PhoneBook::PhoneBook( void )
	: index( 0 ) {
}

void	PhoneBook::exit( void )
{
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
	
	std::cout << "Inserisci First Name: ";
	std::getline(std::cin, fname);
	if (fname.empty())
		return ;
	std::cout << "Inserisci Last Name: ";
	std::getline(std::cin, lname);
	if (lname.empty())
		return ;
	std::cout << "Inserisci Nickname: ";
	std::getline(std::cin, nname);
	if (nname.empty())
		return ;
	std::cout << "Inserisci Numero: ";
	std::getline(std::cin, input_nbr);
	if (input_nbr.empty())
		return ;
	std::cout << "Inserisci Dark Secret: ";
	std::getline(std::cin, dsc);
	if (dsc.empty())
		return ;
	
	_list[i] = Contact(fname.c_str(), lname.c_str(), nname.c_str(), nbr, dsc.c_str());
	
	std::cout << "Contatto aggiunto all’indice " << i << std::endl;
}

void	PhoneBook::_print_frmt(std::string str) const
{
	if (str.length() > 10)
		std::cout << std::setfill ( ' ' ) << std::setw (10) << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setfill ( ' ' ) << std::setw (10) << str << "|";
	return ;
}

void	PhoneBook::search( void ) const
{
	int	y;

	y = 0;
	while (!_list[y].get_fname().empty())
	{
		 //std::cout << std::setfill ('x') << std::setw (10);
		std::cout << std::string(50, '-') << std::endl;
		std::cout << " | " <<  std::setfill ( ' ' ) << std::setw (10) << y << "|";
		_print_frmt(_list[y].get_fname());
		_print_frmt(_list[y].get_lname());
		_print_frmt(_list[y].get_nname());
		std::cout << std::endl;
		y++;
	}
	std::cout << std::string(50, '-') << std::endl;
	std::string input;
	std::cout << "Please, enter index: ";
	std::getline (std::cin, input);
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
