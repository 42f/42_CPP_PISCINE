#ifndef LONELYSTUD_HPP
# define LONELYSTUD_HPP

# include "Enemy.hpp"
# include <iostream>
# include <string>

class LonelyStud : public Enemy
{

	public:

		LonelyStud();
		virtual ~LonelyStud();

	private:
		LonelyStud &		operator=( LonelyStud const & rhs );
		LonelyStud( LonelyStud const & src );

};

#endif /* ***************************************************** LonelyStud_H */
