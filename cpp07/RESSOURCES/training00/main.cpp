# include <stdio.h>
# include <iostream>

// template< typename T, typename U>
// template< typename T = float>	// by default
template< typename T >
T const & max( T const &x, T const &y) {

	return ( x >= y ? x : y);
}

template< typename T>
T const & min( T const &x, T const &y) {

	return ( max<T>(x, y));
}

int foo( int x ) {
	std::cout << "LONG TIIIIME" << std::endl;
	return (x);
}

int main ( void )	{

	std::cout << std::fixed;
	std::cout << max<int>(42, 21) << std::endl;		// explicite
	std::cout << max<>(42, 21) << std::endl;		// implicite

	std::cout << max<float>(42, 21) << std::endl;		// explicite
	std::cout << max<>(42, 21) << std::endl;		// implicite

	std::cout << max<char>(foo(42), foo(21)) << std::endl;		// explicite
	std::cout << max<>(foo(42), foo(21)) << std::endl;		// implicite

	std::cout << min<int>(42, 21) << std::endl;		// explicite
	std::cout << min<>(42, 21) << std::endl;		// implicite

	extern char **environ;
	printf(" -- [%s]\n", environ[0]);

	environ[0][0] = '=';
	environ[0][1] = 'X';
	printf(" -- [%s]\n", environ[0]);

	char **p = NULL;
	environ = p;
	int a = 42;
	int const * const ptr = &a;
	printf("ptr %d\n", *ptr);
	a = 3;
	printf("ptr %d\n", *ptr);
}
