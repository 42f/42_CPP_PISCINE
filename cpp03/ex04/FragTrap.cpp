#include "FragTrap.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap( std::string const name ) : ClapTrap(name)	{

	ClapTrap::_level = 1;
	ClapTrap::_energyPoints = 100;
	ClapTrap::_hitPoints = 10;
	ClapTrap::_maxEnergyPoints = 100;
	ClapTrap::_maxHitPoints = 100;
	ClapTrap::_meleeAttackDamage = 30;
	ClapTrap::_rangedAttackDamage = 20;
	ClapTrap::_armorDamageReduction = 5;

	std::cout << "FRAGTRAP - Constructor by default Called" << std::endl;

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

FragTrap::FragTrap( std::string const name, const FragTrap & src )	:	ClapTrap(name)	{

	std::cout << "FRAGTRAP - Constructor by copy Called" << std::endl;

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
	std::cout << "FRAGTRAP - Destructor Called" << std::endl;
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

void				FragTrap::takeDamage(unsigned int amount)	{

	unsigned int	energyBackup = this->_energyPoints;
	ClapTrap::takeDamage(amount);

	std::cout << this->_name << " says: \"Outch ! Metal gears... frozen solid!\" and got " << energyBackup - this->_energyPoints << " damage." << std::endl;
}

void				FragTrap::beRepaired(unsigned int amount)	{

	ClapTrap::beRepaired(amount);

	std::cout << this->_name  << " found " << amount << " of mana... \"Health! Eww, what flavor is red?\""<< std::endl;
}

unsigned int		FragTrap::rangedAttack(std::string const & target)	{

	int		output = ClapTrap::rangedAttack(target);

	if (output > 0)
	{
		std::cout << "FR4G TR4p --  " << this->_name << " melee attack on " << target ;
		std::cout << " causing " << this->_rangedAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "FR4G TR4p --  " << this->_name << " hit points are too low for a Ranged Attack" << std::endl;
	return (0);
}

unsigned int		FragTrap::meleeAttack(std::string const & target)	{

	int		output = ClapTrap::meleeAttack(target);

	if (output > 0)
	{
		std::cout << "FR4G TR4p --  " << this->_name << " attacks  " << target ;
		std::cout << " at range, causing " << this->_meleeAttackDamage << " poins of damage!" << std::endl;
		return (output);
	}
	else
		std::cout << "FR4G TR4p --  " << this->_name << " hit points are too low for a Melee Attack" << std::endl;
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
