/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:47:56 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 15:01:11 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/HumanB.Class.hpp"
#include "../include/HumanA.Class.hpp"
#include "../include/Weapon.Class.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	//Do not compile
//	Weapon test = NULL;
//	HumanA Hillow("Hillow", test);
	bob.attack();
	club.setType("SPADA");
	bob.attack();

	HumanB jim("Jim");
	jim.SetWeapon(club);
	jim.attack();
	club.setType("ARCO");
	jim.attack();
}
