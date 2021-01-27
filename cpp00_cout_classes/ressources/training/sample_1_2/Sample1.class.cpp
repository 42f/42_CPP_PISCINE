#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1( char p1, int p2, float p3 ) {

	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	this->a2 = p2;
	this->a3 = p3;
	std::cout 	<< "a1 = " << this->a1 << std::endl
				<< "a2 = " << this->a2 << std::endl
				<< "a3 = " << this->a3 << std::endl;
	return ;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	std::cout 	<< "a1 = " << this->a1 << std::endl
				<< "a2 = " << this->a2 << std::endl
				<< "a3 = " << this->a3 << std::endl;
	return ;
}

void	Sample1::bar( void ) {

	std::cout << "MEMBER FUNCTION" << std::endl;
	return ;
}
