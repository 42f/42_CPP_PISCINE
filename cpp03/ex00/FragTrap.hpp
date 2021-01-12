#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap
{

	public:

		FragTrap( std::string const name );
		FragTrap( std::string const name, FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		unsigned int	vaulthunter_dot_exe(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		std::string	 const	_name;
		unsigned int		_level;
		unsigned int		_energyPoints;
		unsigned int		_hitPoints;

		unsigned int const	_maxEnergyPoints;
		unsigned int const	_maxHitPoints;
		unsigned int const	_meleeAttackDamage;
		unsigned int const	_rangedAttackDamage;
		unsigned int const	_armorDamageReduction;

};

#endif /* ******************************************************** FRAGTRAP_H */
