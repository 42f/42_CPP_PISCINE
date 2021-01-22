#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "AForm.hpp"
# include <iostream>
# include <string>

class Intern
{

	public:

		Intern( void );
		~Intern( void );

		AForm 	*makeForm( std::string const &formRequest, std::string const &target);

	private:
		Intern &		operator=( Intern const & rhs );
		Intern( Intern const & src );

		AForm *		allocateFormShrubbery( std::string const &target );
		AForm *		allocateFormPresidential( std::string const &target );
		AForm *		allocateFormRobotomy( std::string const &target );
		AForm *		invalidForm( std::string const &target );


};

//std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* *****BVALETTE****** INTERN_H */
