#include "../include/Fixed.hpp"

Fixed::Fixed()
	: _n( 0 )
{
	std::cout << "Default constructor called" << std::endl;
    // ctor
}

Fixed::Fixed(Fixed const & src)
	: _n(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
    // copy ctor
//    *this = src;
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

Fixed::~Fixed()
{
    // dtor
}

