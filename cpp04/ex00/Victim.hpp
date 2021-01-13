#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{

	public:

		Victim();
		Victim( Victim const & src );
		~Victim();

		Victim &		operator=( Victim const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Victim const & i );

#endif /* ********************************************************** VICTIM_H */