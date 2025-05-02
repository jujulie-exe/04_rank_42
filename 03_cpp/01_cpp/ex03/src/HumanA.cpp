/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:55:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 14:59:47 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Weapon.Class.hpp"
#include "../include/HumanA.Class.hpp"

HumanA::HumanA(const std::string& nameREF, Weapon& type)
	: _name( nameREF ), _type( type )
{
	return ; 
}

std::string	HumanA::getName( void ) const
{
	return (_name);
}

void	HumanA::attack( void ) const
{
	std::cout << getName() << " " << _type.getType() << std::endl; 
}

HumanA::~HumanA()
{
	return ;
}
