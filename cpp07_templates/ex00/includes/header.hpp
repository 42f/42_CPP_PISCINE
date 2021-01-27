#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>

template< typename T>
void	swap( T &a, T &b)	{

	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template< typename T>
T const &min( T const &a, T const &b)	{

	return ( a < b ? a : b );
}

template< typename T>
T const &max( T const &a, T const &b)	{

	return ( a > b ? a : b );
}
#endif /* *****BVALETTE****** HEADER_H */
