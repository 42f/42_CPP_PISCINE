#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class ICharacter;

class AMateria
{

	public:
		AMateria(std::string const & type);
		AMateria &		operator=( AMateria const & rhs );
		virtual ~AMateria();

		std::string const & 	getType( void ) const; //Returns the materia type
		unsigned int 			getXP( void ) const; //Returns the Materia's XP

		virtual AMateria * 		clone( void ) const = 0;
		virtual void			use(ICharacter& target);

	private:

		unsigned int			_xp;
		std::string	const		_type;

};

#endif /* ************************************************************ AMATERIA_H */
