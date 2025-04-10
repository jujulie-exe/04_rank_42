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
		Contact(std::string pf, std::string  pl, std::string pn,std::string pnbr,std::string pd);
		Contact();
		~Contact();
	//	get_dsc( void ) const;
	//	get_nbr( void ) const;
		
};

#endif
