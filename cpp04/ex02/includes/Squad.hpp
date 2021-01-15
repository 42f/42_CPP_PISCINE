#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "TacticalMarine.hpp"
# include <iostream>
# include <string>

class Squad : public ISquad
{

	public:

		Squad();
		Squad( Squad const & src );
		~Squad();


		virtual int				getCount() const;
		virtual ISpaceMarine*	getUnit(int) const;
		virtual int				push(ISpaceMarine*);

	private:
		int					_count;
		ISpaceMarine**		_units;
		Squad &		operator=( Squad const & rhs );
};

#endif /* *********************************************************** SQUAD_H */
