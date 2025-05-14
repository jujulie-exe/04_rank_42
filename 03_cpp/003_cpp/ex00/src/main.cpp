/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:40:21 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/12 18:13:34 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

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
	ClapTrap	instance2(Instance1);
	instance2.beRepaired( 9 );
}
