# include "Intern.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Intern::Intern( void )	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
Intern::Intern( const Intern & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Intern::~Intern()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
Intern &				Intern::operator=( Intern const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, Intern const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

AForm*		Intern::allocateFormShrubbery( std::string const &target )	{
	return (new ShrubberyCreationForm(target));
}

AForm*		Intern::allocateFormPresidential( std::string const &target )	{
	return (new PresidentialPardonForm(target));
}

AForm	*		Intern::allocateFormRobotomy( std::string const &target )	{
	return (new RobotomyRequestForm(target));
}

AForm	*		Intern::invalidForm( __attribute__((unused))std::string const &target )	{

	std::cout << "Invalid form request type" << std::endl;
	return (NULL);
}

AForm*	Intern::makeForm( std::string const &formRequest, std::string const &target)	{

	std::string const	formList[3] = { "shrubbery creation",
										"presidential pardon",
										"robotomy request" };

	AForm*		(Intern::*functionList[4])( std::string const & ) = {	&Intern::allocateFormShrubbery,
										&Intern::allocateFormPresidential,
										&Intern::allocateFormRobotomy,
										&Intern::invalidForm };

	int i = 0;
	while (i < 3 && formRequest.compare(formList[i]) != 0)	{
		i++;
	}
	return ( (this->*functionList[i])(target) );
}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
