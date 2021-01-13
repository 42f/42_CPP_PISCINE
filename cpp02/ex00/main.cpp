#include "Fixed.hpp"
#include <iostream>

int		main( void )	{

	std::cout << "----------  MAIN FROM SUBJECT ----------" << std::endl;
	{
		Fixed a;
		Fixed b( a );
		Fixed c;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "------- END MAIN FROM SUBJECT ----------" << std::endl;
	return (0);
}
