#include "Zombie.hpp"
#include "ZombieHorde.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) {

	std::cout << RED_COLOR << "[Instantiation of a new Horde of 5 Zombied]" << RESET_COLOR << std::endl;
	ZombieHorde		horde1(5);
	std::cout << RED_COLOR << "[Instantiation of a new Horde of 15 Zombied]" << RESET_COLOR << std::endl;
	ZombieHorde		horde2(15);

	std::cout << RED_COLOR << "[return (0);]" << RESET_COLOR << std::endl;
	return (0);
}
