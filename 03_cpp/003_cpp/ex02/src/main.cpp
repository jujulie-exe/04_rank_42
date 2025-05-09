/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:40:21 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/09 17:56:45 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"



int	main( void )
{
	ScavTrap	Instance2("Carlo");
	Instance2.beRepaired(100);
	Instance2.attack("POPO");
	Instance2.guardGate();
	Instance2.takeDamage(300000);
	FragTrap	Instance3("PIPO");
	Instance3.beRepaired(100);
}
