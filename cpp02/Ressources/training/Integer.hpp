#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>
# include <string>

class Integer
{

	public:

		int				getValue( void ) const;

		Integer( int const n);
		~Integer();

		Integer &		operator=( Integer const & rhs );
		Integer 		operator+( Integer const & rhs ) const ;

	private:

		int		_n;

};

std::ostream &			operator<<( std::ostream & o, Integer const & i );

#endif /* ******************************************************** INTERGET_H */
