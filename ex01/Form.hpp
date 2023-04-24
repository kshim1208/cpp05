#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name_;
		bool				isSigned_;
		const int			reqGradeToSign_;
		const int			reqGradeToExec_;

		std::string		test_;

	public:
		Form();
		Form(std::string name);
		Form(std::string name, int sign);
		Form(std::string name, int sign, int exec);
		~Form();
		Form(const Form& source);
		Form& operator=(const Form& source);

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
		class AlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		int					getReqSign(void) const;
		int					getReqExec(void) const;

		bool	beSigned(Bureaucrat &buro);
};

#endif