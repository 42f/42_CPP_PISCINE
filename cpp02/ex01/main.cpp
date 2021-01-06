#include "Fixed.hpp"
#include <iostream>
#include <limits.h>

void	testFloat(float const nbr)	{
	std::cout << std::endl << "________ TEST FLOAT with: " << nbr << "_____________" << std::endl;
	Fixed a( nbr );
	std::cout << "a is " << a << " from STREAM" << std::endl;
	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
}

void	testInt(int const nbr)	{
	std::cout << std::endl << "________ TEST INT with: " << nbr << "_____________" << std::endl;
	Fixed a( nbr );
	std::cout << "a is " << a << " from STREAM" << std::endl;
	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
}

int		main( void )	{

	testFloat( 1234.4321f );
	testFloat( 42.42f );
	testFloat( 42.50f );
	testFloat( 42.92f );
	testFloat( -42.42f );
	// testFloat( __FLT_MAX__ );
	// testFloat( 123456.42f );
	// testFloat( 0.0f );
	// testFloat( 0.1f );
	// testFloat( 1.0f );
	// testFloat( 0.25f );
	// testInt(0);
	// testInt(42);
	// testInt(-42);
	// testInt(16777215);
	// testInt(16777216);
	// testInt(16777217);
	return (0);
}
