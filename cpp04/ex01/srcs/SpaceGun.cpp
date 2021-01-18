#include "SpaceGun.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

SpaceGun::SpaceGun() : AWeapon("SpaceGun", 10, 42)
{
}

// SpaceGun::SpaceGun( const SpaceGun & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

SpaceGun::~SpaceGun()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

SpaceGun &				SpaceGun::operator=( __attribute__((unused))SpaceGun const & rhs )
{
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, SpaceGun const & i )
// {
// 	// o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void		SpaceGun::attack( void ) const	{
	std::cout << "* BAM BAM! -42 in ya face!  *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
