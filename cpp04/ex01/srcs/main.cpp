#include "Character.hpp"

#include "AWeapon.hpp"
#include "Enemy.hpp"

#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"

#include <iostream>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main() {

	std::cout << RED_COLOR << "----------MAIN FROM SUBJECT-----------" << RESET_COLOR << std::endl;
	{
		Character* me = new Character("me");

		std::cout << *me;

		Enemy* b = new RadScorpion();

		AWeapon* pr = new PlasmaRifle();

		AWeapon* pf = new PowerFist();

		me->equip(pr);

		std::cout << *me;

		me->equip(pf);

		me->attack(b);
		std::cout << *me;
		me->equip(pr);

		std::cout << *me;

		me->attack(b);

		std::cout << *me;
		me->attack(b);

		std::cout << *me;
	}
	std::cout << RED_COLOR << "----------END MAIN FROM SUBJECT--------" << RESET_COLOR << std::endl << std::endl;

	{
		std::cout << RED_COLOR << "[WEAPON CTOR]" << RESET_COLOR << std::endl;
		PlasmaRifle		wa;

		std::cout << wa.getName() << " - " << wa.getAPCost() << " - " << wa.getDamage() << std::endl;
		wa.attack();

		std::cout << RED_COLOR << "[CHARACTER CTOR]" << RESET_COLOR << std::endl;
		Character		player("Player1");
		std::cout << RED_COLOR << "[ENEMY CTOR]" << RESET_COLOR << std::endl;
		Enemy*			badGuy = new RadScorpion();

		std::cout << RED_COLOR << "[CHARACTER << OVERLOAD]" << RESET_COLOR << std::endl;
		std::cout << player;
		std::cout << RED_COLOR << "[ENEMY ATTACK WITH NO WEAPON(null)]" << RESET_COLOR << std::endl;
		player.attack(badGuy);
		std::cout << RED_COLOR << "[ENEMY EQUIP FUNCTION CALL]" << RESET_COLOR << std::endl;
		player.equip(&wa);
		std::cout << RED_COLOR << "[CHARACTER << OVERLOAD]" << RESET_COLOR << std::endl;
		std::cout << player;
		std::cout << RED_COLOR << "[LOOP OF 10 ATTACKS FROM CHARACTER ON ENEMY]" << RESET_COLOR << std::endl;
		for (int i = 0; i < 10 && badGuy != NULL; i++)
		{
			std::cout << badGuy->getType() << " has " <<  badGuy->getHP() << " HP points."<< std::endl << std::endl;
			player.attack(badGuy);
			if (badGuy->getHP() == 0)
				break;
		}
		std::cout << RED_COLOR << "[ENEMY DIED ONCE IT HAS REACHED 0 HP POINTS]" << RESET_COLOR << std::endl;
	}

	return 0;
}
