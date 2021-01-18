#ifndef BABYPEON_HPP
# define BABYPEON_HPP

# include "Peon.hpp"
# include "Victim.hpp"
# include <iostream>
# include <string>

class BabyPeon : public Peon
{

	public:

		BabyPeon( std::string const name );
		virtual ~BabyPeon();
		BabyPeon &		operator=( BabyPeon const & rhs );

		virtual void	beDead( void ) const;

	private:
		BabyPeon();
		BabyPeon( BabyPeon const & src );

};

std::ostream &			operator<<( std::ostream & o, BabyPeon const & i );

#endif /* ************************************************************ BabyPeon_H */
