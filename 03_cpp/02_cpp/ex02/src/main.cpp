#include "../include/Fixed.hpp"
int main( void ) 
{
	Fixed a( 1.10f );
	Fixed b( 200.10f );
	Fixed c = a + b;
	Fixed d;
	a = d;
	std::cout << c.toFloat() << " IS FLOAT" << std::endl;
	std::cout << c.toInt() << " IS [INT]" << std::endl;

	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << f << std::endl;
	Fixed const l( Fixed( 10.50f ) / Fixed( 2.25f ) );
	std::cout << l << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
