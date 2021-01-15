#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"
# include <iostream>
# include <string>

class SuperMutant : public Enemy
{

	public:

		SuperMutant();
		~SuperMutant();
		virtual void		takeDamage(int amount);


	private:
		SuperMutant &		operator=( SuperMutant const & rhs );
		SuperMutant( SuperMutant const & src );

};

#endif /* ***************************************************** SUPERMUTANT_H */
