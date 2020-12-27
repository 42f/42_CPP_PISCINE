#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
# include <iostream>
# include <string>

class ZombieHorde
{

	public:

		ZombieHorde( int const n );
		~ZombieHorde();


	private:
		void			zombieRandomizer( Zombie *zombieToRandomize );
		Zombie			*_horde;
};

#endif /* ***************************************************** ZOMBIEHORDE_H */
