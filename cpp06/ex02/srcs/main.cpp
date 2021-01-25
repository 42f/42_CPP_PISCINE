// # include "header.hpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

#include <string>

class Base	{

	public:
		virtual ~Base( void );
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base * generate(void)	{

	// int		n;

	// srand(time(NULL));
	// n = rand() % 3;
	Base *aOutput = static_cast<Base *>(new A);
	return (aOutput);
	// switch (n % 3)
	// {
	// case 0:
	// 	return (new A);

	// case 1:
	// 	return (new B);

	// default:
	// 	return (new C);
	// }
}

int		main( void ) 	{

	std::cout << RED_COLOR << std::endl << "[--]" << RESET_COLOR << std::endl;

	Base *output = generate();

	(void)output;
	// delete output;
	return (0);
}
