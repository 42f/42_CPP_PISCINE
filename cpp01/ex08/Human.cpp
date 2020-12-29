#include "Human.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Human::Human()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Human::~Human()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Human::meleeAttack(std::string const &target) const	{
	std::cout << "Call to MeleeAttack on " << target.c_str() << std::endl;
}

void	Human::rangedAttack(std::string const &target) const	{
	std::cout << "Call to RangedAttack on " << target.c_str() << std::endl;
}

void	Human::intimidatingShout(std::string const &target) const	{
	std::cout << "Shout AHHHRHRHRHHRHHHHHHHH to " << target.c_str() << std::endl;
}

void	Human::nothingAttack( __attribute__((unused))std::string const &target) const	{
}

void	Human::action(std::string const &action_name, std::string const &target) {
	std::string	const name_list[3] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
	void 		(Human::*function_list[4])(std::string const &) const = { &Human::meleeAttack,
				&Human::rangedAttack, &Human::intimidatingShout, &Human::nothingAttack };
	int			i = 0;

	while (name_list[i] != action_name && i < 3)
		i++;
	(this->*function_list[i])(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
