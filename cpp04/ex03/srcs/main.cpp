# include "IMateriaSource.hpp"
# include "ICharacter.hpp"

# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

int main( void ) 	{

	std::cout << RED_COLOR << "----------MAIN FROM SUBJECT-----------" << RESET_COLOR << std::endl;
	{
		IMateriaSource*	src = new MateriaSource();

		AMateria	*tmp0 = new Ice();
		// src->learnMateria(new Ice());
		src->learnMateria(tmp0);
		delete tmp0;
		tmp0 = new Cure();
		// src->learnMateria(new Cure());
		src->learnMateria(tmp0);
		delete tmp0;

		ICharacter* 	me = new Character("me");
		AMateria* 		tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter*		bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << RED_COLOR << "----------END MAIN FROM SUBJECT--------" << RESET_COLOR << std::endl << std::endl;
	std::cout << std::endl << RED_COLOR << "[ TEST EQUIP, USE, XP ]" << RESET_COLOR << std::endl;
	{
		Character	player1("player1");
		Character	player2("player2");

		player1.equip(NULL);
		player1.use(0, player2);
		player1.unequip(0);
		player1.use(42, player2);

		AMateria	*MCure = new Cure;

		player1.equip(MCure);
		size_t	loopSize = 10;
		for (size_t i = 0; i < loopSize; i++)
		{
			std::cout << "Call use() #" << i + 1  << "  -> ";
			player1.use(0, player2);
			std::cout << "  -- XP of MCure = " << MCure->getXP() << std::endl;
		}
		std::cout << "XP of MCure should be " << loopSize * 10 << std::endl;
		player1.unequip(0);
		player1.unequip(0);
		player1.use(0, player2);

		delete MCure;
	}
	std::cout << std::endl << RED_COLOR << "[ TEST MATERIA SOURCE LEARN ABILITY ]" << RESET_COLOR << std::endl;
	{

		Character	player1("player1");
		Character	player2("player2");

		MateriaSource	src;
		AMateria		*MCure = new Cure;

		src.learnMateria(MCure);
		delete MCure;

		AMateria		*someMateria = src.createMateria("cure");

		std::cout << "-- XP of someMateria = " << someMateria->getXP() << std::endl;
		player1.equip(someMateria);
		player1.use(0, player2);
		std::cout << "-- XP of someMateria = " << someMateria->getXP() << std::endl;

		// player1.unequip(0);
		// delete someMateria;
	}
	std::cout << std::endl << RED_COLOR << "[ TEST PLAYER DEEP COPY ]" << RESET_COLOR << std::endl;
	{
		Character	player1("player1");
		Character	player2("player2");

		MateriaSource	src;
		AMateria		*mat = new Ice;

		player1.equip(mat);
		std::cout << std::endl << RED_COLOR << "	-- [ PLAYER 1 -> ice on player 2 ]" << RESET_COLOR << std::endl;
		player1.use(0, player2);
		std::cout << std::endl << RED_COLOR << "	-- [ PLAYER 2 -> ice on player 1 ]" << RESET_COLOR << std::endl;
		player2.use(0, player1);
		std::cout << std::endl << RED_COLOR << "------- [ player2 = player1 ]" << RESET_COLOR << std::endl;
		player2 = player1;
		std::cout << std::endl << RED_COLOR << "	-- [ PLAYER 1 -> ice on player 2 ]" << RESET_COLOR << std::endl;
		player1.use(0, player2);
		std::cout << std::endl << RED_COLOR << "	-- [ PLAYER 2 -> ice on player 1 ]" << RESET_COLOR << std::endl;
		player2.use(0, player1);

	}
	std::cout << std::endl << RED_COLOR << "[ TEST MATERIA SOURCE DEEP COPY ]" << RESET_COLOR << std::endl;
	{
		Character	player1("player1");
		Character	player2("player2");

		MateriaSource	src1;
		MateriaSource	src2;
		AMateria		*mat = new Ice;
		src1.learnMateria(mat);
		delete mat;

		player1.equip(src1.createMateria("ice"));

		std::cout << std::endl << RED_COLOR << "	-- [ SRC 1 -- PLAYER 1 -> ice on player 2 ]" << RESET_COLOR << std::endl;
		player1.use(0, player2);

		player1.equip(src2.createMateria("ice"));
		std::cout << std::endl << RED_COLOR << "	-- [ SRC 2 -- PLAYER 1 -> ice on player 2 ]" << RESET_COLOR << std::endl;
		player1.use(1, player2);

		std::cout << std::endl << RED_COLOR << "------- [ src2 = src1 ]" << RESET_COLOR << std::endl;
		src2 = src1;

		player1.equip(src2.createMateria("ice"));
		std::cout << std::endl << RED_COLOR << "	-- [ SRC 2 -- PLAYER 1 -> ice on player 2 ]" << RESET_COLOR << std::endl;
		player1.use(1, player2);
	}
	return 0;
}
