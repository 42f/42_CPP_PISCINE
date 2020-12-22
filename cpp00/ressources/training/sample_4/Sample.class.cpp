#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;
	this->publicFoo = 42;
	this->_privateFoo = this->publicFoo / 2;
	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}
void	Sample::publicBar( void ) const {

	std::cout << "MEMBER FUNCTION public" << std::endl;
	std::cout << "MEMBER FUNCTION: _privatFoo = " << this->_privateFoo << std::endl;


	return ;
}

void	Sample::_privateBar( void ) const {

	std::cout << "MEMBER FUNCTION _private" << std::endl;
	std::cout << "MEMBER FUNCTION: _privatFoo = " << this->_privateFoo << std::endl;
	return ;
}
