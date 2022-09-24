/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:03:15 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 23:34:46 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructors and destructor */

Form::Form( void ) : _name("default"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form " << _name << " default constructor called" << std::endl;
}

Form::Form( std::string name, int gradeToSign, int gradeToExec ) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form " << _name << " custom constructor called" << std::endl;
	try
	{
		if (gradeToSign < 1 || gradeToExec < 1)
		{
			throw Form::GradeTooHighException("The value of grade is out of bounds [1, 150]!\n");
		}
		else if (gradeToSign > 150 || gradeToExec > 150)
		{
			throw Form::GradeTooLowException("The value of grade is out of bounds [1, 150]!\n");
		}
	}
	catch (Form::GradeTooHighException const & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException const & e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form( Form const & inst ) : _name(inst._name), _isSigned(inst._isSigned), _gradeToSign(inst._gradeToSign), _gradeToExec(inst._gradeToExec)
{
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
}

Form::~Form( void )
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

/* Operator "=" overloading */

Form &	Form::operator=( Form const & rhs )
{	
	this->_isSigned = rhs._isSigned;
	return *this;
}

/* GradeTooHighException constructors and destructor */

Form::GradeTooHighException::GradeTooHighException( void )
{
	// std::cout << "GradeTooHighException default constructor called" << std::endl;
}

Form::GradeTooHighException::GradeTooHighException( std::string const & msg ) : _msg(msg)
{
	// std::cout << "GradeTooHighException custom constructor called" << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	// std::cout << "GradeTooHighException destructor called" << std::endl;
}

/* GradeTooHighException member function */

char const * Form::GradeTooHighException::what( void ) const throw()
{
	return (this->_msg.c_str());
}

/* GradeTooLowException constructors and destructor */

Form::GradeTooLowException::GradeTooLowException( void )
{
	// std::cout << "GradeTooLowException default constructor called" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException( std::string const & msg ) : _msg(msg)
{
	// std::cout << "GradeTooLowException custom constructor called" << std::endl;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	// std::cout << "GradeTooLowException destructor called" << std::endl;
}

/* GradeTooLowException member function */

char const * Form::GradeTooLowException::what( void ) const throw()
{
	return (this->_msg.c_str());
}

/* Getters */

std::string	Form::getName( void ) const
{
	return this->_name;
}

bool	Form::getIsSigned( void ) const
{
	return this->_isSigned;
}

int	Form::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

int	Form::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

/* Member function */

void	Form::beSigned( Bureaucrat const & obj )
{
	if (obj.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException("\nthe grade of the bureaucrat is not enought to sign this form!\n");
	else if (this->_isSigned == 1)
		throw Form::GradeTooLowException("\nthe form is already signed!\n");
	else
		this->_isSigned = 1;
}

/* Operator "<<" overloading */

std::ostream &	operator<<(std::ostream & o, Form const & inst )
{
	o << "Name: " << inst.getName() << std::endl;
	o << "Grade to sign: " << inst.getGradeToSign() << std::endl;
	o << "Grade to execute: " << inst.getGradeToExec() << std::endl;
	o << "Status: " << inst.getIsSigned() << std::endl;
	return o;
}
