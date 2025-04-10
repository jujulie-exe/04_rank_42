#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iomanip>
#include <string>
#include <iostream>
class 	Contact
{
	private:
		std::string _fname;
		std::string _lname;
		std::string _nname;
		std::string _nbr;
		std::string _dsc;
	public:
		void	get_info_contact( void ) const;
		std::string	get_fname( void ) const;
		std::string	get_lname( void ) const;
		std::string	get_nname( void ) const;
		Contact(const char* pf, const char* pl, const char* pn, const char *pnbr, const char* pd);
		Contact();
		~Contact();
	//	get_dsc( void ) const;
	//	get_nbr( void ) const;
		
};

#endif
