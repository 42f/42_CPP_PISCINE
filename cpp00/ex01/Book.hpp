#ifndef BOOK_HPP
# define BOOK_HPP

#include "retro_facebook.hpp"
#include "ContactSheet.hpp"

class Book
{

	public:

		Book();
		~Book();

		bool	show_all_contacts( void ) const;
		bool	show_one_contact( int index ) const;
		bool	add_one_contact( void );

	private:

		ContactSheet	contact[NB_OF_CONTACTS];

};

#endif /* ************************************************************ BOOK_H */
