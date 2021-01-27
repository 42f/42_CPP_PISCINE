# include "ShrubberyCreationForm.hpp"
# include <sstream>
# include <fstream>
# include <iomanip>

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

	std::stringstream	fileName;
	std::stringstream	tmpOutput;

	try
	{
		fileName << this->_target << "_shrubbery";
		std::ofstream	ofs(fileName.str().c_str() , std::ofstream::trunc);

		tmpOutput << std::setw(12) << std::right << std::setfill(' ') << "\\~~/";
		ofs << tmpOutput.str() << std::endl;
		for (int y = 1; y < 10; y++)	{
				tmpOutput.str("");
				tmpOutput << std::setw(10 - y) << std::right << std::setfill(' ') << '~';
				tmpOutput << std::setw(y) << std::right << std::setfill('/') << '|';
				ofs << tmpOutput.str();
				tmpOutput.str("");
				tmpOutput << std::setw(y) << std::left << std::setfill('\\') << '|';
				ofs << tmpOutput.str() << '*';
				ofs << std::endl;
			}
	}
	catch (const std::exception & e)
	{
		std::cerr << "Could not open the output file: " << e.what() << std::endl;
	}
}

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NESTED CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


/* **********************************BVALETTE******************************** */
