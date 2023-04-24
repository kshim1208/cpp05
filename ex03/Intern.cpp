#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern()
{
	std::cout << "Intern - intern has been created !!!" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern - intern has been destroyed....." << std::endl;
}

Intern::Intern(const Intern& source)
{
	Intern	tmp = source;
}

Intern& Intern::operator=(const Intern& source)
{
	Intern tmp = source;
	return (*this);
}

// new-expression에 의한 exception 존재함
	// catch 필요한가?
AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	FormArray[FormMaximum] = 	{"Shrubbery Creation",
											"Robotomy Request",
											"Presidential Pardon"};
	int iter = 0;
	AForm*	tmp;

	tmp = nullptr;
	while (iter < FormMaximum)
	{
		if (FormArray[iter] == name)
			break ;
		iter++;
	}
	try
	{
		switch (iter)
		{
			case SHRUBCREAT :
				tmp = new ShrubberyCreationForm(target);
				break ;
			case ROBREQ :
				tmp = new RobotomyRequestForm(target);
				break ;
			case PRESPARDON :
				tmp = new PresidentialPardonForm(target);
				break ;
			default:
				std::cerr << "Intern - " << name << " is unavailable Form name" << std::endl;
				return (tmp);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Intern - " << name << " has been failed to create form" << std::endl;
		return (tmp);
	}
	std::cout << "Intern - " << name << " Form has been created !!" << std::endl;
	return (tmp);
}
