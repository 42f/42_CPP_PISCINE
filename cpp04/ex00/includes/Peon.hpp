#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : public Victim
{

	public:

		Peon( std::string const name );
		virtual ~Peon();
		Peon &		operator=( Peon const & rhs );

		void			beBorn( void ) const;
		void			beDead( void ) const;
		void			getPolymorphed( void ) const;

	protected:
		Peon();

	private:
		Peon( Peon const & src );

};

std::ostream &			operator<<( std::ostream & o, Peon const & i );

#endif /* ************************************************************ PEON_H */
