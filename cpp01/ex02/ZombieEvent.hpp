#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <iostream>
# include <string>

class ZombieEvent
{

	public:

		static void			randomChump( void );
		static void			setZombieType(std::string const type);
		static Zombie		*newZombie(std::string const name);

	private:
		static std::string	_storedType;

};

#endif /* ***************************************************** ZOMBIEEVENT_H */
