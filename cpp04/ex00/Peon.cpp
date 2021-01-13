#include "Peon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Peon::Peon()
{
}

Peon::Peon( std::string const name ) : Victim(name) {

	std::cout << "Zog Zog." << std::endl;
}

Peon::Peon( __attribute__((unused))const Peon & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Peon const & i )
{
	o << i.introduce();
	return o;
}

Peon &					Peon::operator=( Peon const & rhs )
{
	if (this != &rhs)
		Character::_name = rhs._name;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
