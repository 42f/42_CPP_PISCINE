#ifndef BOOK_CLASS_HPP
# define BOOK_CLASS_HPP

#include "retro_facebook.hpp"
#include "ContactSheet.class.hpp"

class Book
{

	public:

		Book();
		~Book();

		bool	show_all_contacts( void ) const;
		bool	show_one_contact( int index ) const;
		bool	add_one_contact( void );

	private:

		ContactSheet	_contact[NB_OF_CONTACTS];

};

#endif /* ************************************************************ BOOK_H */
