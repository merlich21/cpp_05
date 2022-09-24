/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:03:04 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 22:17:16 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{

	public:

		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExec );
		Form( Form const & inst );
		~Form( void );

		Form &	operator=( Form const & rhs );

		class	GradeTooHighException
		{
			private:

				std::string	_msg;
				
			public:
			
				GradeTooHighException( void );
				GradeTooHighException( std::string const & msg );
				virtual ~GradeTooHighException( void ) throw();
				virtual char const *what( void ) const throw();
		};

		class	GradeTooLowException
		{
			private:

				std::string	_msg;
				
			public:
			
				GradeTooLowException( void );
				GradeTooLowException( std::string const & msg );
				virtual ~GradeTooLowException( void ) throw();
				virtual char const *what( void ) const throw();
		};

		std::string	getName( void ) const;
		bool		getIsSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void	beSigned( Bureaucrat const & obj );

	private:

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream &	operator<<(std::ostream & o, Form const & inst );

#endif
