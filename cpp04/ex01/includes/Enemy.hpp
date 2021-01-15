#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy
{

	public:

		Enemy(int hp, std::string const & type);
		virtual ~Enemy();

		std::string const	getType( void ) const;
		int 				getHP( void ) const;
		virtual void		takeDamage(int amount);

	private:
		int					_hp;
		std::string const	_type;

		Enemy( Enemy const & src );
		Enemy &		operator=( Enemy const & rhs );
};

std::ostream &			operator<<( std::ostream & o, Enemy const & i );

#endif /* *********************************************************** ENEMY_H */
