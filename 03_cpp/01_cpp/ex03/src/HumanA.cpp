/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:55:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/29 16:01:55 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/HumanA.hpp"
#include "../include/Weapon.hpp"

HumanA::HumanA(const std::string& nameREF, Weapon& type)
	: _name( nameREF ), _type( type )
{
	return ; 
}

std::string	HumanA::getName( void ) const
{
	return (_name);
}

std::string	HumanA::attack( void ) const
{
	std::cout << get_name() << " " << _type->getType() << std::endl; 
}

HumanA::~HumanA()
{
	return ;
}
