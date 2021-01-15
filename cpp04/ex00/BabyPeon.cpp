#include "BabyPeon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BabyPeon::BabyPeon()
{
}

BabyPeon::BabyPeon( std::string const name ) : Peon(name) {
}

BabyPeon::BabyPeon( __attribute__((unused))const BabyPeon & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BabyPeon::~BabyPeon()
{
	this->beDead();
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, BabyPeon const & i )
{
	o << i.introduce();
	return o;
}

BabyPeon &					BabyPeon::operator=( BabyPeon const & rhs )
{
	if (this != &rhs)
		Victim::_name = rhs._name;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			BabyPeon::beDead( void )	const {

	std::cout << "HAAAAAAAAAAAAAAAAAAAAA Bleuark..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
