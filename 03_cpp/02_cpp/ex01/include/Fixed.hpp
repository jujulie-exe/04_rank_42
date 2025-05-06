#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <ostream>

 
class Fixed
{
   public:
	Fixed();      //cannon
	Fixed(const int nbr); //devo convertire in numero a virgola fissa
	Fixed(const float nbrFloat); // deve convertire in un numero a virgola fissa
	Fixed(Fixed const & src);      //Cannon
	Fixed& operator=(Fixed const & rsh);     //Cannon
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	virtual	~Fixed();    //Cannon
   private:
	int	_n;
	static const int  _ns = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif // FIXED_H
