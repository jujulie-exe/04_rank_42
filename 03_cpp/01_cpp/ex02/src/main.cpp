/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:36 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/16 13:29:53 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <ostream>


int	main(int argc, char **argv)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	// stampo tutti gli indirizzi di memoria
	std::cout << &str << " ADDRESS THE STR " << std::endl;
	std::cout << stringPTR << " ADDRESS THE strPTR " << std::endl;
	std::cout << &stringREF << " ADDRESS THE &strREF " << std::endl;
	std::cout << &stringPTR << " ADDRESS THE &strPTR " << std::endl;
	if (&str == stringPTR && &str == &stringREF)
		std::cout << "ADRESS &STR & strPTR & strREF are same " << &str << std::endl;
	// stampa i valori
	std::cout << str << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << std::endl;
	return (0);
}

