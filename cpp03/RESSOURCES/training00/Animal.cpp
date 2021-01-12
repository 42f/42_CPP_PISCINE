#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Constructor CALLED" << std::endl;
}

// Animal::Animal( const Animal & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "destuctor	 CALLED" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Animal &				Animal::operator=( Animal const & rhs )
// {
// 	// if ( this != &rhs )
// 	// {
// 	// 	this->_value = rhs.getValue();
// 	// }
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Animal const & i )
// {
// 	o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void 	Animal::call(std::string const callStr)	const {
	std::cout << "Says..." << callStr.c_str() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
