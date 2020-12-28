#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{

	public:

		void	attack( void ) const;
		void	setWeapon(Weapon &weapon);
		HumanB(std::string const name) ;
		~HumanB();


	private:

		std::string		_name;
		Weapon			*_weapon;
};


#endif /* ********************************************************** HUMANB_H */
