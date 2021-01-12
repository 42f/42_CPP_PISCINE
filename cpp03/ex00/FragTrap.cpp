#include "FragTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

int	const	FragTrap::_maxHitPoints = 100;
int	const	FragTrap::_maxEnergyPoints = 100;
int	const	FragTrap::_meleeAttackDamage = 30;
int	const	FragTrap::_rangedAttackDamage = 20;
int	const	FragTrap::_armorDamageReduction = 5;

FragTrap::FragTrap( std::string const name ) : _name(name)
{
	std::cout << "Constructor by default Called" << std::endl;
	this->_level = 1;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
}

FragTrap::FragTrap( std::string const name, const FragTrap & src ) : _name(name)
{
	std::cout << "Constructor by copy Called" << std::endl;
	*this = src;
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

	if (amount > FragTrap::_armorDamageReduction)
		amount -= FragTrap::_armorDamageReduction;
	else
		amount = 0;

	if (this->_energyPoints - amount >= 0)
		this->_energyPoints -= amount;
	else
		this->_energyPoints = 0;

	std::cout << this->_name << " says: \"My robotic flesh! AAAAAAAAAAAAAHH!\" and got " << energyBackUp - this->_energyPoints << " damage." << std::endl;
}

void				FragTrap::beRepaired(unsigned int amount)	{
	if (this->_energyPoints + amount < FragTrap::_maxEnergyPoints)
		this->_energyPoints += amount;
	else
		this->_energyPoints = FragTrap::_maxEnergyPoints;

	if (this->_hitPoints + amount < FragTrap::_maxHitPoints)
		this->_hitPoints += amount;
	else
		this->_hitPoints = FragTrap::_maxHitPoints;

	std::cout << this->_name  << " found " << amount << " of mana... \"Sweet life juice!\""<< std::endl;
}

unsigned int		FragTrap::rangedAttack(std::string const & target)	{
	if (this->_hitPoints - 15 > 0)
	{
		this->_hitPoints -= 15;
		std::cout << "FR4G-T " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << FragTrap::_rangedAttackDamage << " poins of damage!" << std::endl;
		return (FragTrap::_rangedAttackDamage);
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
		std::cout << " causing " << FragTrap::_meleeAttackDamage << " poins of damage!" << std::endl;
		return (FragTrap::_meleeAttackDamage);
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
