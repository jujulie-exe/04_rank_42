/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:39:47 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/29 15:07:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string& stringREF)
	: _WeaponType( stringREF )
{
		return ;
}

std::string	Weapon::getType( void ) const
{
	return (this->_WeaponType);
}

std::string	Weapon::setType(const std::string& type)
{
	_WeaponType = type;
}

Waepon::~Weapon()
{
	return ;
}
