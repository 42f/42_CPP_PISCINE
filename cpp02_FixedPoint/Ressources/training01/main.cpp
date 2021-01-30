#include "Sample.hpp"

int		main ( void )	{

	// Sample a;
	// Sample b( 42 );
	// a = 21;
	// Sample c ( a );

	Sample a(1);
	Sample b(2);
	Sample c(3);

	std::cout << "Value of a: " << a.getValue() << std::endl;
	std::cout << "Value of b: " << b.getValue() << std::endl;
	std::cout << "Value of c: " << c.getValue() << std::endl;

	std::cout << "-- Value of a: " << a.getValue() << std::endl;
	std::cout << "-- Value of b: " << b.getValue() << std::endl;
	std::cout << "-- Value of c: " << c.getValue() << std::endl;


	return (0);
}
