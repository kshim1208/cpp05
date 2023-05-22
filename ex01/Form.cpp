#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form():name_("randomForm"), isSigned_(false), reqGradeToSign_(150), reqGradeToExec_(150)
{
	std::cout << "Form - " << this->name_ << " has been created !!!" << std::endl;
}

Form::Form(std::string name):name_(name), isSigned_(false), reqGradeToSign_(150), reqGradeToExec_(150)
{
	std::cout << "Form - " << this->name_ << " has been created !!!" << std::endl;
}

Form::Form(std::string name, int sign):name_(name), isSigned_(false), reqGradeToSign_(sign), reqGradeToExec_(150)
{
	std::cout << "Form - " << this->name_ << " has been created !!!" << std::endl;
}

Form::Form(std::string name, int sign, int exec):name_(name), isSigned_(false), reqGradeToSign_(sign), reqGradeToExec_(exec)
{
	std::cout << "Form - " << this->name_ << " has been created !!!" << std::endl;
}

Form::~Form()
{
	std::cout << "Form - " << this->name_ << " has been destroyed....." << std::endl;
}

Form::Form(const Form& source):name_(source.name_), isSigned_(source.isSigned_), reqGradeToSign_(source.reqGradeToSign_), reqGradeToExec_(source.reqGradeToExec_){}

Form& Form::operator=(const Form& source)
{
	this->isSigned_ = source.isSigned_;
	return (*this);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("form already signed!");
}

const std::string&	Form::getName(void) const
{
	return (this->name_);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned_);
}

int	Form::getReqSign(void) const
{
	return (this->reqGradeToSign_);
}

int	Form::getReqExec(void) const
{
	return(this->reqGradeToExec_);
}

bool	Form::beSigned(Bureaucrat &buro)
{
	std::cout << "is " << buro.getName() << " trying to sign the form...." << std::endl;
	if (this->reqGradeToSign_ < buro.getGrade())
		throw Form::GradeTooLowException();
	if (this->getIsSigned() == true)
		throw Form::AlreadySignedException();
	this->isSigned_ = true;
	return (true);
}

std::ostream& operator<<(std::ostream &output, const Form &source)
{
	output << "Form " << source.getName() << " is currently ";
	if (source.getIsSigned() == true)
		output << "signed, ";
	else
		output << "NOT signed, ";
	output << "require " << source.getReqSign() << " to be signed, require " << source.getReqExec() << " to be executed";
	return (output);
}