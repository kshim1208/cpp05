#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
{
	Bureaucrat	a;
	Bureaucrat	b("Buro_B");
	Bureaucrat	c("Buro_C", 1);
	Bureaucrat	d("Buro_D", 0);
	Intern		someRandomIntern;

	std::cout << "-------------------" << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "-------------------" << std::endl;

	AForm	*shrub = someRandomIntern.makeForm("shrub creat", "home");
	std::cout << std::hex << shrub << std::endl;

	shrub = someRandomIntern.makeForm("Shrubbery Creation", "home");
	b.executeForm(*shrub);
	c.executeForm(*shrub);
	b.signForm(*shrub);
	c.signForm(*shrub);
	b.executeForm(*shrub);
	c.executeForm(*shrub);

	delete shrub;
	std::cout << "-------------------" << std::endl;

	AForm *robo = someRandomIntern.makeForm("robot request", "victim");
	std::cout << std::hex << robo << std::endl;

	robo = someRandomIntern.makeForm("Robotomy Request", "victim");
	b.executeForm(*robo);
	c.executeForm(*robo);
	b.signForm(*robo);
	c.signForm(*robo);
	b.executeForm(*robo);
	c.executeForm(*robo);

	delete robo;
	std::cout << "-------------------" << std::endl;

	AForm *pardon = someRandomIntern.makeForm("president pardon", "serialkiller");
	std::cout << std::hex << pardon << std::endl;

	pardon = someRandomIntern.makeForm("Presidential Pardon", "serialKiller");
	b.executeForm(*pardon);
	c.executeForm(*pardon);
	b.signForm(*pardon);
	c.signForm(*pardon);
	b.executeForm(*pardon);
	c.executeForm(*pardon);

	delete pardon;
}
