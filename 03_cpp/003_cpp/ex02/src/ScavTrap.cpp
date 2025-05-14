#include "../include/ScavTrap.hpp"


ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}
ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap( name )
{
	ClapTrap::_healthPoint = 100;
	ClapTrap::_AttackPoint = 20;
	ClapTrap::_Stamina = 50;
	ClapTrap::_MaxPoint = _healthPoint;
    std::cout << "[ScavTrap] Parametre constructor called" << std::endl;
    // ctor
}

void	ScavTrap::attack(const std::string& target)
{
	if (_healthPoint > 0 && _Stamina > 0)
	{
		std::cout << _name << " ScavTrap ha dato " << this->_AttackPoint << " a " << target << std::endl;
		--_Stamina;
	}
	else if (_healthPoint > 0 && _Stamina <= 0)
		std::cout << _name << " ScavTrap non ha piu stamina" << std::endl;

	else
		std::cout << _name << " ScavTrap é morto" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_healthPoint > 0)
		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	return ; 
}

ScavTrap::ScavTrap(ScavTrap const & src)
	: ClapTrap(src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] Destructor called" << std::endl;
    // dtor
}

