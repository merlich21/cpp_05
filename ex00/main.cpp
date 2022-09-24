/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:58 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 21:56:32 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	a;
	Bureaucrat	b("Alexander", 3);
	Bureaucrat	c(b);
	Bureaucrat	err1("Error", 0);
	Bureaucrat	err2("Error", 151);

	a = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << err1 << std::endl;
	std::cout << err2 << std::endl;

	a.setGrade(10);

	std::cout << a << std::endl;

	a.setGrade(0);

	std::cout << a << std::endl;
	
	a.setGrade(151);

	std::cout << a << std::endl;

	a.setGrade(2);
	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;

	a.setGrade(149);
	std::cout << a << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;

	return 0;	
}
