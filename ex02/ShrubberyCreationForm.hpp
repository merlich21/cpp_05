/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:23 by merlich           #+#    #+#             */
/*   Updated: 2022/08/28 22:46:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SIGN_S	145
#define EXEC_S	137

class	Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const & target );
		ShrubberyCreationForm( ShrubberyCreationForm const & inst );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

		virtual void	execute( Bureaucrat const & executor ) const;

};

#endif
