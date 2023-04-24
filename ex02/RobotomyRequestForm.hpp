#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>

# include "AForm.hpp"

# define reqSignRobReq 72
# define reqExecRobReq 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string target_;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& source);

	void	procedure(void) const;
};

#endif