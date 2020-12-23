#ifndef CONSTANTS_H
# define CONSTANTS_H

extern const std::string 	str_option_add;
extern const std::string 	str_option_search;
extern const std::string 	str_option_exit;

# define	NB_OF_CONTACTS	8
# define	NB_OF_FIELDS	11

enum	e_infos
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	LOGIN,
	POSTAL_ADDRESS,
	EMAIL_ADDRESS,
	BIRTHDAY_DATE,
	FAVORITEMEAL,
	UNDERWEAR_COLOR,
	DARKEST_SECRET,
	PHONE_NUMBER
};

extern const std::string	fields_names[NB_OF_FIELDS];

#endif
