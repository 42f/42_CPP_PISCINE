#include <iostream>
#include "Integer.hpp"

int		main( void )
{
	Integer		a(42);
	Integer		b(10);
	Integer		c(0);

	c = a + b;

	std::cout << "------" << std::endl;
	std::cout << c << std::endl;
}
