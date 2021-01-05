#include "Sample.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Sample::Sample()
{
	// this->_x++;
	this->_n = 0;
	std::cout << "CONSTRUCT by default" << std::endl;
	return ;
}

Sample::Sample( int const n) : _n(n)
{
	std::cout << "CONSTRUCT by param: " << n << std::endl;
	return ;
}

Sample::Sample( const Sample & src )
{
	std::cout << "CONSTRUCT by copy: " << src._n << std::endl;
	*this = src;

	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Sample::~Sample()
{
	std::cout << "DESTRUCTOR for " << this->getValue() << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Sample &				Sample::operator=( Sample const & rhs )
{
	this->_n = rhs.getValue();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Sample const & i )
{
	o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int						Sample::getValue( void ) const	{
	return (this->_n);
}

/* ************************************************************************** */
