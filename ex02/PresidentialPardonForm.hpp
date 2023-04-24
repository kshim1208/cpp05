#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

# define reqSignPresPardon 25
# define reqExecPresPardon 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target_;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);

	void	procedure(void) const;
};

#endif