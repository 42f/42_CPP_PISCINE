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

		int 				_level;
		int 				_energyPoints;
		int					_hitPoints;

		std::string	const	_name;

		static int const	_maxEnergyPoints;
		static int const	_maxHitPoints;
		static int const	_meleeAttackDamage;
		static int const	_rangedAttackDamage;
		static int const	_armorDamageReduction;

};

#endif /* ******************************************************** FRAGTRAP_H */
