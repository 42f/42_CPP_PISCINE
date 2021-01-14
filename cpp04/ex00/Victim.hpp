#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <sstream>
# include <string>

class Victim
{

	public:

		Victim( std::string const name );
		Victim &		operator=( Victim const & rhs );
		~Victim();

		void			sayHello( void ) const;
		std::string		introduce( void ) const;
		void			getPolymorphed( void ) const;

	protected:
		Victim();
		Victim( Victim const & src );

		std::string		getName( void ) const;

		std::string		_name;
};

std::ostream &			operator<<( std::ostream & o, Victim const & i );

#endif /* ******************************************************** Victim_H */
