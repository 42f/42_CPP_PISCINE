#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( int xa, int xb, int xc ) :	a(xa),
											b(xb),
											c(xc) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void		Sample::setBar( int cxa, int cxb, int cxc ) {
	std::cout << "SET member function called" << std::endl;
	this->a = cxa;
	this->b = cxb;
	this->c = cxc;
	return ;
}

void		Sample::getBar( void ) const {

	std::cout << "GET member function called" << std::endl;
	std::cout << "Value a =" << this->a << std::endl;
	std::cout << "Value b =" << this->b << std::endl;
	std::cout << "Value c =" << this->c << std::endl;

	return ;
}

