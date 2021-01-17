#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character( std::string const & name ) : _name(name), _ap(40), _currentWeapon(NULL)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &		operator<<(std::ostream & o, Character const & i)
{
	o << i.getName() << " has ";
	o << i.getAP() << " AP ";
	if (i.getCurrentWeapon() != NULL)
		o << "and wields a " << i.getCurrentWeapon()->getName() << std::endl;
	else
		o << "and is unarmed" << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


void 				Character::recoverAP( void )	{
	if (this->_ap + Character::APCost > Character::APMax)
		this->_ap = Character::APMax;
	else
		this->_ap += Character::APCost;
};

void 				Character::equip(AWeapon* weapon)	{
	this->_currentWeapon = weapon;
};

void 				Character::attack(Enemy* enemy)	{

	int		apAfterAttack;

	if (enemy != NULL && this->getCurrentWeapon() != NULL)
	{
		apAfterAttack = this->getAP() - this->getCurrentWeapon()->getAPCost();
		if (apAfterAttack < 0)
			return ;
		this->setAP(apAfterAttack);
		std::cout << this->_name << " attacks ";
		std::cout << enemy->getType() << " with a ";
		std::cout << this->_currentWeapon->getName() << std::endl;
		this->_currentWeapon->attack();
		enemy->takeDamage(this->_currentWeapon->getDamage());
		if (enemy->getHP() == 0)
			delete enemy;
	}
};

std::string const	Character::getName( void ) const			{ return (this->_name); };
int					Character::getAP( void ) const 				{ return (this->_ap); };
void				Character::setAP( int amount ) 	 			{ this->_ap = amount; };
AWeapon *			Character::getCurrentWeapon( void ) const 	{ return (this->_currentWeapon); };

/* ************************************************************************** */
