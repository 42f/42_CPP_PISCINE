#include "Book.hpp"
#include "ContactSheet.hpp"

using namespace std;

void	add_handler( Book *retro_facebook )
{
	(void)retro_facebook;
	std::cout << "Add means ajouter ^^" << std::endl;
}

void	search_handler( const Book *retro_facebook )
{
	string			input;
	int				search_index;

	std::cout << "Search means chercher ^^" << std::endl;
	retro_facebook->show_all_contacts();
	getline(cin, input);
	stringstream(input) >> search_index;
	retro_facebook->show_one_contacts(search_index);
}

void	retro_facebook_machine( void )
{
	Book			retro_facebook;
	string			input;

	while (getline(cin, input) && str_option_exit.compare(input) != 0)
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
		return (1);
	return (0);
}
