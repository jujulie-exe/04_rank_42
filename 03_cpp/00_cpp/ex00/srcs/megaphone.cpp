/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:58:13 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/04 16:12:09 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define SPACE " "

int	main(int argc, char **argv)
{
	std::string out; 
	int	i = 0;
	int	y = 1;
	if (argc >= 2)
	{
		while (argv[y])
		{
			i = 0;
			while (argv[y][i])
			{
				char ch = toupper(argv[y][i]);
				std::cout << ch;
				i++;
			}
			std::cout << SPACE;
			y++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
