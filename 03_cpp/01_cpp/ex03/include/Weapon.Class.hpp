/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:50 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 14:41:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string	_WeaponType;
	public:
		Weapon(const std::string& stringREF);
		~Weapon();
		void	setType( const std::string& type);
		std::string	getType( void )	const;
};
#endif
