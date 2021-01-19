# include "RobotomyRequestForm.hpp"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) : AForm("RobotomyRequestForm", 25, 5), _target(target)	{
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

RobotomyRequestForm::~RobotomyRequestForm()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void	RobotomyRequestForm::execute( Bureaucrat const & executor) const	{

	try
	{
		this->executionCheck(executor);
		this->action();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACCESSOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void	RobotomyRequestForm::action( void ) const	{
	std::cout << "DOING ACTION RobotomyRequestForm" << std::endl;
}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
