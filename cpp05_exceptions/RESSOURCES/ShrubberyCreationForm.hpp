#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <string>

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm( std::string const &target );
		~ShrubberyCreationForm( void );



	private:
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );



};

//std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* *****BVALETTE****** SHRUBBERYCREATIONFORM_H */
