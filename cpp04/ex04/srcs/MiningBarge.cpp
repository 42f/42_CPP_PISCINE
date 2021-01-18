# include "MiningBarge.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MiningBarge::MiningBarge( void )	{

	for (size_t i = 0; i < MiningBarge::_bargeCapacity; i++)
		this->_inventory[i] = NULL;
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
MiningBarge::MiningBarge( const MiningBarge & src )	{

}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MiningBarge::~MiningBarge()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
MiningBarge &				MiningBarge::operator=( MiningBarge const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, MiningBarge const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** --------------------------------- METHODS ----------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		MiningBarge::equip(IMiningLaser* src)	{

	if (src == NULL)
		return ;
	for (size_t i = 0; i < MiningBarge::_bargeCapacity ; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = src;
			break ;
		}
	}
}

void		MiningBarge::mine(IAsteroid* target) const	{

	for (size_t i = 0; i < MiningBarge::_bargeCapacity ; i++)
	{
		if (this->_inventory[i] != NULL)
			this->_inventory[i]->mine(target);
	}
}



/* **********************************BVALETTE******************************** */
