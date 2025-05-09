#include "../include/ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(const std::string& name)
		: _name ( name ), _healthPoint ( 10 ), _AttackPoint ( 0 ), _Stamina( 10 ), _MaxPoint( _healthPoint )
{
    std::cout << "[CalpTrap] Parametre name constructor called" << std::endl;
    // ctor
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_healthPoint > 0 && _Stamina > 0)
	{
		std::cout << _name << " ClapTrap ha dato " << this->_AttackPoint << " a " << target << std::endl;
		--_Stamina;
	}
	else if (_healthPoint > 0 && _Stamina <= 0)
		std::cout << _name << " ClapTrap non ha piu stamina" << std::endl;

	else
		std::cout << _name << " ClapTrap é morto" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_healthPoint > 0)
	{
		std::cout << _name << " ClapTrap prendo " << amount << " di danno ";
		_healthPoint -= amount;
		if (_healthPoint < 0)
			_healthPoint = 0;
		std::cout << _name << " rimanendo con " << _healthPoint << std::endl;
	}
	else
		return ;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Stamina > 0 && _healthPoint > 0)
	{
		std::cout << _name << " ClapTrap si ripara di " << amount << " e perde un punto di stamina rimanendo con " << --_Stamina << std::endl;
		if (_healthPoint < _MaxPoint)
		{
			_healthPoint += amount;
			if (_healthPoint > _MaxPoint)
				_healthPoint = _MaxPoint;
		}
		std::cout << _name << " Ora ClapTrap ha " << _healthPoint << " punti di vita" << std::endl;

	}
	else if (_healthPoint > 0  && _Stamina <= 0)
		std::cout << _name << " ClapTrap non puo piu riparsi" << std::endl;
	else 
		std::cout << _name << " ClapTrap é morto" << std::endl;
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
    std::cout << "[ClapTrap] Destructor called" << std::endl;
    // dtor
}
