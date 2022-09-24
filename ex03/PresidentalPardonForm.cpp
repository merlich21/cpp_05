/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:14 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:52:04 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"

/* Constructors and destructor */

PresidentalPardonForm::PresidentalPardonForm( void ) : AForm("PresidentalPardonForm", SIGN_P, EXEC_P)
{
	std::cout << "PresidentalPardonForm default constructor called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm( std::string const & target ) : AForm("PresidentalPardonForm", SIGN_P, EXEC_P)
{
	this->setTarget(target);
	std::cout << "PresidentalPardonForm custom constructor called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm( PresidentalPardonForm const & inst ) : AForm(inst)
{
	std::cout << "PresidentalPardonForm copy constructor called" << std::endl;
}

PresidentalPardonForm::~PresidentalPardonForm( void )
{
	std::cout << "PresidentalPardonForm destructor called" << std::endl;
}

/* Overload of the operator "=" */

PresidentalPardonForm & PresidentalPardonForm::operator=( PresidentalPardonForm const & rhs )
{
	this->setTarget(rhs.getTarget());
	this->setIsSigned(rhs.getIsSigned());
	return *this;
}

void	PresidentalPardonForm::execute( Bureaucrat const & executor ) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException("The form is not signed!");
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("The grade of the executor is not enough to execute this form!");
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
}
