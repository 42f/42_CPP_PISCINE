#include "AssaultTerminator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// AssaultTerminator::AssaultTerminator( AssaultTerminator const & src )
// {
// 	(void)src;
// }

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

ISpaceMarine*	AssaultTerminator::clone( void ) const {

	ISpaceMarine	*output = new AssaultTerminator;
	return (output);
}


void			AssaultTerminator::battleCry( void ) const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}


void			AssaultTerminator::rangedAttack( void ) const {
	std::cout << "* does nothing *" << std::endl;
}


void			AssaultTerminator::meleeAttack( void ) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
