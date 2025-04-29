
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

class HumanB
{
	private:
		Weapon*	_type;
		std::string const	_name;
	public:
		HumanA();
		~HumanA();
		std::string	getName( void ) const;
		std::string	attack( void ) const;
		void	SetWeapon( std::string& const typeREF);
};
