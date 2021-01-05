#include "Fixed.hpp"
#include <iostream>

int		main( void )	{

	// Fixed const c( 42.42f );
	std::cout << "____a__123.4321____" << std::endl;
	// Fixed a( 1234.4321f );
	Fixed a;
	a = Fixed( 1234.4321f );
	// std::cout << "a is " << a << std::endl;
	std::cout << "____b__10____" << std::endl;
	Fixed const b( 10 );
	// std::cout << "b is " << b << std::endl;
	std::cout << "____c__-43.625___" << std::endl;
	Fixed const c( -43.625f );
	// std::cout << "c is " << c << std::endl;
	std::cout << "____d__-8___" << std::endl;
	Fixed const d( -8 );
	// std::cout << "d is " << d << std::endl;
	// std::cout << "__________" << std::endl;
	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	// std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	// std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	// std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	// std::cout << "__________" << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}
