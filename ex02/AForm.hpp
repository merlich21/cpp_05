/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:03:04 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:25:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{

	public:

		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExec );
		AForm( AForm const & inst );
		virtual ~AForm( void );

		AForm &	operator=( AForm const & rhs );

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
		std::string	getTarget( void ) const;

		void		setTarget( std::string const & target );
		void		setIsSigned( bool num );

		void			beSigned( Bureaucrat const & obj );
		virtual void	execute( Bureaucrat const & executor ) const = 0;

	private:

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
		std::string			_target;

};

std::ostream &	operator<<(std::ostream & o, AForm const & inst );

#endif
