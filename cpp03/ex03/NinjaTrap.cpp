#include "NinjaTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

NinjaTrap::NinjaTrap( std::string const name ) : ClapTrap(name)	{

	this->_level = 1;
	this->_energyPoints = 120;
	this->_hitPoints = 60;
	this->_maxEnergyPoints = 120;
	this->_maxHitPoints = 60;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;

	std::cout << "NinjaTrap - Constructor by default Called" << std::endl;

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

NinjaTrap::NinjaTrap( std::string const name, const NinjaTrap & src )	:	ClapTrap(name)	{

	std::cout << "NinjaTrap - Constructor by copy Called" << std::endl;

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

void				NinjaTrap::takeDamage(unsigned int amount)	{

	unsigned int	energyBackup = this->_energyPoints;
	ClapTrap::takeDamage(amount);

	std::cout << this->_name << " says: \"I AM ON FIRE!!! OH GOD, PUT ME OUT!!!\" and got " << energyBackup - this->_energyPoints << " damage." << std::endl;
}

void				NinjaTrap::beRepaired(unsigned int amount)	{

	ClapTrap::beRepaired(amount);

	std::cout << this->_name  << " found " << amount << " of mana... \"Salmon, my favorite!!!\""<< std::endl;
}

unsigned int		NinjaTrap::rangedAttack(std::string const & target)	{

	int		output = ClapTrap::rangedAttack(target);

	if (output > 0)
	{
		std::cout << "NINJ4 TR4PP --  " << this->_name << " melee attack on " << target ;
		std::cout << " causing " << this->_rangedAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "NINJ4 TR4PP --  " << this->_name << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		NinjaTrap::meleeAttack(std::string const & target)	{

	int		output = ClapTrap::meleeAttack(target);

	if (output > 0)
	{
		std::cout << "NINJ4 TR4PP --  " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << this->_meleeAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "NINJ4 TR4PP --  " << this->_name << " hit points are too low for a Melee Attack" << std::endl;
	return (0);
}

void				NinjaTrap::ninjaShoeBox(FragTrap &clapTrap)	{
	std::cout << "Ninja Special Attack !!!" << clapTrap << ", you better run for your life poor FragTrap !!!!!!!!" << std::endl;
}

void				NinjaTrap::ninjaShoeBox(ScavTrap &clapTrap)	{
	std::cout << "Ninja Special Attack !!!" << clapTrap << ", you better run for your life poor ScavTrap !!!!!!!!" << std::endl;
}

void				NinjaTrap::ninjaShoeBox(NinjaTrap &clapTrap)	{
	std::cout << "Ninja Special Attack !!!" << clapTrap << ", you better run for your life poor NinjaTrap !!!!!!!!" << std::endl;
}

/* ************************************************************************** */
