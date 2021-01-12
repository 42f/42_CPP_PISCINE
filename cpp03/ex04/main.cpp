#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

#ifndef DIM_COLOR
# define DIM_COLOR    "\033[2m"
#endif

int		main( void )	{

	{
		std::cout << RED_COLOR << "[CONSTRUCTION]" << RESET_COLOR << std::endl;

		SuperTrap	super("Mega");

		std::cout << RESET_COLOR << std::endl;
		std::cout << RED_COLOR << "[DESTRUCTORS]" << RESET_COLOR << std::endl;
	}
	{
		std::cout << DIM_COLOR << "[CONSTRUCTION]" << std::endl << std::endl;
		SuperTrap	super("Mega");
		NinjaTrap	ninja1("Suki");
		NinjaTrap	ninja2("Eri");
		FragTrap	frag("Freddy");
		ScavTrap	scav("Skarl");
		std::cout << RESET_COLOR << std::endl;

		std::cout << RED_COLOR << "[SuperTrap ATTACK: ninja's special on " <<  frag.getName() << "]" << RESET_COLOR << std::endl;
		super.ninjaShoeBox(frag);
		std::cout << RED_COLOR << "[SuperTrap ATTACK: ninja's special on " <<  scav.getName() << "]" << RESET_COLOR << std::endl;
		super.ninjaShoeBox(scav);
		std::cout << RED_COLOR << "[SuperTrap ATTACK: ninja's special on " <<  ninja2.getName() << "]" << RESET_COLOR << std::endl;
		super.ninjaShoeBox(ninja2);

		std::cout << RED_COLOR << "[SuperTrap ATTACK: FragTrap on Marcel]" << RESET_COLOR << std::endl;
		super.vaulthunter_dot_exe("Marcel");
		std::cout << DIM_COLOR << "[DESTRUCTORS]" << RESET_COLOR << std::endl;
	}
	return (0);
}
