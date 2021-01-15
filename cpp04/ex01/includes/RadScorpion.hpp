#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"
# include <iostream>
# include <string>

class RadScorpion : public Enemy
{

	public:

		RadScorpion();
		~RadScorpion();

	private:
		RadScorpion &		operator=( RadScorpion const & rhs );
		RadScorpion( RadScorpion const & src );

};

#endif /* ***************************************************** RadScorpion_H */
