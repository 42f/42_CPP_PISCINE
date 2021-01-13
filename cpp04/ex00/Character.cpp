#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
}

Character::Character( std::string const name) : _name(name)	{
}

Character::Character( __attribute__((unused))const Character & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if (this != &rhs)
		this->_name = rhs._name;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	(void)i;
	// o << i.introduce();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Character::getName( void ) const		{ return (this->_name); }
void			Character::setName( std::string const &name ) 	{ this->_name = name; }

/* ************************************************************************** */
