/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:17 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:46:38 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

#define SIGN_P	25
#define EXEC_P	5

class	Bureaucrat;

class PresidentalPardonForm : public AForm
{
	public:

		PresidentalPardonForm( void );
		PresidentalPardonForm( std::string const & target );
		PresidentalPardonForm( PresidentalPardonForm const & inst );
		~PresidentalPardonForm( void );

		PresidentalPardonForm & operator=( PresidentalPardonForm const & rhs );

		virtual void	execute( Bureaucrat const & executor ) const;

};

#endif
