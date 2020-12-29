#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{

	public:
		std::string			identify( void );
		Brain				&getBrain( void );
		Human();
		~Human();
	private:
		Brain				_humanBrain;
};

#endif /* *********************************************************** HUMAN_H */
