#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap( std::string const name );
		ScavTrap( std::string const name, ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);

		unsigned int	challengeNewcomer(std::string const & target);

};

#endif /* ******************************************************** ScavTrap_H */
