#include "Book.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Book::Book()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Book::~Book()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Book::show_one_contacts( int index ) const
{
	std::cout << "[" << index << "]" << this->contact[index].first_name << std::endl;
}

void	Book::show_all_contacts( void ) const
{
	for (int i = 0; i < 8; i++)
		std::cout << "[" << i << "]" << this->contact[i].first_name << std::endl;
}


/* ************************************************************************** */
