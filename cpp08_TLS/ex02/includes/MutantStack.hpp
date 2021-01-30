#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <iterator>

#include <algorithm>
#include <numeric>

template< typename T>
class MutantStack : public std::stack< T, std::list<T> >
{

	public:

		class iterator	{

			public:
				iterator( MutantStack &is ) : _s(is), _index(0) {};
				iterator( MutantStack &is, bool ) : _s(is), _index(_s.top()) {};

				T	current( void )	{ return _s.top(); };

				// std::ostream &			operator<<( std::ostream & o, MutantStack const & i )	{

				// 	o << i.current();
    			// 	return o;
				// };
			private:
                MutantStack&	_s;
                int				_index;

		};

		iterator begin()	{ return iterator(*this); }
		iterator end()		{ return iterator(*this, true);	}

		MutantStack( void ) {};
		~MutantStack( void ) {};


	private:

		// KEEP ME
		// MutantStack &		operator=( MutantStack const & rhs );
		// MutantStack( MutantStack const & src );
};


// std::ostream &			operator<<( std::ostream & o, MutantStack const & i );

#endif /* *****BVALETTE****** MUTANTSTACK_H */
