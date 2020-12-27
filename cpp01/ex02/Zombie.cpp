#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie(std::string const name) : _name(name){
	this->_type = "basic_dead_dude";
	std::cout << this->_name << " is born (well... dead, it's a zombie)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead, dead for good this time!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Zombie::announce( void ) const	{
	std::cout 	<< "<" << this->_name << " (" << this->_type << ")> "
				<< "Brrrraaainns (with some Broccoli on the side please)..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Zombie::setType(std::string type)	{
	this->_type = type;
}

/* ************************************************************************** */
