#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>
#include <string>
#include <ostream>


class Harl
{
	private:
		void	_debug( void ) const;
		void	_info( void ) const;
		void	_warning( void ) const;
		void	_error( void ) const;
		void	(Harl::*_FunPTR[4])(void) const;
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
#endif
