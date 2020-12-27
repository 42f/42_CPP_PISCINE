#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int		main( void ) {
	std::cout << RED_COLOR << "[Instantiation of a Zombie on the Stack]" << RESET_COLOR << std::endl;
	Zombie	zombie1("Marcus");

	std::cout << RED_COLOR << "[Announce function call]" << RESET_COLOR << std::endl;
	zombie1.announce();

	std::cout << RED_COLOR << "[Zombie creation on the Heap]" << RESET_COLOR << std::endl;
	ZombieEvent::setZombieType("Brain_lover");
	Zombie	*baby1 = ZombieEvent::newZombie("Jim");

	std::cout << RED_COLOR << "[Zombie creation on the Heap]" << RESET_COLOR << std::endl;
	ZombieEvent::setZombieType("Face_chewer");
	Zombie	*baby2 = ZombieEvent::newZombie("Bob");

	std::cout << RED_COLOR << "[Announce function call]" << RESET_COLOR << std::endl;
	baby1->announce();
	baby2->announce();

	std::cout << RED_COLOR << "[Zombie deletion on the Heap]" << RESET_COLOR << std::endl;
	delete baby1;
	delete baby2;

	for (int i = 0; i < 5; i++)
	{
		std::cout << RED_COLOR << "[Zombie Random creation on the Heap] (" << i << "/4)" << RESET_COLOR << std::endl;
		ZombieEvent::randomChump();
	}
	std::cout << RED_COLOR << "[return (0);]" << RESET_COLOR << std::endl;
	return (0);
}
