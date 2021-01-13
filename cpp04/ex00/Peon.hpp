#ifndef PEON_HPP
# define PEON_HPP

# include "Character.hpp"
# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : public Victim
{

	public:

		Peon( std::string const name );
		~Peon();
		Peon &		operator=( Peon const & rhs );

	private:
		Peon();
		Peon( Peon const & src );

};

std::ostream &			operator<<( std::ostream & o, Peon const & i );

#endif /* ************************************************************ PEON_H */
