#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"
# include <iostream>
# include <string>

class MiningBarge
{

	public:

		MiningBarge( void );
		~MiningBarge( void );

		void equip(IMiningLaser* src);
		void mine(IAsteroid* target) const;


	private:
		MiningBarge &		operator=( MiningBarge const & rhs );
		MiningBarge( MiningBarge const & src );

		static size_t	const	_bargeCapacity = 4;
		IMiningLaser *			_inventory[MiningBarge::_bargeCapacity];

};

//std::ostream &			operator<<( std::ostream & o, MiningBarge const & i );

#endif /* *****BVALETTE****** MININGBARGE_H */
