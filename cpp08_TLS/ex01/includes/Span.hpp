#ifndef SPAN_HPP
# define SPAN_HPP

//# include ""
# include <iostream>
# include <string>
# include <vector>

class Span
{
	public:
	class SpanExceptionOutofCapacy : public std::exception	{

		public:
			virtual const char* what ( void ) const throw();
	};

	class SpanExceptionNoSpan : public std::exception	{

		public:
			virtual const char* what ( void ) const throw();
	};


		Span( unsigned int n );
		Span( Span const & src );
		Span( void );
		~Span( void );

		Span &		operator=( Span const & rhs );

		unsigned int	longestSpan( void );
		unsigned int	shortestSpan( void );
		void			addNumber( int const newNumber );
		void			addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		void			printNumbers( void );

	private:

		unsigned int		_sizeMax;
		std::vector<int>	_intStorage;
};

//std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* *****BVALETTE****** SPAN_H */
