#include "Integer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Integer::Integer( int const n) : _n(n)
{
	std::cout << "Construction called with " << n << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Integer::~Integer()
{
	std::cout << "Destructor called with " << this->_n << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Integer &				Integer::operator=( Integer const & rhs )
{
	std::cout << "Assignation called from " << this->_n << std::endl;
	std::cout << "to: " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();
	return *this;
}

Integer 				Integer::operator+( Integer const & rhs ) const
{
	std::cout << "Addition called with " << this->_n << std::endl;
	std::cout << "and: " << rhs.getValue() << std::endl;

	return Integer(this->_n + rhs.getValue());
}

std::ostream &			operator<<( std::ostream & o, Integer const & i )
{
	std::cout << "<< operator called for " << std::endl;

	o << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int						Integer::getValue( void ) const
{
	return (this->_n);
}

/* ************************************************************************** */
