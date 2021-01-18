# include "StripMiner.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

StripMiner::StripMiner( void )	{

}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
StripMiner::StripMiner( const StripMiner & src )	{

}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

StripMiner::~StripMiner()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
StripMiner &				StripMiner::operator=( StripMiner const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, StripMiner const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** --------------------------------- METHODS ----------------------------------
*/

void 	StripMiner::mine(IAsteroid* target)	{

	if (target != NULL)
		std::cout << "* strip mining... got "  << target->beMined(this) << "! *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* **********************************BVALETTE******************************** */
