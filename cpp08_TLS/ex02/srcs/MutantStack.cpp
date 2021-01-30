# include "MutantStack.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template<typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {
	return ;
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {
	return ;
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template<typename T>
MutantStack<T>::~MutantStack( void ) {
	return ;
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// template< typename T>
// std<T>::ostream &			operator<<( std::ostream & o, MutantStack const & i )	{

// 	o << i.();
// 	return o;
// }

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &rhs) {
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// template< typename T>
// iterator	MutantStack<T>::begin( void )	{
// 	std::cout << "COUCOU" << std::endl;
// }

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
