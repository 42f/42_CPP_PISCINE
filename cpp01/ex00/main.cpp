#include "Pony.hpp"
#include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )
{

	std::cout << RED_COLOR << "[Instantiation of a Pony on the Stack]" << RESET_COLOR << std::endl;
	Pony stackPony = ponyOnTheStack("bob");
	std::cout << RED_COLOR << "[Allocation of a Pony on the Heap]" << RESET_COLOR << std::endl;
	Pony *heapPony = ponyOnTheHeap("jim");

	std::cout << RED_COLOR << "[Delete of the Pony on the Heap]" << RESET_COLOR << std::endl;
	delete heapPony;
	std::cout << RED_COLOR << "[Return (0);]" << RESET_COLOR << std::endl;
	return (0);
}
