#include "ScavTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap( std::string const name ) : _name(name)	{

	this->_level = 1;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_maxEnergyPoints = 50;
	this->_maxHitPoints = 100;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;

	std::cout << "SCAVTRAP Constructor by default Called" << std::endl;

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

ScavTrap::ScavTrap( std::string const name, const ScavTrap & src )	:	_name(name)	{

	std::cout << "SCAVTRAP Constructor by copy Called" << std::endl;

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
	std::cout << "Destructor Called" << std::endl;
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

void				ScavTrap::takeDamage(unsigned int amount)	{

	int		energyBackUp = this->_energyPoints;

	if (amount > this->_armorDamageReduction)
		amount -= this->_armorDamageReduction;
	else
		amount = 0;

	if (this->_energyPoints - amount >= 0)
		this->_energyPoints -= amount;
	else
		this->_energyPoints = 0;

	std::cout << this->_name << " says: \"Outch ! Metal gears... frozen solid!\" and got " << energyBackUp - this->_energyPoints << " damage." << std::endl;
}

void				ScavTrap::beRepaired(unsigned int amount)	{
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

unsigned int		ScavTrap::rangedAttack(std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		std::cout << "SCAVTR4P " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << this->_rangedAttackDamage << " poins of damage!" << std::endl;
		return (this->_rangedAttackDamage);
	}
	else
		std::cout << "SCAVTR4P " << this->_name << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		ScavTrap::meleeAttack(std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		std::cout << "SCAVTR4P " << this->_name << " melee attack on " << target ;
		std::cout << " causing " << this->_meleeAttackDamage << " poins of damage!" << std::endl;
		return (this->_meleeAttackDamage);
	}
	else
		std::cout << "SCAVTR4P " << this->_name << " hit points are too low for a Melee Attack" << std::endl;
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
