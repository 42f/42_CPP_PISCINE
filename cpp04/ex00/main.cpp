#include "Sorcerer.hpp"
#include "Victim.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )	{

	std::cout << RED_COLOR << "----------MAIN FROM SUBJECT-----------" << RESET_COLOR << std::endl;
	{
/*
		Sorcerer robert("Robert", "the Magnificent");

		Victim jim("Jimmy");
		Peon joe("Joe");

		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
*/
	}
	std::cout << RED_COLOR << "----------END MAIN FROM SUBJECT--------" << RESET_COLOR << std::endl;

	Sorcerer robert("Robert", "the Magnificent");

	robert.sayHello();
	std::cout << robert << std::endl;

	Victim	mel("Mel");

	mel.sayHello();
	// std::cout << mel << std::endl;
	return (0);
}



