# include "IMateriaSource.hpp"
# include "ICharacter.hpp"

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

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

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
	std::cout << std::endl << RED_COLOR << "[ MAIN BVALETTE ]" << RESET_COLOR << std::endl;
	{

	}

	return 0;
}
