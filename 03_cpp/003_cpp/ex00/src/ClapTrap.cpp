#include "../include/ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(const std::string& name)
		: _name ( name ), _healthPoint ( 10 ), _AttackPoint ( 0 ), _Stamina( 10 )
{
    std::cout << "Parametre name constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(ClapTrap const & src)
		: _name (src._name ), _healthPoint ( src._healthPoint ), _AttackPoint ( src._AttackPoint ), _Stamina( src._Stamina )
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_healthPoint > 0 && _Stamina > 0)
	{
		std::cout << "ClapTrap ha dato " << this->_AttackPoint << " a " << target << std::endl;
		--_Stamina;
	}
	else if (_healthPoint > 0 && _Stamina <= 0)
		std::cout << "ClapTrap non ha piu stamina" << std::endl;

	else
		std::cout << "ClapTrap é morto" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_healthPoint > 0)
	{
		std::cout << "ClapTrap prendo " << amount << " di danno";
		_healthPoint -= amount;
		if (_healthPoint < 0)
			_healthPoint = 0;
		std::cout << " rimando con " << _healthPoint << std::endl;
	}
	else
		return ;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Stamina > 0 && _healthPoint > 0)
	{
		std::cout << "ClapTrap si ripara di " << amount << " e perde un punto di stamina rimanendo con " << --_Stamina << std::endl;
		if (_healthPoint < 10)
		{
			_healthPoint += amount;
			if (_healthPoint > 10)
				_healthPoint = 10;
		}
		std::cout << "Ora ClapTrap ha " << _healthPoint << " punti di vita" << std::endl;

	}
	else if (_healthPoint > 0  && _Stamina <= 0)
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
