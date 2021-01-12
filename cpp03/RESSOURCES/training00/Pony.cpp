#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Pony::Pony()
{
	std::cout << "Constructor CALLED" << std::endl;
}

// Pony::Pony( const Pony & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Pony::~Pony()
{
	std::cout << "destuctor	 CALLED" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Pony &				Pony::operator=( Pony const & rhs )
// {
// 	// if ( this != &rhs )
// 	// {
// 	// 	this->_value = rhs.getValue();
// 	// }
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Pony const & i )
// {
// 	o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
