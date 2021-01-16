#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

class Ice
{

	public:

		Ice();
		~Ice();



	private:
		Ice &		operator=( Ice const & rhs );
		Ice( Ice const & src );



};

//std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************ ICE_H */
