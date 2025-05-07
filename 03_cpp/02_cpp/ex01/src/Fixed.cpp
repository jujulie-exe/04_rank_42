#include "../include/Fixed.hpp"

Fixed::Fixed()
	: _n( 0 )
{
	std::cout << "Default constructor called" << std::endl;
    // ctor
}

Fixed::Fixed(const int nbr)
	: _n(  nbr << this->_ns)
{

	std::cout << "[INT]constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float nbr)
	: _n(static_cast<int>(std::roundf(nbr * (1 << _ns))))
{
	std::cout << "[FLOAT]constructor called" << std::endl;
	return ;
}


Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
    	// copy ctor
    	*this = src;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_n) / (1 << _ns));
}

int	Fixed::toInt( void ) const
{
	return _n >> this->_ns;
}


Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
    {
        this->_n = rhs.getRawBits();
    }
    return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _n;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	if(raw != _n)
		_n = raw;
	return ;
}

std::ostream &operator<<(std::ostream &obj, Fixed const &rhs)
{
	 obj << rhs.getRawBits();
	 return (obj);
}

Fixed::~Fixed()
{
	std::cout << "Default Deconstructor called" << std::endl;
    // dtor
}

