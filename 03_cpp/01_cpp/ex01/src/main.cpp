/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:53:31 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/11 17:57:50 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.Class.hpp"


int	main()
{
	Zombie* n = n->newZombie("Fread");
	n->announce();
	randomChump("Tua madre");
	delete n;
	Zombie *list = zombieHorde(5, "HUGO");
	list[0].announce();
	list[4].announce();
	delete[] list;
}
