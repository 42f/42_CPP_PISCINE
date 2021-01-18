#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"
# include <iostream>
# include <string>

class StripMiner : public IMiningLaser
{

	public:

		StripMiner( void );
		~StripMiner( void );

		virtual void mine(IAsteroid* target);

	private:
		StripMiner &		operator=( StripMiner const & rhs );
		StripMiner( StripMiner const & src );



};

//std::ostream &			operator<<( std::ostream & o, StripMiner const & i );

#endif /* *****BVALETTE****** STRIPMINER_H */
