#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"
# include <iostream>
# include <string>

class ISquad
{
	public:

		virtual 				~ISquad() {}

		virtual int				getCount( void ) const = 0;
		virtual ISpaceMarine*	getUnit(int) const = 0;
		virtual int				push(ISpaceMarine*) = 0;
};
#endif /* ********************************************************** ISQUAD_H */
