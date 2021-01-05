#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>
# include <string>

class Sample
{

	public:

		Sample();										//canon
		Sample( int const n );
		Sample( Sample const & src );					//canon
		~Sample();										//canon (+ virtual?)

		Sample &		operator=( Sample const & rhs );	//canon

		int				getValue( void ) const ;

	private:

		int				_n;

};

std::ostream &			operator<<( std::ostream & o, Sample const & i );

#endif /* ********************************************************** SAMPLE_H */
