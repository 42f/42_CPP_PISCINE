#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include "Form.hpp"
# include <iostream>
# include <string>
# include <stdexcept>

class Form;

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what ( void ) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what ( void ) const throw();
		};

		Bureaucrat( std::string const name, int grade ) ;
		~Bureaucrat( void );

		std::string			getName( void ) const;
		int					getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );

		void				signForm( Form & );

		static int const	gradeMax = 1;
		static int const	gradeMin = 150;
		static int const	invalidGrade= 0;

	private:
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );

		std::string	const		_name;
		int						_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* *****BVALETTE****** Bureaucrat_H */
