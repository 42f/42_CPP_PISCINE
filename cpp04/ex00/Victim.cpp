#include "Victim.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Victim::Victim()
{
}

Victim::Victim( std::string const name ) : Character(name)	{

	std::cout << "Some random victim called " << this->getName() << " just appeared!" << std::endl;
}

Victim::Victim( __attribute__((unused))const Victim & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Victim::~Victim()
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Victim &				Victim::operator=( Victim const & rhs )
{
	if (this != &rhs)
		Character::_name = rhs._name;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Victim const & i )
{
	o << i.introduce();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Victim::introduce( void ) const	{

	std::stringstream	intro;

	intro << "I'm " << Character::getName() << " and I like otters!";
	return (intro.str());
}

void			Victim::sayHello( void ) const 	{ std::cout << this->introduce() << std::endl; }


/* ************************************************************************** */
