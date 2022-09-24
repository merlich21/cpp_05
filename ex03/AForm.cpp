/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:03:15 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:49:13 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Constructors and destructor */

AForm::AForm( void ) : _name("default"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm " << _name << " default constructor called" << std::endl;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExec ) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm " << _name << " custom constructor called" << std::endl;
	try
	{
		if (gradeToSign < 1 || gradeToExec < 1)
		{
			throw AForm::GradeTooHighException("The value of grade is out of bounds [1, 150]!\n");
		}
		else if (gradeToSign > 150 || gradeToExec > 150)
		{
			throw AForm::GradeTooLowException("The value of grade is out of bounds [1, 150]!\n");
		}
	}
	catch (AForm::GradeTooHighException const & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm( AForm const & inst ) : _name(inst._name), _isSigned(inst._isSigned), _gradeToSign(inst._gradeToSign), _gradeToExec(inst._gradeToExec), _target(inst._target)
{
	std::cout << "AForm " << _name << " copy constructor called" << std::endl;
}

AForm::~AForm( void )
{
	std::cout << "AForm " << _name << " destructor called" << std::endl;
}

/* Operator "=" overloading */

AForm &	AForm::operator=( AForm const & rhs )
{	
	this->_isSigned = rhs._isSigned;
	this->_target = rhs._target;
	return *this;
}

/* GradeTooHighException constructors and destructor */

AForm::GradeTooHighException::GradeTooHighException( void )
{
	// std::cout << "GradeTooHighException default constructor called" << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException( std::string const & msg ) : _msg(msg)
{
	// std::cout << "GradeTooHighException custom constructor called" << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	// std::cout << "GradeTooHighException destructor called" << std::endl;
}

/* GradeTooHighException member function */

char const * AForm::GradeTooHighException::what( void ) const throw()
{
	return (this->_msg.c_str());
}

/* GradeTooLowException constructors and destructor */

AForm::GradeTooLowException::GradeTooLowException( void )
{
	// std::cout << "GradeTooLowException default constructor called" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException( std::string const & msg ) : _msg(msg)
{
	// std::cout << "GradeTooLowException custom constructor called" << std::endl;
}

AForm::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	// std::cout << "GradeTooLowException destructor called" << std::endl;
}

/* GradeTooLowException member function */

char const * AForm::GradeTooLowException::what( void ) const throw()
{
	return (this->_msg.c_str());
}

/* Getters and setter */

std::string	AForm::getName( void ) const
{
	return this->_name;
}

bool	AForm::getIsSigned( void ) const
{
	return this->_isSigned;
}

int	AForm::getGradeToSign( void ) const
{
	return this->_gradeToSign;
}

int	AForm::getGradeToExec( void ) const
{
	return this->_gradeToExec;
}

std::string	AForm::getTarget( void ) const
{
	return this->_target;
}

void	AForm::setTarget( std::string const & target )
{
	this->_target = target;
}

void	AForm::setIsSigned( bool num )
{
	this->_isSigned = num;
}

/* Member function */

void	AForm::beSigned( Bureaucrat const & obj )
{
	if (obj.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException("\nthe grade of the bureaucrat is not enought to sign this form!\n");
	else if (this->_isSigned == 1)
		throw AForm::GradeTooLowException("\nthe form is already signed!\n");
	else if (this->getTarget().empty())
		throw AForm::GradeTooLowException("\nthe target is not specified!\n");
	else
		this->_isSigned = 1;
}

/* Operator "<<" overloading */

std::ostream &	operator<<(std::ostream & o, AForm const & inst )
{
	o << "---------------------------------------" << std::endl;
	o << "Name: " << inst.getName() << std::endl;
	o << "Target: " << inst.getTarget() << std::endl;
	o << "Grade to sign: " << inst.getGradeToSign() << std::endl;
	o << "Grade to execute: " << inst.getGradeToExec() << std::endl;
	o << "Status: " << inst.getIsSigned() << std::endl;
	o << "---------------------------------------" << std::endl;
	return o;
}
