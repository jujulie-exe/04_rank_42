#include "../include/ScavTrap.hpp"


ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}
ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap( name )
{
	_healthPoint = 100;
	_AttackPoint = 20;
	_Stamina = 50;
	_MaxPoint = _healthPoint;
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
	if (_healthPoint > 0)
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
		_healthPoint = rhs._healthPoint;
		_AttackPoint = rhs._AttackPoint;
        _Stamina = rhs._Stamina;
        _MaxPoint = rhs._MaxPoint;
        // this->_n = rhs.getValue();
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] Destructor called" << std::endl;
    // dtor
}

