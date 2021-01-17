#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure : public AMateria
{

	public:

		Cure();
		~Cure();

		virtual Cure *		 	clone() const;
		virtual void			use(ICharacter& target);

	private:
		Cure &		operator=( Cure const & rhs );
		Cure( Cure const & src );



};

//std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */
