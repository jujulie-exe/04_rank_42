/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:53:31 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 15:57:02 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.Class.hpp"


int	main()
{
	Zombie* n = newZombie("Fread");
	n->announce();
	randomChump("Bob");
	delete n;
	Zombie *list = zombieHorde(5, "HUGO");
	list[0].announce();
	list[1].announce();
	list[2].announce();
	list[3].announce();
	list[4].announce();
	delete[] list;
}
