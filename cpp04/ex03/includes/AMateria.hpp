#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{

	public:
		AMateria(std::string const & type);
		[...]
		[...] ~AMateria();

		std::string const & 	getType() const; //Returns the materia type
		unsigned int 			getXP() const; //Returns the Materia's XP

		virtual AMateria* 		clone() const = 0;
		virtual void			use(ICharacter& target);		//+10xp

	private: [...]
		unsigned int			_xp;

};

//std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ************************************************************ AMATERIA_H */
