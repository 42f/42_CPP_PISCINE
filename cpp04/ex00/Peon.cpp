#include "Peon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Peon::Peon()
{
}

Peon::Peon( std::string const name ) : Victim(name) {

	this->>beBorn();
}

Peon::Peon( __attribute__((unused))const Peon & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Peon::~Peon()
{
	this->>beDead();
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
		Victim::_name = rhs._name;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			Peon::beDead( void )	const {

	std::cout << "Bleuark..." << std::endl;
}

void			Peon::beBorn( void )	const {

	std::cout << "Zog zog." << std::endl;
}

void			Peon::getPolymorphed( void ) const	{

	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
