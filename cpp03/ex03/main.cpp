#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )	{

	{
		std::cout << RED_COLOR << "[CONSTRUCTION]" << std::endl << std::endl;
		NinjaTrap	ninja1("Suki");
		NinjaTrap	ninja2("Eri");
		FragTrap	frag("Freddy");
		ScavTrap	scav("Skarl");
		std::cout << RESET_COLOR << std::endl;

		std::cout << RED_COLOR << "[ATTACK: ninja's special on " <<  frag.getName() << "]" << RESET_COLOR << std::endl;
		ninja1.ninjaShoeBox(frag);
		std::cout << RED_COLOR << "[ATTACK: ninja's special on " <<  scav.getName() << "]" << RESET_COLOR << std::endl;
		ninja1.ninjaShoeBox(scav);
		std::cout << RED_COLOR << "[ATTACK: ninja's special on " <<  ninja2.getName() << "]" << RESET_COLOR << std::endl;
		ninja1.ninjaShoeBox(ninja2);
		std::cout << RED_COLOR << "[DESTRUCTORS]" << RESET_COLOR << std::endl;
	}

	return (0);
}
