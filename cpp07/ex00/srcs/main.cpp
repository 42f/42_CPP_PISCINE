# include "header.hpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) 	{

	std::cout << RED_COLOR << "-------- [START MAIN FROM SUBJECT] -----------" << RESET_COLOR << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	}
	std::cout << RED_COLOR << "-------- [END   MAIN FROM SUBJECT] -----------" << RESET_COLOR << std::endl;

	return (0);
}
