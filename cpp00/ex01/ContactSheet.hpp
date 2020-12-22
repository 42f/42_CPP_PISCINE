#ifndef CONTACTSHEET_HPP
# define CONTACTSHEET_HPP

#include "retro_facebook.hpp"

class ContactSheet
{

	public:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		login;
		std::string		postal_address;
		std::string		email_address;
		std::string		birthday_date;
		std::string		favoritemeal;
		std::string		underwear_color;
		std::string		darkest_secret;
		int				phone_number;

		ContactSheet();
		~ContactSheet();

	private:

};

#endif /* **************************************************** CONTACTSHEET_H */
