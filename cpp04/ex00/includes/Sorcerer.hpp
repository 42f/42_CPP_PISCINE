#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"
# include <iostream>
# include <sstream>
# include <string>

class Sorcerer
{

	public:

		Sorcerer( std::string const name, std::string const title );
		Sorcerer &		operator=( Sorcerer const & rhs );
		~Sorcerer();

		void						sayHello( void ) const;
		std::string					introduce( void ) const;
		std::string					getName( void ) const;
		std::string					getTitle( void ) const;
		void						polymorph( Victim const & ) const;

	private:
		Sorcerer();
		Sorcerer( Sorcerer const & src );

		std::string		_name;
		std::string		_title;
};

std::ostream &			operator<<( std::ostream & o, Sorcerer const & i );

#endif /* ******************************************************** Sorcerer_H */
