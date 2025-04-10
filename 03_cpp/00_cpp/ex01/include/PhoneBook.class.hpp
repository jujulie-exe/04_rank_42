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
		void	_print_frmt(const std::string& str) const ;
		bool	_all_digit(const std::string& str) const;
		bool	_getline_value(std::string& str);
		int	_my_atoi(const std::string& str) const;
};


#endif
