# include "AForm.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

AForm::AForm(  std::string const name, int signGrade, int execGrade  ) : _name(name),
																		_signedStatus(false),
																		_signGrade(signGrade),
																		_execGrade(execGrade)	{

	if (signGrade < Bureaucrat::gradeMax || execGrade < Bureaucrat::gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > Bureaucrat::gradeMin || execGrade > Bureaucrat::gradeMin)
		throw Bureaucrat::GradeTooLowException();
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
AForm::AForm( const AForm & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

AForm::~AForm()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
AForm &				AForm::operator=( AForm const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, AForm const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// void			AForm::execute( Bureaucrat const & executor ) const	{

// 	// if (this->getSignStatus() == false)
// 	// 	throw Bureaucrat::AFormNotSignedException();
// 	// else if (this->getExecGrade() < executor.getGrade())
// 	// 	throw Bureaucrat::GradeTooLowException();
// 	(void)executor;
// 	std::cout << "coucou_fromm_ form::execute" << std::endl;
// }

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

std::string		AForm::getName( void ) const			{ return (this->_name); }
int				AForm::getSignGrade( void ) const	{ return (this->_signGrade); }
int				AForm::getExecGrade( void ) const	{ return (this->_execGrade); }
bool			AForm::getSignStatus( void ) const	{ return (this->_signedStatus); }

void			AForm::beSigned( Bureaucrat & signCandidate)	{

	if (signCandidate.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->_signedStatus = true;
}

void			AForm::executionCheck( Bureaucrat const & executor ) const	{

	if (this->getSignStatus() == false)
		throw Bureaucrat::FormNotSignedException();
	else if (this->getExecGrade() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
