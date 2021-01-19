#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
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


	public:

		Bureaucrat( std::string const name, int grade ) ;
		~Bureaucrat( void );

		std::string			getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );

	private:
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );

		std::string	const		_name;
		int						_grade;

		static int const		gradeMax = 1;
		static int const		gradeMin = 150;
		static int const		invalidGrade= 0;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* *****BVALETTE****** Bureaucrat_H */
