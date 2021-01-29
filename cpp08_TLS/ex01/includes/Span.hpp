#ifndef SPAN_HPP
# define SPAN_HPP

//# include ""
# include <iostream>
# include <string>

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

		int				longestSpan( void );
		int				shortestSpan( void );
		void			addNumber( int const newNumber );
		void			printNumbers( void );

	private:

		unsigned int	_storedNumber;
		unsigned int	_size;
		int	*			_intArr;
};

//std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* *****BVALETTE****** SPAN_H */
