# include "Array.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template< typename T >
Array<T>::Array( unsigned int n ) : _n(n) {

	this->_arr = new T*[n];
	for (unsigned int i = 0; i < n; i++)
		this->_arr[i] = new T;
}

template< typename T >
Array<T>::Array( void )	: _n(0), _arr(NULL){
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template< typename T >
Array<T>::Array( const Array & src )	{

	*this = src;
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template< typename T >
Array<T>::~Array()	{
	for (unsigned int i = 0; i < this->getSize(); i++)
		delete this->_arr[i];
	delete [] this->_arr;
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template< typename T >
Array<T> &		Array<T>::operator=( Array<T> const & rhs )	{

	if ( this != &rhs )
	{
		for (unsigned int i = 0; i < this->getSize(); i++)
			delete this->_arr[i];
		delete [] this->_arr;

		this->_n = rhs.getSize();
		this->_arr = new T*[this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
		{
			this->_arr[i] = new T;
			*this->_arr[i] = *rhs._arr[i];			// to get the reference data from [] operator ?
		}
	}
	return *this;
}

template< typename T >
T &	 		Array<T>::operator[]( unsigned int idx)	{

	if (idx < this->getSize())
		return (*this->_arr[idx]);
	else
		throw std::exception();
}

template< typename T >
const T &	Array<T>::operator[]( unsigned int idx) const	{

	if (idx < this->getSize())
		return (*this->_arr[idx]);
	else
		throw std::exception();
}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

template< typename T >
unsigned int	Array<T>::getSize( void )	const { return this->_n; };

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
