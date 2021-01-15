#include "Enemy.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Enemy::~Enemy()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Enemy::takeDamage( int amount )	{
	if (this->_hp - amount < 0)
		this->_hp = 0;
	else
		this->_hp -= amount;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const	Enemy::getType( void ) const	{ return (this->_type); }
int 				Enemy::getHP( void ) const		{ return (this->_hp); }

/* ************************************************************************** */
