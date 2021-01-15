#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>
# include <string>

class AssaultTerminator : public ISpaceMarine
{

	public:

		AssaultTerminator();
		~AssaultTerminator();

		virtual ISpaceMarine*	clone() const;
		virtual void			battleCry( void ) const;
		virtual void			rangedAttack( void ) const;
		virtual void			meleeAttack( void ) const;

	private:
		AssaultTerminator( AssaultTerminator & src );
		AssaultTerminator &		operator=( AssaultTerminator const & rhs );
		AssaultTerminator( AssaultTerminator const & src );

};

#endif /* ************************************************** AssaultTerminator_H */
