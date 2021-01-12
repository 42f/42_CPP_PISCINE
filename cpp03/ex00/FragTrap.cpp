#include "FragTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap( std::string const name ) :	_name(name),
												_level( 1),
												_energyPoints( 100),
												_hitPoints( 10),
												_maxEnergyPoints( 100),
												_maxHitPoints( 100),
												_meleeAttackDamage( 30),
												_rangedAttackDamage( 20),
												_armorDamageReduction( 5)	{

	std::cout << "Constructor by default Called" << std::endl;

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

FragTrap::FragTrap( std::string const name, const FragTrap & src )	:	_name(name),
																		_level( 1),
																		_energyPoints( 100),
																		_hitPoints( 10),
																		_maxEnergyPoints( 100),
																		_maxHitPoints( 100),
																		_meleeAttackDamage( 30),
																		_rangedAttackDamage( 20),
																		_armorDamageReduction( 5)	{
	std::cout << "Constructor by copy Called" << std::endl;

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

FragTrap::~FragTrap()
{
	std::cout << "Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_level = rhs._level;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void				FragTrap::takeDamage(unsigned int amount)	{

	int		energyBackUp = this->_energyPoints;

	if (amount > this->_armorDamageReduction)
		amount -= this->_armorDamageReduction;
	else
		amount = 0;

	if (this->_energyPoints - amount >= 0)
		this->_energyPoints -= amount;
	else
		this->_energyPoints = 0;

	std::cout << this->_name << " says: \"My robotic flesh! AAAAAAAAAAAAAHH!\" and got " << energyBackUp - this->_energyPoints << " damage." << std::endl;
}

void				FragTrap::beRepaired(unsigned int amount)	{
	if (this->_energyPoints + amount < this->_maxEnergyPoints)
		this->_energyPoints += amount;
	else
		this->_energyPoints = this->_maxEnergyPoints;

	if (this->_hitPoints + amount < this->_maxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = this->_maxHitPoints;

	std::cout << this->_name  << " found " << amount << " of mana... \"Sweet life juice!\""<< std::endl;
}

unsigned int		FragTrap::rangedAttack(std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		std::cout << "FR4G-T " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << this->_rangedAttackDamage << " poins of damage!" << std::endl;
		return (this->_rangedAttackDamage);
	}
	else
		std::cout << "FR4G-T" << this->_name << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		FragTrap::meleeAttack(std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		std::cout << "FR4G-T " << this->_name << " melee attack on " << target ;
		std::cout << " causing " << this->_meleeAttackDamage << " poins of damage!" << std::endl;
		return (this->_meleeAttackDamage);
	}
	else
		std::cout << "FR4G-T" << this->_name << " hit points are too low for a Melee Attack" << std::endl;
	return (0);
}

unsigned int		FragTrap::vaulthunter_dot_exe(std::string const & target)	{

	std::string		attackList[] = { "Clap-in-the-Box", "Laser Inferno", "Pony horde unleached", "5G-Vaccine-Nano-Particules", "FINISH HIM!" };
	size_t			nbOfAttacks = sizeof(attackList) / sizeof(std::string);
	struct timeval	tv;
	int				damage;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	std::cout << this->_name << " launch " << attackList[rand() % nbOfAttacks] << " attack on " << target << std::endl;
	damage = (rand() % 25);
	return (damage > 10 ? damage : 10);
}

/* ************************************************************************** */
