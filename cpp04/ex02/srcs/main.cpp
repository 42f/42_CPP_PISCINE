#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	std::cout << RED_COLOR << "----------MAIN FROM SUBJECT-----------" << RESET_COLOR << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;

		ISquad* vlc = new Squad;

		vlc->push(bob);
		vlc->push(jim);

		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}

		delete vlc;
	}
	std::cout << RED_COLOR << "----------END MAIN FROM SUBJECT--------" << RESET_COLOR << std::endl << std::endl;
	std::cout << std::endl << RED_COLOR << "[Test with push limits - with TacticalMarine]" << RESET_COLOR << std::endl;
	{
		ISpaceMarine *bob = new TacticalMarine;
		TacticalMarine **team = new TacticalMarine*[10];

 		for (int i = 0; i < 10; i++)
		 	team[i] = new TacticalMarine;
		Squad vlc;

		std::cout << std::endl << "GetCount() function call return = " << vlc.getCount() << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << "Try to push bob to the squad... return = " << vlc.push(bob) << std::endl;
		std::cout << "GetCount() function call return = " << vlc.getCount() << std::endl << std::endl;

 		for (int i = 0; i < 10; i++)	{
			std::cout << "Squad content = " << vlc.getCount() << std::endl;
			vlc.push(team[i]);
		}
		std::cout << "After : Squad content = " << vlc.getCount() << std::endl;
		delete [] team;
	}

	std::cout << std::endl << RED_COLOR << "[Test with push limits - with AssaultTerminator]" << RESET_COLOR << std::endl;
	{
		AssaultTerminator **team = new AssaultTerminator*[10];
		Squad				vlc;

 		for (int i = 0; i < 10; i++)
		 	team[i] = new AssaultTerminator;

 		for (int i = 0; i < 10; i++)	{
			std::cout << "Squad content = " << vlc.getCount() << std::endl;
			vlc.push(team[i]);
		}
		std::cout << "After : Squad content = " << vlc.getCount() << std::endl;
		delete [] team;
	}

	std::cout << std::endl << RED_COLOR << "[Test with clone]" << RESET_COLOR << std::endl;
	{
		ISpaceMarine	*bob = new AssaultTerminator;
		ISpaceMarine	*jim = new TacticalMarine;
		Squad			vlc;

		vlc.push(jim);
		for (int i = 0; i < 10; i++)
		{
			ISpaceMarine *tmpClone;
			if (i % 2 == 0)
				tmpClone = bob->clone();
			else
				tmpClone = jim->clone();
			std::cout << "Clone address:        " << tmpClone << std::endl;
			std::cout << RED_COLOR << "[call push function]" << RESET_COLOR << std::endl;
			vlc.push(tmpClone);
			std::cout << "Last pushed address : " << vlc.getUnit(vlc.getCount() - 1 ) << std::endl << std::endl;
		}
		std::cout << "After : Squad content = " << vlc.getCount() << std::endl << std::endl;
		delete bob;
	}

	std::cout << std::endl << RED_COLOR << "[Test deep copy]" << RESET_COLOR << std::endl;
	{
	return 0;
}
