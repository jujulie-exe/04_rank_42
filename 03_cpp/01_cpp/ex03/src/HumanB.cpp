/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:55:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/29 16:20:56 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"

HumanA::HumanB(const std::string& nameREF)
	: _name( nameREF )
{
	return ; 
}

std::string	HumanB::getName( void ) const
{
	return (_name);
}



std::string	HumanB::attack( void ) const
{
	if (_type)
		std::cout << get_name() << " " << _type->getType() << std::endl; 
}


void		HumanB::SetWeapon(Weapon &typePTR)
{
	this->_type = &typePTR;
}

HumanB::~HumanB()
{
	return ; 
}
