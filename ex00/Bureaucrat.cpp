/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:51 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 21:38:46 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & inst ) : _name(inst._name)
{
	std::cout << "Bureaucrat " << _name << " copy constructor called" << std::endl;
	*this = inst;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " custom constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

Bureaucrat	& Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs._grade;
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int		Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::setGrade( int const grade )
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::incrementGrade( void )
{
	try
	{
		if (this->_grade < 2)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade( void )
{
	try
	{
		if (this->_grade > 149)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char	* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Error!\nThe grade is too high!\n");
}

const char	* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Error!\nThe grade is too low!\n");
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}
