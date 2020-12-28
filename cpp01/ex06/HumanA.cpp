#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string const name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanA::attack( void ) const	{
	std::cout << std::uppercase;
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << std::uppercase;
	std::cout << this->_weapon.getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
