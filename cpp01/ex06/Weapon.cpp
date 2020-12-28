#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::Weapon(Weapon const &old_obj)
{
	_type = old_obj._type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const	&Weapon::getType( void ) const {
	return (this->_type);
}

void				Weapon::setType( std::string const type )	{
	this->_type = type;
}

/* ************************************************************************** */
