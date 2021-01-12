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
		std::cout << RED_COLOR << "[INITIALIZATION of a Fragtrap object]" << RESET_COLOR << std::endl;
		FragTrap f("bob");
		std::cout << RED_COLOR << "[DESTRUCTION of a Fragtrap object]" << RESET_COLOR << std::endl;
	}

	{
		std::cout << RED_COLOR << "[INITIALIZATION of a Scavtrap object]" << RESET_COLOR << std::endl;
		ScavTrap f("bob");
		std::cout << RED_COLOR << "[DESTRUCTION of a Scavtrap object]" << RESET_COLOR << std::endl;
	}

	std::cout << std::endl << "________FragTrap_________" << std::endl;

	{
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
	}

	std::cout << std::endl << RESET_COLOR <<  "________ScavTrap_________" << std::endl;

	{
		std::cout << RED_COLOR;
		ScavTrap	bob("Bob");
		ScavTrap	marcel("Marcel", bob);
		std::cout << RESET_COLOR << std::endl;
		int			damage;

		std::cout << RED_COLOR << "[CHALLENGE NEW COMER]" << RESET_COLOR << std::endl;
		damage = marcel.challengeNewcomer ("Bob");
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
	}

	return (0);
}
