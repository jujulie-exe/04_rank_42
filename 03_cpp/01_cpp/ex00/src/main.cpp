/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:53:31 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 15:19:54 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.Class.hpp"


int	main()
{
	Zombie* n = newZombie("Fread");
	n->announce();
	randomChump("Bob");
	delete n;
}
