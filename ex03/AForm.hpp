#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name_;
		bool				isSigned_;
		const int			reqGradeToSign_;
		const int			reqGradeToExec_;

	public:
		AForm();
		AForm(std::string name);
		AForm(int sign, int exec);
		AForm(std::string name, int sign);
		AForm(std::string name, int sign, int exec);
		virtual ~AForm();
		AForm(const AForm& source);
		AForm& operator=(const AForm& source);

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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		int					getReqSign(void) const;
		int					getReqExec(void) const;

		bool			beSigned(Bureaucrat &buro);
		void			setSign(bool status);

		bool			execute(Bureaucrat const & executor) const;
		virtual	void	procedure(void) const = 0;
};

std::ostream& operator<<(std::ostream &output, const AForm &source);

#endif