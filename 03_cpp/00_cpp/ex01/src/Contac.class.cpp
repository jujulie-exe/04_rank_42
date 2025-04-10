#include "../include/Contac.class.hpp"

Contact::Contact() 
    : _fname(""), _lname(""), _nname(""), _nbr(""), _dsc("") {}

Contact::Contact(const char* pf, const char* pl, const char* pn, const char* pnbr, const char* pd)
    : _fname(pf), _lname(pl), _nname(pn), _nbr(pnbr), _dsc(pd) {
}

void Contact::get_info_contact( void ) const
{
	std::cout << "First Name: " <<_fname << std::endl;
	std::cout << "Last Name: " <<_lname << std::endl;
	std::cout << "NickName: " <<_nname << std::endl;
	std::cout << "Number: " <<_nbr << std::endl;
	std::cout << "Dark Secret: " <<_dsc << std::endl;
}

std::string Contact::get_fname( void ) const
{
	return  _fname;
}

std::string Contact::get_lname( void ) const
{
	return  _lname;
}

std::string Contact::get_nname( void ) const
{
	return  _nname;	
}

Contact::~Contact( void )
{
	return ;
}
