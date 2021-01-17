# include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
Cure::Cure( const Cure & src )
{
}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
Cure &				Cure::operator=( Cure const & rhs )
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

Cure*	 		Cure::clone() const {

	return (new Cure);
}

void			Cure::use(ICharacter& target) {

	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */
