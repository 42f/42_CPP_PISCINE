# include "AsteroKreog.hpp"


std::string const AsteroKreog::_name = "AsteroKreog";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AsteroKreog::AsteroKreog( void )	{

}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

// AsteroKreog::AsteroKreog( const IAsteroid & src )	{

// }



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AsteroKreog::~AsteroKreog()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// AsteroKreog &				AsteroKreog::operator=( AsteroKreog const & rhs )	{

	// if ( this != &rhs )
	// {
	// 	this->_name = rhs.getName();
	// }
	// return *this;
// }

/*****
std::ostream &			operator<<( std::ostream & o, AsteroKreog const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string AsteroKreog::beMined(__attribute__((unused))StripMiner *src) const		{ return("Flavium"); }
std::string AsteroKreog::beMined(__attribute__((unused))DeepCoreMiner *src) const	{ return("Dragonite"); }

std::string AsteroKreog::getName() const	{

	return (this->_name);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* **********************************BVALETTE******************************** */
