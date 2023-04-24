#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <string>

# include "AForm.hpp"

# define reqSignShubCreat 145
# define reqExecShubCreat 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target_;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);

	void	procedure(void) const;
};

#endif