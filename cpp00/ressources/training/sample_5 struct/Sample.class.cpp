#include <iostream>
#include "Sample.class.hpp"

Sample0::Sample0( void ) {

	std::cout << "0 0 0 Constructor called" << std::endl;
	this->publicFoo = 42;
	return ;
}

Sample0::~Sample0( void ) {

	std::cout << "0 0 0 Destructor called" << std::endl;
	return ;
}
void	Sample0::publicBar0( void ) const {

	std::cout << "0 0 0 MEMBER FUNCTION public" << std::endl;


	return ;
}

Sample::Sample( void ) {

	std::cout << "1 1 1 Constructor called" << std::endl;
	this->publicFoo = 42;
	return ;
}

Sample::~Sample( void ) {

	std::cout << "1 1 1 Destructor called" << std::endl;
	return ;
}
void	Sample::publicBar( void ) const {

	std::cout << "1 1 1 MEMBER FUNCTION public" << std::endl;

	return ;
}
