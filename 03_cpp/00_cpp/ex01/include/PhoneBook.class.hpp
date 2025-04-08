#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

 #include "Contac.class.hpp"

class	PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	add( void );
		void	search( void ) const;
		void	exit ( void ) ;
		size_t	index;
	private:
		Contact	_list[8];
		void	_print_frmt(std::string str) const ;
};


#endif
