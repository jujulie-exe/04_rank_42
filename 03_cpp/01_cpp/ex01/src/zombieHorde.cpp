/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:13:39 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/11 17:56:22 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.Class.hpp"

Zombie*	zombieHorde(size_t i, std::string name)
{
	Zombie* nZombie = new Zombie[i];
	i--;
	while (i != -1)
	{
		nZombie[i].set_name(name);
		i--;
	}
	return nZombie;
}
