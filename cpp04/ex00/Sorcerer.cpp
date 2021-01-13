#include "Sorcerer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer( std::string const name, std::string const title ) : _name(name), _title(title)	{

	std::cout << name << ", " << title << " is born!" << std::endl;
}

Sorcerer::Sorcerer( const Sorcerer & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << " is dead. Consequences will never be the same!" << std::endl;
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

	intro << "I am " << this->getName() << ", " << this->getTitle() << " and I like ponies.";
	return (intro.str());
}

std::string		Sorcerer::getName( void ) const		{ return (this->_name); }
std::string		Sorcerer::getTitle( void ) const 	{ return (this->_title); }
void			Sorcerer::sayHello( void ) const 	{ std::cout << this->introduce() << std::endl; }

/* ************************************************************************** */
