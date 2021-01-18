#include "NinjaTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

NinjaTrap::NinjaTrap( std::string const name ) : ClapTrap(name)	{

	this->setLevel(4242);
	this->setEnergyPoints(4242);
	this->setHitPoints(4242);
	this->setMaxEnergyPoints(4242);
	this->setMaxHitPoints(4242);
	this->setMeleeAttackDamage(4242);
	this->setRangedAttackDamage(4242);
	this->setArmorDamageReduction(4242);

	// this->_level = 1;
	// this->_energyPoints = 120;
	// this->_hitPoints = 60;
	// this->_maxEnergyPoints = 120;
	// this->_maxHitPoints = 60;
	// this->_meleeAttackDamage = 60;
	// this->_rangedAttackDamage = 5;
	// this->_armorDamageReduction = 0;

	std::cout << "NinjaTrap - Constructor by default Called" << std::endl;

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

NinjaTrap::NinjaTrap( std::string const name, const NinjaTrap & src )	:	ClapTrap(name)	{

	std::cout << "NinjaTrap - Constructor by copy Called" << std::endl;

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

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap - Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

NinjaTrap &				NinjaTrap::operator=( NinjaTrap const & rhs )
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

unsigned int		NinjaTrap::rangedAttack(std::string const & target)	{

	int		output = ClapTrap::rangedAttack(target);

	if (output > 0)
	{
		std::cout << "NINJ4 TR4PP --  " << this->getName() << " melee attack on " << target ;
		std::cout << " causing " << this->getRangedAttackDamage() << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "NINJ4 TR4PP --  " << this->getName() << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		NinjaTrap::meleeAttack(std::string const & target)	{

	int		output = ClapTrap::meleeAttack(target);

	if (output > 0)
	{
		std::cout << "NINJ4 TR4PP --  " << this->getName() << " attacks  " << target ;
		std::cout << " at range, causing " << this->getMeleeAttackDamage() << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "NINJ4 TR4PP --  " << this->getName() << " hit points are too low for a Melee Attack" << std::endl;
	return (0);
}

void				NinjaTrap::ninjaShoeBox(FragTrap &clapTrap)	{
	std::cout << this->getName() <<" unleashes the UNICORN HORDE !!!" << clapTrap << ", you better run for your life poor FragTrap !!!!!!!! " << std::endl;
}

void				NinjaTrap::ninjaShoeBox(ScavTrap &clapTrap)	{
	std::cout << this->getName() <<" opens the enraged PONIES' CAGE !!!" << clapTrap << ", you better run for your life poor ScavTrap !!!!!!!! " << std::endl;
}

void				NinjaTrap::ninjaShoeBox(NinjaTrap &clapTrap)	{
	std::cout << this->getName() <<" sends a buttload of 5G nanoparticules from COVID vaccin TO YOUR FACE to control your small useless brain from Bill Gate's office !!! " << clapTrap << ", you better run for your life poor NinjaTrap !!!!!!!!" << std::endl;
}

/* ************************************************************************** */
