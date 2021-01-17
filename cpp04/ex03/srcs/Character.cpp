# include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character( std::string name ) : _name(name)	{

	for (size_t i = 0; i < Character::_inventorySize; i++)
		this->_inventory[i] = NULL;
}

/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

Character::Character( const Character & src )
{
	*this = src;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (size_t i = 0; i < Character::_inventorySize; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		for (size_t i = 0; i < Character::_inventorySize; i++)
		{
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


std::string const & 	Character::getName() const	{

	return (this->_name);
}

void 					Character::equip(AMateria* m)	{

	if (m == NULL)
		return;

	for (size_t i = 0; i < Character::_inventorySize; i++)
	{
		if (this->_inventory[i] == m)
			break ;
		if (this->_inventory[i] == NULL)	{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void 					Character::unequip(int idx)	{

	if (idx >= 0 && (size_t)idx < Character::_inventorySize && this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}

void 					Character::use(int idx, ICharacter& target) 	{

	if (idx >= 0 && (size_t)idx < Character::_inventorySize && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */
