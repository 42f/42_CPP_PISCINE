#include "Human.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Human::Human()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Human::~Human()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain		&Human::getBrain( void )	{
	return (this->_humanBrain);
}

std::string		Human::identify( void )	{
	std::string				ret;
	std::stringstream		sstr;

	sstr << std::setbase(16);
	sstr << &(this->_humanBrain);
	ret = sstr.str();
	return (ret);
}
/* ************************************************************************** */
