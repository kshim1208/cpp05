#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	Bureaucrat	a;
	Bureaucrat	b("Buro_B");
	Bureaucrat	c("Buro_C", 1);
	Bureaucrat	d("Buro_D", 0);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	c.gradeDecrement(1);
	std::cout << c << std::endl;

	c.gradeIncrement(-2);
	std::cout << c << std::endl;

	c.gradeDecrement(149);
	std::cout << c << std::endl;

	c.gradeIncrement(150);
	std::cout << c << std::endl;

	c.gradeDecrement(200);
	std::cout << c << std::endl;

	c.gradeDecrement(-200);
	std::cout << c << std::endl;

	c.gradeDecrement(-150);
	std::cout << c << std::endl;
}
