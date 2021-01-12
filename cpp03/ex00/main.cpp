#include "FragTrap.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )	{

	std::cout << RED_COLOR;
	FragTrap	bob("Bob");
	FragTrap	marcel("Marcel", bob);
	std::cout << RESET_COLOR << std::endl;
	int			damage;

	std::cout << RED_COLOR << "[VAULT HUNTER]" << RESET_COLOR << std::endl;
	damage = marcel.vaulthunter_dot_exe("Bob");
	std::cout << std::endl;
	bob.takeDamage(damage);
	std::cout << std::endl;
	bob.beRepaired(15);
	std::cout << std::endl;

	std::cout << RED_COLOR << "[MELEE ATTACK]" << RESET_COLOR << std::endl;
	damage = bob.meleeAttack("Marcel");
	std::cout << std::endl;
	marcel.takeDamage(damage);
	std::cout << std::endl;

	std::cout << RED_COLOR << "[RANGED ATTACK]" << RESET_COLOR << std::endl;
	damage = bob.rangedAttack("Marcel");
	std::cout << std::endl;
	marcel.takeDamage(damage);
	std::cout << std::endl;

	std::cout << RED_COLOR ;
	return (0);
}
