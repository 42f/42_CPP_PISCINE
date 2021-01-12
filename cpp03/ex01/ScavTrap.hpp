#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{

	public:

		ScavTrap( std::string const name );
		ScavTrap( std::string const name, ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		unsigned int	challengeNewcomer(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		std::string	 const	_name;
		unsigned int		_level;
		unsigned int		_energyPoints;
		unsigned int		_hitPoints;

		unsigned int 		_maxEnergyPoints;
		unsigned int 		_maxHitPoints;
		unsigned int 		_meleeAttackDamage;
		unsigned int 		_rangedAttackDamage;
		unsigned int 		_armorDamageReduction;

};

#endif /* ******************************************************** ScavTrap_H */
