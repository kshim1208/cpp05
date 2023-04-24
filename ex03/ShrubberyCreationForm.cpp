#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", reqSignShubCreat, reqExecShubCreat)
{
	this->target_ = "randomTarget";
	std::cout << "ShrubberyCreationForm - " << this->getName() << " has been created !!!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", reqSignShubCreat, reqExecShubCreat)
{
	this->target_ = target;
	std::cout << "ShrubberyCreationForm - " << this->getName() << " has been created !!!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm - " << this->getName() << " has been destroyed....." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source): AForm(source.getName(), source.getReqSign(), source.getReqExec())
{
	this->setSign(source.getIsSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	this->setSign(source.getIsSigned());
	return (*this);
}

void	ShrubberyCreationForm::procedure(void) const
{
	std::fstream	file;

	file.open(this->target_, std::fstream::trunc | std::fstream::out);
	if (file.is_open() == false)
	{
		std::cerr << "ShrubberyCreationForm - file creation failed" << std::endl;
		return ;
	}
	try
	{
		for (int iter = 0; iter < 10; iter++)
		{
			file.write("          /\\          \n", 23);
			file.write("         /  \\         \n", 23);
			file.write("        /    \\        \n", 23);
			file.write("       /      \\       \n", 23);
			file.write("      /        \\      \n", 23);
			file.write("     /          \\     \n", 23);
			file.write("    /            \\    \n", 23);
			file.write("   ----------------   \n", 23);
			file.write("        /     \\       \n", 23);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	file.close();
	return ;
}
