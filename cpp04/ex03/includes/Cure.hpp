#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

class Cure
{

	public:

		Cure();
		~Cure();



	private:
		Cure &		operator=( Cure const & rhs );
		Cure( Cure const & src );



};

//std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */
