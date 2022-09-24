/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:20 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:46:23 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define SIGN_R	72
#define EXEC_R	45

class	Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & inst );
		~RobotomyRequestForm( void );

		RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

		virtual void	execute( Bureaucrat const & executor ) const;

};

#endif
