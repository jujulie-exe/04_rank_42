/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:19:29 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 16:09:35 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP
#include "Weapon.Class.hpp"

class HumanA
{
	private:
		std::string const	_name;
		Weapon&	_type;
	public:
		//HumanA();
		HumanA(const std::string& nameREF, Weapon& type);
		~HumanA();
		std::string	getName( void ) const;
		void	attack( void ) const;
		//Weapon	*SetWeapon( std::string& const typeREF);
};
#endif
