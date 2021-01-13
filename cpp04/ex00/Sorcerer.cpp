#include "Sorcerer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer( std::string const name, std::string const title ) : Character(name), _title(title)	{

	std::cout << name << ", " << title << " is born!" << std::endl;
}

Sorcerer::Sorcerer( __attribute__((unused))const Sorcerer & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Sorcerer::~Sorcerer()
{
	std::cout << Character::getName() << ", " << this->getTitle() << " is dead. Consequences will never be the same!" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Sorcerer &				Sorcerer::operator=( Sorcerer const & rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Sorcerer const & i )
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

std::string		Sorcerer::introduce( void ) const	{

	std::stringstream	intro;

	intro << "I am " << Character::getName() << ", " << this->getTitle() << " and I like ponies." << std::endl;
	return (intro.str());
}

std::string		Sorcerer::getTitle( void ) const 	{

	return (this->_title);
}

void			Sorcerer::sayHello( void ) const 	{

	std::cout << this->introduce();
}

void			Sorcerer::polymorph( Victim const &target )	const {

	target.getPolymorphed();
}

/* ************************************************************************** */
