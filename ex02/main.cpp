/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:58 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:54:30 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int	main(void)
{
	Bureaucrat	alex("Alexander", 1);
	Bureaucrat	max("Max", 150);
	Bureaucrat	dm("Dmitriy", 140);
	Bureaucrat	ncl("Nicolas", 72);
	Bureaucrat	mcl("Michael", 25);

	ShrubberyCreationForm	f1("Home");
	// RobotomyRequestForm		f1("Jules");
	// PresidentalPardonForm	f1("Ben");

	RobotomyRequestForm		f3("Jules");
	PresidentalPardonForm	f2("Ben");
	ShrubberyCreationForm	f4;

	ShrubberyCreationForm	f5;
	ShrubberyCreationForm	f6(f1);

	// RobotomyRequestForm	f5;
	// RobotomyRequestForm	f6(f1);

	// PresidentalPardonForm	f5;
	// PresidentalPardonForm	f6(f1);

	/* Canonical tests */

	std::cout << f1 << std::endl;
	std::cout << f5 << std::endl;
	std::cout << f6 << std::endl;

	alex.signForm(f1);
	std::cout << f1 << std::endl;
	f5 = f1;

	std::cout << f5 << std::endl;
	
	ShrubberyCreationForm	f7(f1);
	// RobotomyRequestForm		f7(f1);
	// PresidentalPardonForm	f7(f1);
	std::cout << f1 << std::endl;
	std::cout << f1.getTarget() << std::endl;

	/* Form is not signed case */

	alex.executeForm(f1);
	alex.executeForm(f2);
	alex.executeForm(f3);

	max.executeForm(f1);
	max.executeForm(f2);
	max.executeForm(f3);

	/* Target is not specified case */

	alex.signForm(f4);
	alex.executeForm(f4);

	/* ShrubberyCreationForm tests */

	std::cout << f1 << std::endl;
	std::cout << max << std::endl;
	max.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << dm << std::endl;
	dm.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << dm << std::endl;
	dm.executeForm(f1);
	std::cout << ncl << std::endl;
	ncl.executeForm(f1);

	/* RobotomyRequestForm tests */

	std::cout << f3 << std::endl;
	std::cout << dm << std::endl;
	dm.signForm(f3);
	std::cout << f3 << std::endl;

	std::cout << ncl << std::endl;
	ncl.signForm(f3);
	std::cout << f3 << std::endl;

	std::cout << ncl << std::endl;
	ncl.executeForm(f3);
	std::cout << mcl << std::endl;
	mcl.executeForm(f3);

	/* PresidentalPardonForm tests */

	std::cout << f2 << std::endl;
	std::cout << ncl << std::endl;
	ncl.signForm(f2);
	std::cout << f2 << std::endl;

	std::cout << mcl << std::endl;
	mcl.signForm(f2);
	std::cout << f2 << std::endl;

	std::cout << mcl << std::endl;
	mcl.executeForm(f2);
	std::cout << alex << std::endl;
	alex.executeForm(f2);

	/* Execute form 3 (or more) times */

	std::cout << alex << std::endl;
	alex.executeForm(f1);
	alex.executeForm(f1);
	alex.executeForm(f1);

	alex.executeForm(f2);
	alex.executeForm(f2);
	alex.executeForm(f2);

	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);
	alex.executeForm(f3);


	ShrubberyCreationForm	a1;
	PresidentalPardonForm	b1;
	RobotomyRequestForm		c1;

	alex.executeForm(a1);
	alex.executeForm(b1);
	alex.executeForm(c1);

	alex.signForm(a1);
	alex.signForm(b1);
	alex.signForm(c1);

	alex.executeForm(a1);
	alex.executeForm(b1);
	alex.executeForm(c1);

	return 0;
}
