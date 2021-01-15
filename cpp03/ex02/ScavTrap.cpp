#include "ScavTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(name)	{

	this->_level = 1;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_maxEnergyPoints = 50;
	this->_maxHitPoints = 100;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;

	std::cout << "SCAVTRAP - Constructor by default Called" << std::endl;

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

ScavTrap::ScavTrap( std::string const name, const ScavTrap & src )	:	ClapTrap(name)	{

	std::cout << "SCAVTRAP - Constructor by copy Called" << std::endl;

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

unsigned int		ScavTrap::rangedAttack(std::string const & target)	{

	int		output = ClapTrap::rangedAttack(target);

	if (output > 0)
	{
		std::cout << "#Sc4v TR4PP --  " << this->_name << " melee attack on " << target ;
		std::cout << " causing " << this->_rangedAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "#Sc4v TR4PP --  " << this->_name << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		ScavTrap::meleeAttack(std::string const & target)	{

	int		output = ClapTrap::meleeAttack(target);

	if (output > 0)
	{
		std::cout << "#Sc4v TR4PP --  " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << this->_meleeAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "#Sc4v TR4PP --  " << this->_name << " hit points are too low for a Melee Attack" << std::endl;
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
	std::cout << this->_name << " sends \"" << attackList[rand() % nbOfAttacks] << "\" challenge to " << target << std::endl;
	damage = (rand() % 25);
	return (damage > 10 ? damage : 10);
}

/* ************************************************************************** */
