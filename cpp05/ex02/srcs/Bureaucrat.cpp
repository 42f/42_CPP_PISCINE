# include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(  std::string const name, int grade  ) : _name(name) {

	if (grade < Bureaucrat::gradeMax)
	{
		this->_grade = Bureaucrat::invalidGrade;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > Bureaucrat::gradeMin)
	{
		this->_grade = Bureaucrat::invalidGrade;
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->_grade = grade;
}



/*
** ------------------------------- COPY CTOR  ---------------------------------
*/

/*****
Bureaucrat::Bureaucrat( const Bureaucrat & src )	{

}
*****/



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()	{

}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*****
Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )	{

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Bureaucrat::getName( void ) const 	{ return (this->_name); };
int				Bureaucrat::getGrade( void ) const 	{ return (this->_grade); };

void			Bureaucrat::incrementGrade( void )	{

	if (this->getGrade() - 1 < Bureaucrat::gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
};

void			Bureaucrat::decrementGrade( void )	{

	if (this->getGrade() + 1 > Bureaucrat::gradeMin)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;

};

void			Bureaucrat::executeForm( AForm const & form)	{

	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void			Bureaucrat::signForm( AForm & form )	{

	try
	{
		form.beSigned(*this);
		std::cerr << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " cannot sign " << form.getName() << " because : \"" << e.what() << "\""<< std::endl;
	}

}

/*
** --------------------------------- NESTED CLASS-------------------------------
*/

const char* 	Bureaucrat::GradeTooHighException::what( void ) const throw()	{ return ("Grade is too High."); }
const char* 	Bureaucrat::GradeTooLowException::what( void ) const throw()	{ return ("Grade is too Low."); }
const char* 	Bureaucrat::FormNotSignedException::what( void ) const throw()	{ return ("Form is not signed."); }

/* **********************************BVALETTE******************************** */
