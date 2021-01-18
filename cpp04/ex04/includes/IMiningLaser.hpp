#ifndef IMININGLASER_HPP
# define IMININGLASER_HPP

# include "IAsteroid.hpp"
# include <iostream>
# include <string>

class IMiningLaser
{
	public:
		virtual ~IMiningLaser() {}
		virtual void mine(IAsteroid* target) = 0;
};

#endif /* *****BVALETTE****** IMININGLASER_H */
