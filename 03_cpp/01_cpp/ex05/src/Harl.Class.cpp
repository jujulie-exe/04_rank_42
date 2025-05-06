#include "../include/Harl.Class.hpp"

Harl::Harl() 
{
	_FunPTR[0] = &Harl::_debug;
	_FunPTR[1] = &Harl::_info;
	_FunPTR[2] = &Harl::_warning;
	_FunPTR[3] = &Harl::_error;
	return ;
}

void	Harl::_debug( void ) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void ) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void )const
{
	std::cout << "WARNING" << std::endl;
}
void	Harl::_error( void ) const
{
	std::cout << "ERROR" << std::endl;
}

void	Harl::complain( std::string level)
{
	size_t	i = 0;	
	std::string info[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""}; 
	while (!info[i].empty())
	{
		if (info[i] == level)
			(this->*_FunPTR[i])();
		i++;
	}
}

Harl::~Harl()
{
	return ;
}
