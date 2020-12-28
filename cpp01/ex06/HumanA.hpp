#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{

	public:

		void	attack( void ) const;

		HumanA(std::string const name, Weapon &weapon);
		~HumanA();

	private:
		std::string	const	_name;
		Weapon const		&_weapon;
};

#endif /* ********************************************************** HUMANA_H */
