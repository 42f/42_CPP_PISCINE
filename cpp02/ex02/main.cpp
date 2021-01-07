#include "Fixed.hpp"
#include <iostream>
#include <limits.h>

// void	testConstuctorCopy(int const nbr)	{
// 	std::cout << std::endl << "________ TEST COPY  with: " << nbr << "_____________" << std::endl;
// 	Fixed src (nbr);
// 	Fixed a = src;
// 	std::cout 			   << "           a.toFLOAT ---> " << a.toFloat() << std::endl;
// 	std::cout 			   << "           a.toINT -----> " << a.toInt() << std::endl;
// 	std::cout 			   << "                a with << " << a << std::endl;
// }

// void	testFloat(float const nbr)	{
// 	std::cout << std::endl << "________ TEST FLOAT with: " << nbr << "_____________" << std::endl;
// 	Fixed a( nbr );
// 	std::cout 			   << "           a.toFLOAT ---> " << a.toFloat() << std::endl;
// 	std::cout 			   << "           a.toINT -----> " << a.toInt() << std::endl;
// 	std::cout 			   << "                a with << " << a << std::endl;
// }

// void	testInt(int const nbr)	{
// 	std::cout << std::endl << "________ TEST INT with: " << nbr << "_____________" << std::endl;
// 	Fixed a( nbr );
// 	std::cout 			   << "         a.toFLOAT ---> " << a.toFloat() << std::endl;
// 	std::cout 			   << "         a.toINT -----> " << a.toInt() << std::endl;
// 	std::cout 			   << "              a with << " << a << std::endl;
// }

int		main( void )	{

	std::cout << "----------  MAIN FROM SUBJECT ----------" << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "------- END MAIN FROM SUBJECT ----------" << std::endl;

	Fixed a(42.42f);
	Fixed b(1);
	std::cout << "a==b -> " << (a==b) << ".(sys " << (a.toFloat()==b.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "a==a -> " << (a==a) << ".(sys " << (a.toFloat()==a.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "a!=b -> " << (a!=b) << ".(sys " << (a.toFloat()!=b.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "b!=b -> " << (b!=b) << ".(sys " << (b.toFloat()!=b.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "a<=b -> " << (a<=b) << ".(sys " << (a.toFloat()<=b.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl << std::endl;
	std::cout << "a>=b -> " << (a>=b) << ".(sys " << (a.toFloat()>=b.toFloat()) << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "a<b  -> " << (a<b)  << ".(sys " << (a.toFloat()<b.toFloat())  << ")    (a="<< a << ", b=" << b << ")" << std::endl;
	std::cout << "a>b  -> " << (a>b)  << ".(sys " << (a.toFloat()>b.toFloat())  << ")    (a="<< a << ", b=" << b << ")" << std::endl << std::endl;
	std::cout << "b<=b -> " << (b<=b) << ".(sys " << (b.toFloat()<=b.toFloat()) << ")    (b=" << b << ")" << std::endl;
	std::cout << "b>=b -> " << (b>=b) << ".(sys " << (b.toFloat()>=b.toFloat()) << ")    (b=" << b << ")" << std::endl;
	std::cout << "b<b  -> " << (b<b)  << ".(sys " << (b.toFloat()<b.toFloat())  << ")    (b=" << b << ")" << std::endl;
	std::cout << "b>b  -> " << (b>b)  << ".(sys " << (b.toFloat()>b.toFloat())  << ")    (b=" << b << ")" << std::endl << std::endl;
	std::cout << "a+10  -> " << (a+10)  << " (" << a.toFloat() << "+10 = " << (a.toFloat() + 10) << ")" << std::endl;
	std::cout << "a-10  -> " << (a-10)  << " (" << a.toFloat() << "-10 = " << (a.toFloat() - 10) << ")" << std::endl << std::endl;
	std::cout << "a*2  -> " << (a*2)  << " (" << a.toFloat() << "*2 = " << (a.toFloat() * 2) << ")" << std::endl;
	std::cout << "a/3  -> " << (a/3)  << " (" << a.toFloat() << "/3 = " << (a.toFloat() /3) << ")" << std::endl << std::endl;
	std::cout << "a   =  " << a << std::endl << "a++ -> " << (a++) << std::endl << "a   =  " << a << std::endl << std::endl;
	std::cout << "a   =  " << a << std::endl << "a-- -> " << (a--) << std::endl << "a   =  " << a << std::endl << std::endl;
	std::cout << "a   =  " << a << std::endl << "++a -> " << (++a) << std::endl << "a   =  " << a << std::endl << std::endl;
	std::cout << "a   =  " << a << std::endl << "--a -> " << (--a) << std::endl << "a   =  " << a << std::endl << std::endl;


	return (0);
}

