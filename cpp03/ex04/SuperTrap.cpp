#include "SuperTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

SuperTrap::SuperTrap( std::string const name ) : ClapTrap(name), FragTrap(name), NinjaTrap(name) 	{

	this->setLevel(1);
	this->setEnergyPoints(NinjaTrap::_energyPoints);
	this->setHitPoints(FragTrap::_hitPoints);
	this->setMaxEnergyPoints(NinjaTrap::_maxEnergyPoints);
	this->setMaxHitPoints(FragTrap::_maxHitPoints);
	this->setMeleeAttackDamage(NinjaTrap::_meleeAttackDamage);
	this->setRangedAttackDamage(FragTrap::_rangedAttackDamage);
	this->setArmorDamageReduction(FragTrap::_armorDamageReduction);

	std::cout << "SuperTrap - Constructor by default Called -----------------------------" << std::endl;

	std::cout << " _name " << this->getName() << std::endl;
	std::cout << " _level " << this->getLevel() << std::endl;
	std::cout << " _energyPoints " << this->getEnergyPoints() << std::endl;
	std::cout << " _hitPoints " << this->getHitPoints() << std::endl;
	std::cout << " _maxEnergyPoints " << this->getMaxEnergyPoints() << std::endl;
	std::cout << " _maxHitPoints " << this->getMaxHitPoints() << std::endl;
	std::cout << " _meleeAttackDamage " << this->getMeleeAttackDamage() << std::endl;
	std::cout << " _rangedAttackDamage " << this->getRangedAttackDamage() << std::endl;
	std::cout << " _armorDamageReduction " << this->getArmorDamageReduction() << std::endl;

	std::cout << "*************************-- REF = ninja" << std::endl;

	std::cout << " _name " << NinjaTrap::getName() << std::endl;
	std::cout << " _level " << NinjaTrap::getLevel() << std::endl;
	std::cout << " _energyPoints " << NinjaTrap::getEnergyPoints() << std::endl;
	std::cout << " _hitPoints " << NinjaTrap::getHitPoints() << std::endl;
	std::cout << " _maxEnergyPoints " << NinjaTrap::getMaxEnergyPoints() << std::endl;
	std::cout << " _maxHitPoints " << NinjaTrap::getMaxHitPoints() << std::endl;
	std::cout << " _meleeAttackDamage " << NinjaTrap::getMeleeAttackDamage() << std::endl;
	std::cout << " _rangedAttackDamage " << NinjaTrap::getRangedAttackDamage() << std::endl;
	std::cout << " _armorDamageReduction " << NinjaTrap::getArmorDamageReduction() << std::endl;

	std::cout << "*************************-- REF = frag" << std::endl;

	std::cout << " _name " << FragTrap::getName() << std::endl;
	std::cout << " _level " << FragTrap::getLevel() << std::endl;
	std::cout << " _energyPoints " << FragTrap::getEnergyPoints() << std::endl;
	std::cout << " _hitPoints " << FragTrap::getHitPoints() << std::endl;
	std::cout << " _maxEnergyPoints " << FragTrap::getMaxEnergyPoints() << std::endl;
	std::cout << " _maxHitPoints " << FragTrap::getMaxHitPoints() << std::endl;
	std::cout << " _meleeAttackDamage " << FragTrap::getMeleeAttackDamage() << std::endl;
	std::cout << " _rangedAttackDamage " << FragTrap::getRangedAttackDamage() << std::endl;
	std::cout << " _armorDamageReduction " << FragTrap::getArmorDamageReduction() << std::endl;

	std::cout << "*************************-- base direct" << std::endl;

	std::cout << " _name " << ClapTrap::getName() << std::endl;
	std::cout << " _level " << ClapTrap::getLevel() << std::endl;
	std::cout << " _energyPoints " << ClapTrap::getEnergyPoints() << std::endl;
	std::cout << " _hitPoints " << ClapTrap::getHitPoints() << std::endl;
	std::cout << " _maxEnergyPoints " << ClapTrap::getMaxEnergyPoints() << std::endl;
	std::cout << " _maxHitPoints " << ClapTrap::getMaxHitPoints() << std::endl;
	std::cout << " _meleeAttackDamage " << ClapTrap::getMeleeAttackDamage() << std::endl;
	std::cout << " _rangedAttackDamage " << ClapTrap::getRangedAttackDamage() << std::endl;
	std::cout << " _armorDamageReduction " << ClapTrap::getArmorDamageReduction() << std::endl;
}

SuperTrap::SuperTrap( std::string const name, const SuperTrap & src )	:	ClapTrap(name), FragTrap(name), NinjaTrap(name) 	{

	std::cout << "SuperTrap - Constructor by copy Called" << std::endl;

	*this = src;

	std::cout << " _name " << this->getName() << std::endl;
	std::cout << " _level " << this->getLevel() << std::endl;
	std::cout << " _energyPoints " << this->getEnergyPoints() << std::endl;
	std::cout << " _hitPoints " << this->getHitPoints() << std::endl;
	std::cout << " _maxEnergyPoints " << this->getMaxEnergyPoints() << std::endl;
	std::cout << " _maxHitPoints " << this->getMaxHitPoints() << std::endl;
	std::cout << " _meleeAttackDamage " << this->getMeleeAttackDamage() << std::endl;
	std::cout << " _rangedAttackDamage " << this->getRangedAttackDamage() << std::endl;
	std::cout << " _armorDamageReduction " << this->getArmorDamageReduction() << std::endl;

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap - Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

SuperTrap &				SuperTrap::operator=( SuperTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->setLevel(rhs.getLevel());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setHitPoints(rhs.getHitPoints());
		this->setMaxEnergyPoints(rhs.getMaxEnergyPoints());
		this->setMaxHitPoints(rhs.getMaxHitPoints());
		this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
		this->setRangedAttackDamage(rhs.getRangedAttackDamage());
		this->setArmorDamageReduction(rhs.getArmorDamageReduction());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int		SuperTrap::rangedAttack(std::string const & target)	{

	return (FragTrap::rangedAttack(target));
}

unsigned int		SuperTrap::meleeAttack(std::string const & target)	{

	return (NinjaTrap::meleeAttack(target));
}

/* ************************************************************************** */
