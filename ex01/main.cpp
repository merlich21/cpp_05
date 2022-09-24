/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:56:58 by merlich           #+#    #+#             */
/*   Updated: 2022/08/27 23:40:16 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	Form	a;
	Form	b;
	Form	c("B52", 10, 15);
	Form	e1("B53", 1000, 15);
	Form	e2("B54", 10, 1500);
	Form	e3("B55", 0, 15);
	Form	e4("B56", 10, 0);
	Form	d(c);
	Bureaucrat al = Bureaucrat("Alex", 1);
	Bureaucrat max = Bureaucrat("Max", 150);


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << e1 << std::endl;
	std::cout << e2 << std::endl;
	std::cout << e3 << std::endl;
	std::cout << e4 << std::endl;
	std::cout << d << std::endl;
	
	b = c;
	std::cout << b << std::endl;

	// b.beSigned(al);
	// std::cout << b << std::endl;
	// c.beSigned(max);
	// std::cout << c << std::endl;

	/* Signing the form */

	std::cout << al << std::endl;
	std::cout << c << std::endl;
	al.signForm(c);
	std::cout << c << std::endl;
	
	std::cout << max << std::endl;
	std::cout << a << std::endl;
	max.signForm(a);
	std::cout << a << std::endl;

	/* The form is already signed! */

	std::cout << al << std::endl;
	std::cout << c << std::endl;
	al.signForm(c);
	std::cout << c << std::endl;

	std::cout << max << std::endl;
	std::cout << c << std::endl;
	max.signForm(c);
	std::cout << c << std::endl;

	return 0;
}
