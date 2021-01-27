#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template< typename T>
class Array
{

	public:

		Array( void );
		Array( unsigned int n );
		Array( Array const & src );
		Array &		operator=( Array<T> const & rhs );

  		T &	 		operator[]( unsigned int idx );
  		const T & 	operator[]( unsigned int idx ) const;

		~Array( void );

		unsigned int	getSize( void ) const;

	private:

		unsigned int	_n;
		T				**_arr;
};

#endif /* *****BVALETTE****** ARRAY_H */
