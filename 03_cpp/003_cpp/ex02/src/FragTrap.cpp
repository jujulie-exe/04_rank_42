#include "../include/FragTrap.hpp"


FragTrap::FragTrap()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap( name )
{
	_healthPoint = 100;
	_Stamina = 100;
	_AttackPoint = 30;
	_MaxPoint = _healthPoint;
    std::cout << "[FragTrap] constructor called" << std::endl;
    // ctor
}

FragTrap::FragTrap(FragTrap const & src)
	: ClapTrap(src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_healthPoint > 0)
		std::cout << "This member function displays a positive high-fives request on the standard output."<< std::endl;
	return ;
}

FragTrap &FragTrap::operator=( FragTrap const &rhs)
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

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] Destructor called" << std::endl;
    // dtor
}

