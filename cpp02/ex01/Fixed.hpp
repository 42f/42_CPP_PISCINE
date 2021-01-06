#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( int const src );
		Fixed( float const src );
		~Fixed();

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;

		void		printToBinary( float const src) const ;
		void		printToBinary( int const src ) const ;
		void		printToBinary( Fixed const *src) const ;

		Fixed &		operator=( Fixed const & rhs );

	private:

		int					_value;
		static const int	_nbFractionalBits;
};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */



// 010001001001101001001101.11010100
//      010001001_001101001.00110111         010100
// 000000000000001001101001.00110111
