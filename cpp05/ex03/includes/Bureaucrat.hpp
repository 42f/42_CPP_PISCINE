#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <stdexcept>

class AForm;

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

		class FormNotSignedException : public std::exception
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

		void				executeForm( AForm const & );
		void				signForm( AForm & );

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
