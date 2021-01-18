# include "KoalaSteroid.hpp"

std::string const KoalaSteroid::_name = "KoalaSteroid";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

KoalaSteroid::KoalaSteroid( void )	{

}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

// KoalaSteroid::KoalaSteroid( const IAsteroid & src )	{

// }



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

KoalaSteroid::~KoalaSteroid()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// KoalaSteroid &				KoalaSteroid::operator=( KoalaSteroid const & rhs )	{

	// if ( this != &rhs )
	// {
	// 	this->_value = rhs.getValue();
	// }
	// return *this;
// }

/*****
std::ostream &			operator<<( std::ostream & o, KoalaSteroid const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string KoalaSteroid::beMined(__attribute__((unused))StripMiner *src) const	{ return("Tartarite"); }
std::string KoalaSteroid::beMined(__attribute__((unused))DeepCoreMiner *src) const	{ return("Meium"); }

std::string KoalaSteroid::getName() const	{

	return (this->_name);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* **********************************BVALETTE******************************** */
