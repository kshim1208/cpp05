#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name_("Buro")
{
	this->grade_ = 150;
	std::cout << "Bureaucrat - " << this->name_ << " has been created !!!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name_(name)
{
	this->grade_ = 150;
	std::cout << "Bureaucrat - " << this->name_ << " has been created !!!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	try
	{
		if (grade > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else if (grade < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		this->grade_ = 150;
	}
	std::cout << "Bureaucrat - " << this->name_ << " has been created !!!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat - " << this->name_ << " has been destroyed....." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source)
{
	this->grade_ = source.grade_;
	std::cout << "Bureaucrat - " << this->name_ << " has been copy-created !!!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source)
{
	this->grade_ = source.grade_;
	std::cout << "Bureaucrat - " << this->name_ << " has been copy-operator-created !!!" << std::endl;
	return (*this);
}

const char*	Bureaucrat::ChangeTooMuchException::what() const throw()
{
	return ("grade changed too much, change reverted");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

void	Bureaucrat::gradeIncrement(int change)
{
	try
	{
		if (change >= 150 || change <= -150)
			throw Bureaucrat::ChangeTooMuchException();
		if (this->grade_ + change < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	this->grade_ -= change;
}

void	Bureaucrat::gradeDecrement(int change)
{
	try
	{
		if (change >= 150 || change <= -150)
			throw Bureaucrat::ChangeTooMuchException();
		if (this->grade_ + change > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	this->grade_ += change;
}

std::ostream& operator<<(std::ostream &output, const Bureaucrat &source)
{
	output << source.getName() << ", bureaucrat grade " << source.getGrade();
	return (output);
}
