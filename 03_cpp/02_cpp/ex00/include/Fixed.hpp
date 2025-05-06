#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <ostream>

 
class Fixed
{
   public:
	Fixed();      //cannon
	Fixed(Fixed const & src);      //Cannon
	Fixed& operator=(Fixed const & rsh);     //Cannon
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	virtual	~Fixed();    //Cannon
   private:
		int	_n;
		static const int  _ns = 8;
};
#endif // FIXED_H
