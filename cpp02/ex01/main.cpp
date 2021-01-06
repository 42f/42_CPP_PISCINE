#include "Fixed.hpp"
#include <iostream>
#include <limits.h>

void	test(float const f)	{
	std::cout << std::endl << "________ TEST with: " << f << "_____________" << std::endl;
	Fixed a( f );
	std::cout << "a is " << a << " from STREAM" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "____________________________________________" << std::endl << std::endl;
}

int		main( void )	{

	test( 1234.4321f );
	test( 42.42f );
	test( -42.42f );
	test( __FLT_MAX__ );
	test( 123456.42f );
	test( 0.0f );
	test( 0.1f );
	test( 1.0f );
	test( 0.25f );
	return (0);
}
