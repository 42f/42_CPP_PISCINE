# include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
Ice::Ice( const Ice & src )
{
}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*
** --------------------------------- METHODS ----------------------------------
*/

Ice*	 	Ice::clone() const {

	return (new Ice);
}

void			Ice::use(ICharacter& target) {

	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
