# include "ShrubberyCreationForm.hpp"
# include <sstream>
# include <fstream>

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) : AForm("ShrubberyCreationForm", 25, 5), _target(target)	{
}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CTOR  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )	{

}
*****/



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DESTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

ShrubberyCreationForm::~ShrubberyCreationForm()	{

}



/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OVERLOAD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*****
ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )	{

	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}
*****/

/*****
std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )	{

	o << "Value = " << i.getValue();
	return o;
}
*****/


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void	ShrubberyCreationForm::execute( Bureaucrat const & executor) const	{

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

void	ShrubberyCreationForm::action( void ) const	{

	std::cout << "DOING ACTION ShrubberyCreationForm" << std::endl;

	std::stringstream	fileName;
	size_t const		max = 24;

	fileName << this->_target << "_shrubbery";
	try
	{
		std::ofstream	ofs(fileName.str().c_str() , std::ofstream::app);
		for
	}
	catch (const std::exception & e)
	{
		std::cerr << "Could not open the output file: " << e.what() << std::endl;
	}


/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
