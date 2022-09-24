/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:19 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:51:58 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructors and destructor */

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", SIGN_R, EXEC_R)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : AForm("RobotomyRequestForm", SIGN_R, EXEC_R)
{
	this->setTarget(target);
	std::cout << "RobotomyRequestForm custom constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & inst ) : AForm(inst)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/* Overload of the operator "=" */

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->setTarget(rhs.getTarget());
	this->setIsSigned(rhs.getIsSigned());
	return *this;
}

/* Member functions */

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	int	r = 0;

	if (!this->getIsSigned())
		throw AForm::GradeTooLowException("The form is not signed!");
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("The grade of the executor is not enough to execute this form!");
	else
	{
		std::cout << "*** DRILLING NOISES ***" << std::endl;
		r = rand() % 2;
		if (r)
			std::cout << this->getTarget() << " has been robotomized successefully!" << std::endl;
		else
			std::cout << "The " << this->getTarget() << "`s robotomy failed!" << std::endl;
	}
}
