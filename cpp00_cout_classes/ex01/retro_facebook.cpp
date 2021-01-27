#include "Book.class.hpp"
#include "ContactSheet.class.hpp"

void	add_handler( Book *retro_facebook )
{
	if (retro_facebook->add_one_contact() == false)
		std::cout << "Could not add any new contact, try a SEARCH or buy a bigger retro_facebook 8 kbytes, 1982 new edition!" << std::endl;
}

void	search_handler( const Book *retro_facebook )
{
	std::string		input;
	int				search_index;

	if (retro_facebook->show_all_contacts() == true)
	{
		std::cout << "Please enter a contact number to get more details" << std::endl;
		getline(std::cin, input);
		std::stringstream(input) >> search_index;
		if (retro_facebook->show_one_contact(search_index) == false)
			std::cout << "Try SEARCH again" << std::endl;
	}
	else
		std::cout << "There are no entries to show. Add some contacts with ADD." << std::endl;
}

void	retro_facebook_machine( void )
{
	Book			retro_facebook;
	std::string		input;

	while (getline(std::cin, input) && str_option_exit.compare(input) != 0)
	{
		if (str_option_add.compare(input) == 0)
			add_handler( &retro_facebook );
		else if (str_option_search.compare(input) == 0)
			search_handler( &retro_facebook );
	}
}

int		main(const int ac, __attribute__((unused))const char **av)
{
	if (ac == 1)
		retro_facebook_machine();
	else
	{
		std::cerr << "This program does not take any argument." << std::endl;
		return (1);
	}
	return (0);
}
