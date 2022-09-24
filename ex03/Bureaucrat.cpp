/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:51 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:02:02 by merlich          ###   ########.fr       */
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

void	Bureaucrat::signForm( AForm & form )
{
	try
	{
		std::cout << "____________________________________________" << std::endl;
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		std::cout << "____________________________________________" << std::endl;
		std::cout << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << this->_name << " couldn`t sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		std::cout << "____________________________________________" << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		std::cout << "____________________________________________" << std::endl;
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		std::cout << "____________________________________________" << std::endl;
		std::cout << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << this->_name << " couldn`t execute " << form.getName() << " because " << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "____________________________________________" << std::endl;
	}
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << "***************************************" << std::endl;
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	o << "***************************************" << std::endl;
	return o;
}