#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iomanip>
#include <string>
#include <iostream>
class 	Contact
{
	public:
		Contact();
		Contact(const char* pf, const char* pl, const char* pn, size_t pnbr, const char* pd);
		~Contact();
		void	get_info_contact( void ) const;
		std::string	get_fname( void ) const;
		std::string	get_lname( void ) const;
		std::string	get_nname( void ) const;
	//	get_dsc( void ) const;
	//	get_nbr( void ) const;
		
	private:
		std::string _fname;
		std::string _lname;
		std::string _nname;
		std::string _dsc;
		size_t	_nbr;
};

#endif
