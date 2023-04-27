#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", reqSignRobReq, reqExecRobReq)
{
	this->target_ = "randomTarget";
	std::cout << "RobotomyRequestForm - " << this->getName() << " has been created !!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", reqSignRobReq, reqExecRobReq)
{
	this->target_ = target;
	std::cout << "RobotomyRequestForm - " << this->getName() << " has been created !!!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm - " << this->getName() << " has been destroyed....." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source): AForm(source.getName(), source.getReqSign(), source.getReqExec())
{
	this->setSign(source.getIsSigned());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
	this->setSign(source.getIsSigned());
	return (*this);
}

void	RobotomyRequestForm::procedure(void) const
{
	std::cout << "RobotomyRequestForm - some drilling noises....." << std::endl;
	if (std::rand() % 2 == 1)
	{
		std::cout << "RobotomyRequestForm - " << this->target_ << " has been successfully robotomized!!!!!" << std::endl;
	}
	else
	{
		std::cout << "RobotomyRequestForm - robotomy procedure to " << this->target_ << " failed....." << std::endl;
	}
}
