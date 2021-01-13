#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
#include <sstream>
# include <string>

class Character
{

	public:

		Character( std::string const name );
		virtual Character &		operator=( Character const & rhs );
		~Character();

		std::string		getName( void ) const;

		std::string		_name;

	protected:

		void			setName( std::string const &name );
		Character();

	private:

		Character( Character const & src );
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************** Character_H */
