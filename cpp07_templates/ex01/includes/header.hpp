#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>

template< typename T>
void	function(T &val)	{

	val += 10;
}

template< typename T>
void	iter(T * arr, size_t len, void (*f)(T &elem))	{

	for (size_t i = 0; i < len && arr != NULL; i++)
			f(arr[i]);
}

template< typename T>
void	iter(T * const arr, size_t len, void (*f)(T const &elem))	{

	for (size_t i = 0; i < len && arr != NULL; i++)
			f(arr[i]);
}

#endif /* *****BVALETTE****** HEADER_H */
