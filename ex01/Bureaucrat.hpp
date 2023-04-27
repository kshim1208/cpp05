#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

# include <iostream>

class Form;

class Bureaucrat
{
	protected:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat& operator=(const Bureaucrat& source);

		class ChangeTooMuchException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		const std::string&	getName(void) const;
		int			getGrade(void)const;
		void	gradeIncrement(int change);
		void	gradeDecrement(int change);

		void	signForm(Form &aForm);
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat &source);

#endif