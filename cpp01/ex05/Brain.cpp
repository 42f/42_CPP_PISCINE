#include "Brain.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// Brain::Brain() : _brainType("smart"), _brainAlive(true)	{
Brain::Brain() {
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
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
std::string		Brain::identify( void )	{
	std::string				ret;
	std::stringstream		sstr;

	sstr << std::setbase(16);
	sstr << this;
	ret = sstr.str();
	return (ret);
}

/* ************************************************************************** */
