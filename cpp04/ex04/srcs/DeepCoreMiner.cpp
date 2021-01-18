# include "DeepCoreMiner.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DeepCoreMiner::DeepCoreMiner( void )	{

}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
DeepCoreMiner::DeepCoreMiner( const DeepCoreMiner & src )	{

}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DeepCoreMiner::~DeepCoreMiner()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
DeepCoreMiner &				DeepCoreMiner::operator=( DeepCoreMiner const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, DeepCoreMiner const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** --------------------------------- METHODS ----------------------------------
*/

void 	DeepCoreMiner::mine(IAsteroid* target)	{

	if (target != NULL)
		std::cout << "* mining deep... got " << target->beMined(this) << "! *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* **********************************BVALETTE******************************** */
