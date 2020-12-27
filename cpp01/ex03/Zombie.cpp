#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie()	{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout.width(10);
	std::cout << std::left << this->_name;
	std::cout << " is dead, dead for good this time!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Zombie::announce( void ) const	{
	std::cout << "<" ;
	std::cout.width(10);
	std::cout << std::left << this->_name << " (";
	std::cout.width(13);
	std::cout << std::left << this->_type << ")> ";
	std::cout << "Brrrraaainns (with some Broccoli on the side please)..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Zombie::setType(std::string type)	{
	this->_type = type;
}

void	Zombie::setName(std::string name)	{
	this->_name = name;
}

/* ************************************************************************** */
