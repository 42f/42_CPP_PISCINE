#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <iostream>
# include <string>

class Character
{

	public:

		Character( std::string const & name );

		void 				recoverAP( void );
		void 				equip(AWeapon*);
		void 				attack(Enemy*);
		std::string const	getName( void ) const;
		int					getAP( void ) const ;
		void				setAP( int amount ) ;
		AWeapon *			getCurrentWeapon( void ) const ;
		~Character();


	private:
		Character &		operator=( Character const & rhs );
		Character( Character const & src );

		std::string const		_name;
		int						_ap;
		AWeapon *				_currentWeapon;

};

std::ostream &		operator<<(std::ostream & o, Character const & i);

#endif /* ******************************************************* CHARACTER_H */
