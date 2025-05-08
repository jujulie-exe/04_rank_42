#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <ostream>
#include <ostream>
#include <cmath>

 
class Fixed
{
   public:
	// ***CONSTRUTOR
	Fixed();      //cannon
	Fixed(const int nbr); //devo convertire in numero a virgola fissa
	Fixed(const float nbrFloat); // deve convertire in un numero a virgola fissa
	Fixed(Fixed const & src);      //Cannon


	//OPERATOR*****
		// ***OPERATOR  COMPARAASION*******
	bool operator==(Fixed const &rsh) const;
	bool operator<(Fixed const &rsh) const;
	bool operator>(Fixed const &rsh) const;
	bool operator<=(Fixed const &rsh) const;
	bool operator>=(Fixed const &rsh) const;
	bool operator!=(Fixed const &rsh) const;
		//***OPERATOR  ARITHEMIC*******
	Fixed operator*(Fixed const &rsh);
	Fixed operator/(Fixed const &rsh);
	Fixed operator-(Fixed const &rsh);
	Fixed operator+(Fixed const &rsh);
	Fixed& operator=(Fixed const &rsh);
		//***OPERATOR INCRIMENTAL******
	Fixed& operator++();    
	Fixed operator++(int);    
		//***OPERATOR DINCRIMENTAL******
	Fixed& operator--();    
	Fixed operator--(int);    




	// FUNZION FOR INTERN WORKING CLASS****
	int			getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int			toInt( void ) const;
		// FUNZIONI DI RITORNO MAX
	static const Fixed&	max(const Fixed &REF1, const Fixed &REF2); 
	static Fixed&		max(Fixed &REF1, Fixed &REF2);
		// FUNZIONI DI RITORNO MIN
	static const Fixed&	min(const Fixed &REF1,const Fixed &REF2); 
	static Fixed&		min(Fixed &REF1, Fixed &REF2); 



	//*** DECOSTR
	virtual		~Fixed();    //Cannon
   private:
	int	_n;
	static const int  _ns = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif // FIXED_H
