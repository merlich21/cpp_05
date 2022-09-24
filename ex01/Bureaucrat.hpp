/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:47:48 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 21:39:30 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{

	public:

		Bureaucrat( void );
		Bureaucrat( Bureaucrat const & inst );
		Bureaucrat( std::string name, int grade );
		~Bureaucrat( void );

		Bureaucrat	& operator=( Bureaucrat const & rhs );

		std::string	getName( void ) const;

		int		getGrade( void ) const;
		void	setGrade( int const grade );

		void	incrementGrade( void );
		void	decrementGrade( void );

		class	GradeTooHighException : public std::exception
		{
			public:

				virtual const char	*what( void ) const throw();

		};

		class	GradeTooLowException : public std::exception
		{
			public:

				virtual const char	*what( void ) const throw();

		};

		void	signForm( Form & form );

	private:

		const std::string	_name;
		int					_grade;

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
