#include "MightyGoblin.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MightyGoblin::MightyGoblin()
{
}

MightyGoblin::MightyGoblin( std::string const name ) : Victim(name) {

	std::cout << "Goblining mightily" << std::endl;
}

MightyGoblin::MightyGoblin( __attribute__((unused))const MightyGoblin & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MightyGoblin::~MightyGoblin()
{
	std::cout << "Shlearkkk..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, MightyGoblin const & i )
{
	o << i.introduce();
	return o;
}

MightyGoblin &			MightyGoblin::operator=( MightyGoblin const & rhs )
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
