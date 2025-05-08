#include .."ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(const std::string& name)
		: _name ( name ), _healthPoint ( 10 ), _AttackPoint ( 0 ), _Stammina( 10 )
{
    std::cout << "Parametre name constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_healthPoint > 0)
	{
		std::cout << "ClapTrap ha dato " << this->_AttackPoint << "a " << target << std::endl;
		_Stamina--;
	}
	else
		std::cout << "ClapTrap é morto" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Stamina > 0)
	{
		std::cout << "ClapTrap si ripara di " << amount << " e perde un punto di stamina" << "rimanendo con " << --_Stamina << std::endl;
		if (_healthPoint < 10)
		{
			_healthPoint += amount;
			if (_healthPoint > 10)
				_healthPoint = 10;
		}

	}
	else if (_healthPoint > 0  && _Stamina == 0)
		std::cout << "ClapTrap non puo piu riparsi" << std::endl;
	else 
		std::cout << "ClapTrap é morto" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}
