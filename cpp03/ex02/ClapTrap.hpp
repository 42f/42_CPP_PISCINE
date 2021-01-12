#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap( std::string const name );
		ClapTrap( std::string const name, ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		unsigned int	challengeNewcomer(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);

	protected:

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

#endif /* ******************************************************** ClapTrap_H */
