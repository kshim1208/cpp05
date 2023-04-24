#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", reqSignPresPardon, reqExecPresPardon)
{
	this->target_ = "randomTarget";
	std::cout << "PresidentialPardonForm - " << this->getName() << " has been created !!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", reqSignPresPardon, reqExecPresPardon)
{
	this->target_ = target;
	std::cout << "PresidentialPardonForm - " << this->getName() << " has been created !!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm - " << this->getName() << " has been destroyed....." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source): AForm(source.getName(), source.getReqSign(), source.getReqExec())
{
	this->setSign(source.getIsSigned());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	this->setSign(source.getIsSigned());
	return (*this);
}

void	PresidentialPardonForm::procedure(void) const
{
	std::cout << "PresidentialPardonForm - " << this->target_ << " has been pardoned by Zaphod Beeblebrox!!!!" << std::endl;
}