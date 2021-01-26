# include "header.hpp"
# include <iostream>
# include <stdlib.h>

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef RED_COLOR
# define RED_COLOR    "\033[31m"
#endif

class Awesome {
	public :
		Awesome ( void ) : _n(0) {}						// add constructor by default + accessor getValue + const keyword
		Awesome ( int n ) : _n(n) {}
		bool	operator==( Awesome const &rhs ) const	{return (this->_n == rhs._n); }
		bool	operator!=( Awesome const &rhs ) const	{return (this->_n != rhs._n); }
		bool	operator> ( Awesome const &rhs ) const	{return (this->_n >  rhs._n); }
		bool	operator< ( Awesome const &rhs ) const	{return (this->_n <  rhs._n); }
		bool	operator>=( Awesome const &rhs ) const	{return (this->_n >= rhs._n); }
		bool	operator<=( Awesome const &rhs ) const	{return (this->_n <= rhs._n); }

		int		getValue( void ) const { return (this->_n); }

	private:
		int _n;
};


int		main( void ) 	{

	std::cout << RED_COLOR << "-------- [START MAIN FROM SUBJECT] -----------" << RESET_COLOR << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	}
	std::cout << RED_COLOR << "-------- [END   MAIN FROM SUBJECT] -----------" << RESET_COLOR << std::endl;
	std::cout << RED_COLOR << "-------- [Awesome class] -----------" << RESET_COLOR << std::endl;
	{
		Awesome a(42);
		Awesome b(21);

		Awesome c = min(a, b);
		std::cout << "Min of (" << a.getValue() << ", " << b.getValue() << ") = " << c.getValue() << std::endl;
		c = max(a, b);
		std::cout << "Max of (" << a.getValue() << ", " << b.getValue() << ") = " << c.getValue() << std::endl;
		std::cout << "[swap: before] a = " << a.getValue() << ", b = " << b.getValue() << std::endl;
		::swap(a, b);
		std::cout << "[swap: after ] a = " << a.getValue() << ", b = " << b.getValue() << std::endl;

	}
	return (0);
}
