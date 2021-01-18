#include "BabyPeon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "MightyGoblin.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void )	{

	std::cout << RED_COLOR << "----------MAIN FROM SUBJECT-----------" << RESET_COLOR << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");

		Victim jim("Jimmy");
		Peon joe("Joe");

		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	std::cout << RED_COLOR << "----------END MAIN FROM SUBJECT--------" << RESET_COLOR << std::endl;

	std::cout << RED_COLOR << "----------PART 1 : adds MightyGoblin from Victim-----------" << RESET_COLOR << std::endl;
	{
	Sorcerer robert("Robert", "the Magnificent");

	robert.sayHello();
	std::cout << robert;

	MightyGoblin	mel("Mel");

	mel.sayHello();
	std::cout << mel;

	robert.polymorph(mel);

	Victim			mel2("Mel2");
	mel2 = mel;

	std::cout << mel2;
	robert.polymorph(mel2);

	Peon	marcus("Marcus");

	marcus.sayHello();
	robert.polymorph(marcus);
	}
	std::cout << RED_COLOR << "----------PART 2 : test Peon (from Victim)-----------" << RESET_COLOR << std::endl;
	{
	Peon	p("Peon");

	p.sayHello();

	}
	std::cout << RED_COLOR << "----------PART 3 : adds BabyPeon from Peon (from Victim)-----------" << RESET_COLOR << std::endl;
	{

	BabyPeon	bp("babyPeon");

	bp.sayHello();

	}
	return (0);
}



