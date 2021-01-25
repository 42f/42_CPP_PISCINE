# include "header.hpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

#include <string>

Base * generate(void)	{

	int		n;

	srand(reinterpret_cast<long int>(&n));
	switch (rand() % 3 % 3)
	{
	case 0:
		std::cout << "A" << std::endl;
		return (static_cast<Base *>(new A));

	case 1:
		std::cout << "B" << std::endl;
		return (static_cast<Base *>(new B));

	default:
		std::cout << "C" << std::endl;
		return (static_cast<Base *>(new C));
	}
}

void	identify_from_pointer(Base * ptr)	{

	if (dynamic_cast<A*>(ptr) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr) != NULL)
		std::cout << "C" << std::endl;
}

void	identify_from_reference( Base & ref)	{

	try {
		__attribute__((unused))A & aRef = dynamic_cast<A&>(ref);
		std::cout << "A" << std::endl;
	}
	catch ( std::exception & e ) {};
	try {
		__attribute__((unused))B & bRef = dynamic_cast<B&>(ref);
		std::cout << "B" << std::endl;
	}
	catch ( std::exception & e ) {};
	try {
		__attribute__((unused))C & cRef = dynamic_cast<C&>(ref);
		std::cout << "C" << std::endl;
	}
	catch ( std::exception & e ) {};

}

int		main( void ) 	{


	std::cout << RED_COLOR << "[Generate] ---> " << RESET_COLOR;
	Base *output = generate();

	if (output != NULL)
	{

		std::cout << RED_COLOR << "[Identify by Pointer] ---> " << RESET_COLOR;
		identify_from_pointer(output);
		std::cout << RED_COLOR << "[Identify by Ref] ---> " << RESET_COLOR;
		identify_from_reference(*output);
	}

	delete output;
	return (0);
}
