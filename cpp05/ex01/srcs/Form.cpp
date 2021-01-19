# include "Form.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Form::Form(  std::string const name, int signGrade, int execGrade  ) : _name(name),
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
Form::Form( const Form & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

Form::~Form()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
Form &				Form::operator=( Form const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, Form const & i )	{

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

std::string		Form::getName( void ) const			{ return (this->_name); }
int				Form::getSignGrade( void ) const	{ return (this->_signGrade); }
int				Form::getExecGrade( void ) const	{ return (this->_execGrade); }
bool			Form::getSignStatus( void ) const	{ return (this->_signedStatus); }

void			Form::beSigned( Bureaucrat & signCandidate)	{

	if (signCandidate.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->_signedStatus = true;
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
