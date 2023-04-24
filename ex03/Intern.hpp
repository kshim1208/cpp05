#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "AForm.hpp"

# define FormMaximum 3

enum	FormEnum
{
	SHRUBCREAT = 0,
	ROBREQ,
	PRESPARDON
};

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern& source);
		Intern& operator=(const Intern& source);

		AForm*	makeForm(std::string name, std::string target);
};

#endif