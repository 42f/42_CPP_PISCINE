#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>
# include <string>

class SuperTrap : public FragTrap, public NinjaTrap
{

	public:

		SuperTrap( std::string const name );
		SuperTrap( std::string const name, SuperTrap const & src );
		~SuperTrap();

		SuperTrap &		operator=( SuperTrap const & rhs );

		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
};

#endif /* ******************************************************** SuperTrap_H */
