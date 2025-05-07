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
// OPERETOR OVER
	//***OPERATOR  ARITHEMIC*******
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
   	{
        	this->_n = rhs.getRawBits();
   	}
	return *this;
}

Fixed	Fixed::operator+(Fixed const &rsh)
{
	Fixed Result;
	Result.setRawBits(this->_n + rsh.getRawBits());
	return Result;
}

Fixed Fixed::operator*(Fixed const &rhs)
{
 	Fixed result;
 	result.setRawBits((this->_n * rhs.getRawBits()) >> _ns);  // Dividi per 256 usando shift
 	return result;
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	return ( this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rsh)
{
	std::cout << "Minus assignment operator called" << std::endl;
	int tmp = this->_n - rsh.getRawBits();
	Fixed n;
	n.setRawBits(tmp);
	return n;
}
	//***OPERATOR  INCREMENTAL*******
Fixed&	Fixed::operator++()
{
	this->_n++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++_n;
	return tmp;
}
	//***OPERATOR  DENCREMENTAL*******
Fixed&	Fixed::operator--()
{
	this->_n--;
	return *this;
}
Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--_n;
	return tmp;
}

	// ***OPERATOR  COMPARAASION*******
bool Fixed::operator==(Fixed const &rsh) const
{
	return (this->getRawBits() == rsh.getRawBits());
}

bool Fixed::operator!=(Fixed const &rsh) const
{
	return (this->getRawBits() != rsh.getRawBits());
}

bool Fixed::operator<=(Fixed const &rsh) const
{
	return (this->getRawBits() <= rsh.getRawBits());
} 

bool Fixed::operator>=(Fixed const &rsh) const
{
	return (this->getRawBits() >= rsh.getRawBits());
} 

bool Fixed::operator>(Fixed const &rsh) const
{
	return (this->getRawBits() > rsh.getRawBits());
} 

bool Fixed::operator<(Fixed const &rsh) const
{
	return (this->getRawBits() < rsh.getRawBits());
} 

 
 


std::ostream &operator<<(std::ostream &obj, Fixed const &rhs)
{
	 obj << rhs.toFloat();
	 return (obj);
}

Fixed::~Fixed()
{
	std::cout << "Default Deconstructor called" << std::endl;
    // dtor
}

