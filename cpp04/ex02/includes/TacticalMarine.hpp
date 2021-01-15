#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>
# include <string>

class TacticalMarine : public ISpaceMarine
{

	public:

		TacticalMarine();
		~TacticalMarine();

		virtual ISpaceMarine*	clone() const;
		virtual void			battleCry( void ) const;
		virtual void			rangedAttack( void ) const;
		virtual void			meleeAttack( void ) const;

	private:
		TacticalMarine( TacticalMarine & src );
		TacticalMarine &		operator=( TacticalMarine const & rhs );
		TacticalMarine( TacticalMarine const & src );

};

#endif /* ************************************************** TACTICALMARINE_H */
