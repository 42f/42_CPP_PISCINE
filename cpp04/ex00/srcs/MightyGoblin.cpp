#include "MightyGoblin.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MightyGoblin::MightyGoblin()
{
}

MightyGoblin::MightyGoblin( std::string const name ) : Victim(name) {

	this->beBorn();
}

MightyGoblin::MightyGoblin( __attribute__((unused))const MightyGoblin & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MightyGoblin::~MightyGoblin()
{
	this->beDead();
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
		Victim::_name = rhs._name;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string		MightyGoblin::introduce( void ) const	{

	std::stringstream	intro;

	intro << "Hi, grgrgeghregh imnm " << this->getName() << " Bal'a dash, malanore !!!" << std::endl;
	return (intro.str());
}

void			MightyGoblin::beDead( void )	const {

	std::cout << "Shlearkkk..." << std::endl;
}

void			MightyGoblin::beBorn( void )	const {

	std::cout << "Goblining mightily" << std::endl;
}

void			MightyGoblin::getPolymorphed( void ) const	{

	std::cout << this->getName() << " has been turned into a cute Nice Goblin!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
