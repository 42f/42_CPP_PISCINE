# include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// AMateria::AMateria()
// {
// }

AMateria::AMateria(std::string const & type) : _xp(0), _type(type)
{
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
AMateria::AMateria( const AMateria & src )
{
}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
		this->_xp = rhs.getXP();
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			AMateria::use(__attribute__((unused))ICharacter& target) { this->_xp += 10; };

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & 	AMateria::getType() const	{ return (this->_type); }
unsigned int 			AMateria::getXP() const		{ return (this->_xp); }

/* ************************************************************************** */
