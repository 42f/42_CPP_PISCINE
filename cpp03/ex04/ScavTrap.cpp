#include "ScavTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(name)	{

	this->setLevel(1);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	this->setMaxEnergyPoints(50);
	this->setMaxHitPoints(100);
	this->setMeleeAttackDamage(20);
	this->setRangedAttackDamage(15);
	this->setArmorDamageReduction(3);

	std::cout << "SCAVTRAP - Constructor by default Called" << std::endl;

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

ScavTrap::ScavTrap( std::string const name, const ScavTrap & src )	:	ClapTrap(name)	{

	std::cout << "SCAVTRAP - Constructor by copy Called" << std::endl;

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

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP - Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

unsigned int		ScavTrap::rangedAttack(std::string const & target)	{

	int		output = ClapTrap::rangedAttack(target);

	if (output > 0)
	{
		std::cout << "#Sc4v TR4PP --  " << this->getName() << " melee attack on " << target ;
		std::cout << " causing " << this->getRangedAttackDamage() << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "#Sc4v TR4PP --  " << this->getName() << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		ScavTrap::meleeAttack(std::string const & target)	{

	int		output = ClapTrap::meleeAttack(target);

	if (output > 0)
	{
		std::cout << "#Sc4v TR4PP --  " << this->getName() << " attacks  " << target ;
		std::cout << " at range, causing " << this->getMeleeAttackDamage() << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "#Sc4v TR4PP --  " << this->getName() << " hit points are too low for a Melee Attack" << std::endl;
	return (0);
}

unsigned int		ScavTrap::challengeNewcomer(std::string const & target)	{

	std::string		attackList[] = { "You versus me! Me versus you! Either way!", "Dance battle! Or, you know... regular battle.",
									"Man versus machine! Very tiny streamlined machine!",
									"5G-Vaccine-Nano-Particules fight for brain control by Bill Gates",
									"Pony vs. Machine" };
	size_t			nbOfAttacks = sizeof(attackList) / sizeof(std::string);
	struct timeval	tv;
	int				damage;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	std::cout << this->getName() << " sends \"" << attackList[rand() % nbOfAttacks] << "\" challenge to " << target << std::endl;
	damage = (rand() % 25);
	return (damage > 10 ? damage : 10);
}

/* ************************************************************************** */
