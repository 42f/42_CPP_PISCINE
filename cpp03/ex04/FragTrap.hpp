#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap( std::string const name );
		FragTrap( std::string const name, FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);

		unsigned int	vaulthunter_dot_exe(std::string const & target);

};

#endif /* ******************************************************** FRAGTRAP_H */
