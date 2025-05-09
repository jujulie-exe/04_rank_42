/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:40:21 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/09 17:07:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"



int	main( void )
{
	ClapTrap Instance1("Carlye");
	Instance1.attack("POPO");
	Instance1.takeDamage(9);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.beRepaired(20);
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	Instance1.attack("POPO");
	ScavTrap	Instance2("Carlo");
	Instance2.beRepaired(100);
	Instance2.attack("POPO");
	Instance2.guardGate();
	Instance2.takeDamage(300000);
}
