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
};

#endif /* ******************************************************** NinjaTrap_H */
