#include "Fixed.hpp"
#include <iostream>

int		main( void )	{

	// Fixed const c( 42.42f );
	std::cout << "____a______" << std::endl;
	Fixed a;
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "____b______" << std::endl;
	Fixed const b( 10 );
	std::cout << "b is " << b << std::endl;
	std::cout << "____c_____" << std::endl;
	Fixed const c( -43.625f );
	std::cout << "c is " << c << std::endl;
	std::cout << "____d_____" << std::endl;
	Fixed const d( b );
	std::cout << "d is " << d << std::endl;
	std::cout << "__________" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "__________" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}


