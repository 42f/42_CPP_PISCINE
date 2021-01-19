#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>
# include <string>

class NinjaTrap : virtual public ClapTrap
{

	public:

		NinjaTrap( std::string const name );
		NinjaTrap( std::string const name, NinjaTrap const & src );
		~NinjaTrap();

		NinjaTrap &		operator=( NinjaTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);

		void			ninjaShoeBox(FragTrap &clapTrap);
		void			ninjaShoeBox(ScavTrap &clapTrap);
		void			ninjaShoeBox(NinjaTrap &clapTrap);

	protected:
		unsigned int		_level;
		unsigned int		_energyPoints;
		unsigned int		_hitPoints;
		unsigned int 		_maxEnergyPoints;
		unsigned int 		_maxHitPoints;
		unsigned int 		_meleeAttackDamage;
		unsigned int 		_rangedAttackDamage;
		unsigned int 		_armorDamageReduction;
};

#endif /* ******************************************************** NinjaTrap_H */
