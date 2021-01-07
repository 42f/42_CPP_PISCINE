#include "Fixed.hpp"
#include <iostream>
#include <limits.h>

void	testConstuctorCopy(int const nbr)	{
	std::cout << std::endl << "________ TEST COPY  with: " << nbr << "_____________" << std::endl;
	Fixed src (nbr);
	Fixed a = src;
	std::cout 			   << "           a.toFLOAT ---> " << a.toFloat() << std::endl;
	std::cout 			   << "           a.toINT -----> " << a.toInt() << std::endl;
	std::cout 			   << "                a with << " << a << std::endl;
}

void	testFloat(float const nbr)	{
	std::cout << std::endl << "________ TEST FLOAT with: " << nbr << "_____________" << std::endl;
	Fixed a( nbr );
	std::cout 			   << "           a.toFLOAT ---> " << a.toFloat() << std::endl;
	std::cout 			   << "           a.toINT -----> " << a.toInt() << std::endl;
	std::cout 			   << "                a with << " << a << std::endl;
}

void	testInt(int const nbr)	{
	std::cout << std::endl << "________ TEST INT with: " << nbr << "_____________" << std::endl;
	Fixed a( nbr );
	std::cout 			   << "         a.toFLOAT ---> " << a.toFloat() << std::endl;
	std::cout 			   << "         a.toINT -----> " << a.toInt() << std::endl;
	std::cout 			   << "              a with << " << a << std::endl;
}

int		main( void )	{

	std::cout << "----------  MAIN FROM SUBJECT ----------" << std::endl;
	{
		Fixed 		a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	std::cout << "------- END MAIN FROM SUBJECT ----------" << std::endl;

	testFloat( 1234.4321f );
	testFloat( 42.49f );
	testFloat( 42.42f );
	testFloat( 42.50f );
	testFloat( 42.92f );
	testFloat( -42.42f );
	testFloat( 123456.42f );
	testFloat( -0.0f );
	testFloat( 0.0f );
	testFloat( 0.1f );
	testFloat( 1.0f );
	testFloat( 0.25f );
	testFloat( -0.25f );
	testFloat( 3.5f );
	testFloat( -3.5f );
	testInt(0);
	testInt(42);
	testInt(-42);
	testInt(8388607);
	testInt(16777215);
	testInt(16777216);
	testInt(16777217);
	testInt(42);
	testInt(-42);
	testConstuctorCopy(42);
	testConstuctorCopy(-42);
	return (0);
}
