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

bool	Book::add_one_contact( void )
{
	size_t			available_entry;
	std::string		field_input;
	available_entry = 0;
	while (available_entry < NB_OF_CONTACTS
			&& this->contact[available_entry].info[FIRST_NAME].length() != 0)
		available_entry++;
	if (available_entry < NB_OF_CONTACTS)
	{
		for (int field = 0; field < NB_OF_FIELDS; field++)
		{
			std::cout << "--> Please enter contact's " << fields_names[field] << ": " << std::endl;
			while (getline(std::cin, field_input) && field_input.length() == 0)
				std::cerr << "Empty entry, please enter something" << std::endl;
			this->contact[available_entry].info[field].assign(field_input);
		}
		return (true);
	}
	else
	{
		std::cerr << "No more space available in this retro_facebook... sorry it's the 80's here !" << std::endl;
		return (false);
	}

}

bool	Book::show_one_contact( int index ) const
{
	index--;
	if (index >= 0 && index < NB_OF_CONTACTS && this->contact[index].info[FIRST_NAME].length() != 0)
	{
		for (int field = 0; field < NB_OF_FIELDS; field ++)
			std::cout << this->contact[index].info[field] << std::endl;
		return (true);
	}
	else
	{
		std::cout << "Invalid index..." << std::endl;
		return (false);
	}
}

bool	Book::show_all_contacts( void ) const
{
	std::string data;
	int			index;
	int			last_field;

	index = 0;
	last_field = NICKNAME;
	while (index < NB_OF_CONTACTS)
	{
		if (this->contact[index].info[FIRST_NAME].length() == 0)
			break ;
  		std::cout << std::setw(10) << std::right;
		std::cout << index + 1 << '|';
		for (int field = 0; field <= last_field; field ++)
		{
			data = this->contact[index].info[field].substr(0, 9);
			if (data.size() == 9)
				data.insert(data.end(), 1, '.');
  			std::cout << std::setw(10) << std::right;
			std::cout << data;
			if (field < last_field)
				std::cout << '|';
		}
		std::cout << std::endl;
		index++;
	}
	if (index == 0)
		return (false);
	return (true);
}


/* ************************************************************************** */
