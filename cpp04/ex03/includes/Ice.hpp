#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice : public AMateria
{

	public:

		Ice();
		~Ice();

		virtual Ice *		 	clone() const ;
		virtual void			use(ICharacter& target);

	private:
		Ice &		operator=( Ice const & rhs );
		Ice( Ice const & src );



};

//std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************ ICE_H */
