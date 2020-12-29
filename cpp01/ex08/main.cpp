#include "Human.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )
{
	Human	bob;

	std::cout << RED_COLOR << "[Call for meleeAttack]" << RESET_COLOR << std::endl;
	bob.action("meleeAttack", "badGuy");
	std::cout << RED_COLOR << "[Call for intimidatingShoud]" << RESET_COLOR << std::endl;
	bob.action("intimidatingShout", "notSoGoodGuy");
	std::cout << RED_COLOR << "[Call for rangedAttack]" << RESET_COLOR << std::endl;
	bob.action("rangedAttack", "thisGuy");
	std::cout << RED_COLOR << "[Call with wrong function name]" << RESET_COLOR << std::endl;
	bob.action("pouette", "superVilain");
	std::cout << RED_COLOR << "[Call with empty argument]" << RESET_COLOR << std::endl;
	bob.action("", "badGuy");
	return (0);
}
