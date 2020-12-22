#include <iostream>
#include "Sample2.class.hpp"

Sample2::Sample2( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3){

	std::cout << "Constructor called" << std::endl;
	std::cout 	<< "a1 = " << this->a1 << std::endl
				<< "a2 = " << this->a2 << std::endl
				<< "a3 = " << this->a3 << std::endl;
	return ;
}

Sample2::~Sample2( void ) {

	std::cout << "Destructor called" << std::endl;
	std::cout 	<< "a1 = " << this->a1 << std::endl
				<< "a2 = " << this->a2 << std::endl
				<< "a3 = " << this->a3 << std::endl;
	return ;
}

void	Sample2::bar( void ) {

	std::cout << "MEMBER FUNCTION" << std::endl;
	return ;
}
