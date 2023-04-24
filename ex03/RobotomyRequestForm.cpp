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

// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
void	RobotomyRequestForm::procedure(void) const
{
	std::random_device	rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	std::cout << "RobotomyRequestForm - some drilling noises....." << std::endl;
	if (dis(gen) == 1)
	{
		std::cout << "RobotomyRequestForm - " << this->target_ << " has been successfully robotomized!!!!!" << std::endl;
	}
	else
	{
		std::cout << "RobotomyRequestForm - robotomy procedure to " << this->target_ << " failed....." << std::endl;
	}
}
