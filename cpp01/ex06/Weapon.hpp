#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:

		std::string	const	&getType( void ) const ;
		void				setType( std::string const type );

		Weapon(std::string type);
		Weapon(Weapon const &old_obj);
		~Weapon();

	private:

		std::string		_type;
};


#endif /* ********************************************************** WEAPON_H */
