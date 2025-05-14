/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:40:21 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/14 12:14:46 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"



int	main( void )
{
	ClapTrap Instance1("Carlye");
	ScavTrap	Instance2("Carlo");
	Instance2.beRepaired(100);
	Instance2.takeDamage(300000);
	ScavTrap	Instance3(Instance2);
	Instance3.attack("POPO");
	Instance2.guardGate();
}
