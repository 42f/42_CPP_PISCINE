#ifndef MIGHTYGOBLIN_HPP
# define MIGHTYGOBLIN_HPP

# include "Character.hpp"
# include "Victim.hpp"
# include <iostream>
# include <string>

class MightyGoblin : public Victim
{

	public:

		MightyGoblin( std::string const name );
		~MightyGoblin();
		MightyGoblin &		operator=( MightyGoblin const & rhs );

	private:
		MightyGoblin();
		MightyGoblin( MightyGoblin const & src );


};

std::ostream &			operator<<( std::ostream & o, MightyGoblin const & i );

#endif /* ************************************************************ MightyGoblin_H */
