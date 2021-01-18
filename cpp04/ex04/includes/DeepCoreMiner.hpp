#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"
# include <iostream>
# include <string>

class DeepCoreMiner : public IMiningLaser
{

	public:

		DeepCoreMiner( void );
		~DeepCoreMiner( void );

		virtual void mine(IAsteroid* target);

	// protected:
	private:
		DeepCoreMiner &		operator=( DeepCoreMiner const & rhs );
		DeepCoreMiner( DeepCoreMiner const & src );


};

//std::ostream &			operator<<( std::ostream & o, DeepCoreMiner const & i );

#endif /* *****BVALETTE****** DEEPCOREMINER_H */
