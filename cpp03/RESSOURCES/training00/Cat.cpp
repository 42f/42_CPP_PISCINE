#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Constructor CALLED" << std::endl;
}

// Cat::Cat( const Cat & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "destuctor	 CALLED" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Cat &				Cat::operator=( Cat const & rhs )
// {
// 	// if ( this != &rhs )
// 	// {
// 	// 	this->_value = rhs.getValue();
// 	// }
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Cat const & i )
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
