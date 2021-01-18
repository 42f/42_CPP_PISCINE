#include "ClapTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap( std::string const name ) : _name(name)	{

	this->setLevel(0);
	this->setEnergyPoints(0);
	this->setHitPoints(0);
	this->setMaxEnergyPoints(0);
	this->setMaxHitPoints(0);
	this->setMeleeAttackDamage(0);
	this->setRangedAttackDamage(0);
	this->setArmorDamageReduction(0);

	std::cout << "CLAPTRAP - Constructor by default Called" << std::endl;

	std::cout << " _name " << this->_name << std::endl;
	std::cout << " _level " << this->_level << std::endl;
	std::cout << " _energyPoints " << this->_energyPoints << std::endl;
	std::cout << " _hitPoints " << this->_hitPoints << std::endl;
	std::cout << " _maxEnergyPoints " << this->_maxEnergyPoints << std::endl;
	std::cout << " _maxHitPoints " << this->_maxHitPoints << std::endl;
	std::cout << " _meleeAttackDamage " << this->_meleeAttackDamage << std::endl;
	std::cout << " _rangedAttackDamage " << this->_rangedAttackDamage << std::endl;
	std::cout << " _armorDamageReduction " << this->_armorDamageReduction << std::endl;
}

ClapTrap::ClapTrap( std::string const name, const ClapTrap & src )	:	_name(name)	{

	std::cout << "CLAPTRAP - Constructor by copy Called" << std::endl;

	*this = src;

	std::cout << " _name " << this->_name << std::endl;
	std::cout << " _level " << this->_level << std::endl;
	std::cout << " _energyPoints " << this->_energyPoints << std::endl;
	std::cout << " _hitPoints " << this->_hitPoints << std::endl;
	std::cout << " _maxEnergyPoints " << this->_maxEnergyPoints << std::endl;
	std::cout << " _maxHitPoints " << this->_maxHitPoints << std::endl;
	std::cout << " _meleeAttackDamage " << this->_meleeAttackDamage << std::endl;
	std::cout << " _rangedAttackDamage " << this->_rangedAttackDamage << std::endl;
	std::cout << " _armorDamageReduction " << this->_armorDamageReduction << std::endl;

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "CLAPTRAP - Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_level = rhs._level;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_maxEnergyPoints = rhs._maxEnergyPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
		this->_meleeAttackDamage = rhs._meleeAttackDamage;
		this->_rangedAttackDamage = rhs._rangedAttackDamage;
		this->_armorDamageReduction = rhs._armorDamageReduction;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void				ClapTrap::takeDamage(unsigned int amount)	{

 	unsigned int	energyBackup = this->_energyPoints;
	if (amount > this->_armorDamageReduction)
		amount -= this->_armorDamageReduction;
	else
		amount = 0;

	if (this->_energyPoints - amount >= 0)
		this->_energyPoints -= amount;
	else
		this->_energyPoints = 0;
 	std::cout << this->_name << " says: \"My robotic flesh! AAAAAAAAAAAAAHH!\" and got " << energyBackup - this->_energyPoints << " damage." << std::endl;
}

void				ClapTrap::beRepaired(unsigned int amount)	{
	if (this->_energyPoints + amount < this->_maxEnergyPoints)
		this->_energyPoints += amount;
	else
		this->_energyPoints = this->_maxEnergyPoints;

	if (this->_hitPoints + amount < this->_maxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = this->_maxHitPoints;
 	std::cout << this->_name  << " found " << amount << " of mana... \"Health! Eww, what flavor is red?\""<< std::endl;
}

unsigned int		ClapTrap::rangedAttack(__attribute__((unused))std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		return (this->_rangedAttackDamage);
	}
	return (0);
}

unsigned int		ClapTrap::meleeAttack(__attribute__((unused))std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		return (this->_meleeAttackDamage);
	}
	return (0);
}

std::string const	ClapTrap::getName( void ) const	{
	return (this->_name);
}


void				ClapTrap::setLevel( unsigned int value )				{	this->_level = value; }
void				ClapTrap::setEnergyPoints( unsigned int value )			{	this->_energyPoints = value; }
void				ClapTrap::setHitPoints( unsigned int value )			{	this->_hitPoints = value; }
void		 		ClapTrap::setMaxEnergyPoints( unsigned int value )		{	this->_maxEnergyPoints = value; }
void		 		ClapTrap::setMaxHitPoints( unsigned int value )			{	this->_maxHitPoints = value; }
void		 		ClapTrap::setMeleeAttackDamage( unsigned int value )	{	this->_meleeAttackDamage = value; }
void		 		ClapTrap::setRangedAttackDamage( unsigned int value )	{	this->_rangedAttackDamage = value; }
void		 		ClapTrap::setArmorDamageReduction( unsigned int value )	{	this->_armorDamageReduction = value; }

unsigned int		ClapTrap::getLevel( void ) const 				{ return (this->_level);	}
unsigned int		ClapTrap::getEnergyPoints( void ) const 			{ return (this->_energyPoints);	}
unsigned int		ClapTrap::getHitPoints( void ) const 				{ return (this->_hitPoints);	}
unsigned int 		ClapTrap::getMaxEnergyPoints( void ) const 			{ return (this->_maxEnergyPoints);	}
unsigned int 		ClapTrap::getMaxHitPoints( void ) const 			{ return (this->_maxHitPoints);	}
unsigned int 		ClapTrap::getMeleeAttackDamage( void ) const 		{ return (this->_meleeAttackDamage);	}
unsigned int 		ClapTrap::getRangedAttackDamage( void ) const 		{ return (this->_rangedAttackDamage);	}
unsigned int 		ClapTrap::getArmorDamageReduction( void ) const 	{ return (this->_armorDamageReduction);	}


std::ostream &		operator<<( std::ostream & o, ClapTrap const & i)	{
	o << i.getName().c_str();
	return (o);
}
/* ************************************************************************** */
