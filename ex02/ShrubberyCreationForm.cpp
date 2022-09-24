/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:22 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:51:51 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Constructors and destructor */

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", SIGN_S, EXEC_S)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : AForm("ShrubberyCreationForm", SIGN_S, EXEC_S)
{
	this->setTarget(target);
	std::cout << "ShrubberyCreationForm custom constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & inst ) : AForm(inst)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/* Overload of the operator "=" */

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->setTarget(rhs.getTarget());
	this->setIsSigned(rhs.getIsSigned());
	return *this;
}

/* Member functions */

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	std::ofstream ofs;

	if (!this->getIsSigned())
		throw AForm::GradeTooLowException("The form is not signed!");
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("The grade of the executor is not enough to execute this form!");
	else
	{
		ofs.open(this->getTarget() + "_shrubbery");
		ofs << "            &&& &&  & && \n";
		ofs << "        && &\\/&\\|& ()|/ @, && \n";
		ofs << "        &\\/(/&/&||/& /_/)_&/_& \n";
		ofs << "    &() &\\/&|()|/&\\/ '%\" & () \n";
		ofs << "    &_\\_&&_\\ |& |&&/&__%_/_& && \n";
		ofs << "    &&   && & &| &| /& & % ()& /&& \n";
		ofs << "    ()&_---()&\\&\\|&&-&&--%---()~ \n";
		ofs << "        &&     \\|||\n";
		ofs << "                |||\n";
		ofs << "                |||\n";
		ofs << "                |||\n";
		ofs << "        , -=-~  .-^- _\n";
		ofs << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		ofs.close();
		std::cout << "File " << this->getTarget() << "_shrubbery has been created!" << std::endl;
	}
}
