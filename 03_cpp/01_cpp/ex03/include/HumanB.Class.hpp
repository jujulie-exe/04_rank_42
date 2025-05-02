
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:19:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/29 15:22:00 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP
#include "Weapon.Class.hpp"
class HumanB
{
	private:
		std::string const	_name;
		Weapon*	_type;
	public:
		HumanB(const std::string& nameREF);
		~HumanB();
		std::string	getName( void ) const;
		void	attack( void ) const;
		void	SetWeapon( Weapon &typeREF);
};
#endif
