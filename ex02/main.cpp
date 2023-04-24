#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main()
{
	Bureaucrat	a;
	Bureaucrat	b("Buro_B");
	Bureaucrat	c("Buro_C", 1);
	Bureaucrat	d("Buro_D", 0);

	std::cout << "-------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "-------------------" << std::endl;

	ShrubberyCreationForm shrub("home");
	b.executeForm(shrub);
	c.executeForm(shrub);
	b.signForm(shrub);
	c.signForm(shrub);
	b.executeForm(shrub);
	c.executeForm(shrub);

	std::cout << "-------------------" << std::endl;

	RobotomyRequestForm robo("victim");
	b.executeForm(robo);
	c.executeForm(robo);
	b.signForm(robo);
	c.signForm(robo);
	b.executeForm(robo);
	c.executeForm(robo);

	std::cout << "-------------------" << std::endl;

	PresidentialPardonForm pardon("serialKiller");
	b.executeForm(pardon);
	c.executeForm(pardon);
	b.signForm(pardon);
	c.signForm(pardon);
	b.executeForm(pardon);
	c.executeForm(pardon);
}
