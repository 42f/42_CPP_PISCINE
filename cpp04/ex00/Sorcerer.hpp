#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
#include <sstream>
# include <string>

class Sorcerer
{

	public:

		Sorcerer( std::string const name, std::string const title );
		Sorcerer( Sorcerer const & src );
		Sorcerer &		operator=( Sorcerer const & rhs );
		~Sorcerer();


		void						sayHello( void ) const;
		std::string					introduce( void ) const;
		std::string					getName( void ) const;
		std::string					getTitle( void ) const;


	private:
		Sorcerer();

		std::string		_name;
		std::string		_title;
};

std::ostream &			operator<<( std::ostream & o, Sorcerer const & i );

#endif /* ******************************************************** SORCERER_H */
