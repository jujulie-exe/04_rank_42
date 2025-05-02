/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:55:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 14:46:24 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Weapon.Class.hpp"
#include "../include/HumanB.Class.hpp"

HumanB::HumanB(const std::string& nameREF)
	: _name( nameREF ), _type ( NULL )
{
	return ; 
}

std::string	HumanB::getName( void ) const
{
	return (_name);
}



void	HumanB::attack( void ) const
{
	if (_type)
		std::cout << getName() << " " << _type->getType() << std::endl; 
}


void		HumanB::SetWeapon(Weapon &typePTR)
{
	this->_type = &typePTR;
}

HumanB::~HumanB()
{
	return ; 
}
