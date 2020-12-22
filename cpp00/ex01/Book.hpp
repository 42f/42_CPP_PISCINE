#ifndef BOOK_HPP
# define BOOK_HPP

#include "retro_facebook.hpp"
#include "ContactSheet.hpp"

class Book
{

	public:

		Book();
		~Book();

		void	show_all_contacts( void ) const;
		void	show_one_contacts( int index ) const;

	private:

		ContactSheet	contact[8];

};

#endif /* ************************************************************ BOOK_H */
