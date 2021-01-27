#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm( std::string const &target );
		~RobotomyRequestForm( void );



	private:
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		RobotomyRequestForm( RobotomyRequestForm const & src );



};

//std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* *****BVALETTE****** ROBOTOMYREQUESTFORM_H */
