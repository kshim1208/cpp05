#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm():name_("randomAForm"), isSigned_(false), reqGradeToSign_(150), reqGradeToExec_(150)
{
	std::cout << "AForm - " << this->name_ << " has been created !!!" << std::endl;
}

AForm::AForm(std::string name):name_(name), isSigned_(false), reqGradeToSign_(150), reqGradeToExec_(150)
{
	std::cout << "AForm - " << this->name_ << " has been created !!!" << std::endl;
}

AForm::AForm(int sign, int exec):name_("randomAForm"), isSigned_(false), reqGradeToSign_(sign), reqGradeToExec_(exec)
{
	std::cout << "AForm - " << this->name_ << " has been created !!!" << std::endl;
}

AForm::AForm(std::string name, int sign):name_(name), isSigned_(false), reqGradeToSign_(sign), reqGradeToExec_(150)
{
	std::cout << "AForm - " << this->name_ << " has been created !!!" << std::endl;
}

AForm::AForm(std::string name, int sign, int exec):name_(name), isSigned_(false), reqGradeToSign_(sign), reqGradeToExec_(exec)
{
	std::cout << "AForm - " << this->name_ << " has been created !!!" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm - " << this->name_ << " has been destroyed....." << std::endl;
}

AForm::AForm(const AForm& source):name_(source.name_), isSigned_(source.isSigned_), reqGradeToSign_(source.reqGradeToSign_), reqGradeToExec_(source.reqGradeToExec_){}

AForm& AForm::operator=(const AForm& source)
{
	this->isSigned_ = source.isSigned_;
	return (*this);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("it already signed!");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("it is not signed!");
}

const std::string&	AForm::getName(void) const
{
	return (this->name_);
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned_);
}

int	AForm::getReqSign(void) const
{
	return (this->reqGradeToSign_);
}

int	AForm::getReqExec(void) const
{
	return (this->reqGradeToExec_);
}

bool	AForm::beSigned(Bureaucrat &buro)
{
	std::cout << "is " << buro.getName() << " trying to sign the " << this->getName() << "...." << std::endl;
	try
	{
		if (this->reqGradeToSign_ < buro.getGrade())
			throw AForm::GradeTooLowException();
		if (this->getIsSigned() == true)
			throw AForm::AlreadySignedException();
	}
	catch (const std::exception& e)
	{
		throw ;
	}
	this->setSign(true);
	return (true);
}

void	AForm::setSign(bool status)
{
	this->isSigned_ = status;
}

bool	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == true)
	{
		if (this->getReqExec() >= executor.getGrade())
			this->procedure();
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
	return (true);
}

std::ostream& operator<<(std::ostream &output, const AForm &source)
{
	output << "Form " << source.getName() << " is currently ";
	if (source.getIsSigned() == true)
		output << "signed, ";
	else
		output << "NOT signed, ";
	output << "require " << source.getReqSign() << " to be signed, require " << source.getReqExec() << " to be executed";
	return (output);
}
