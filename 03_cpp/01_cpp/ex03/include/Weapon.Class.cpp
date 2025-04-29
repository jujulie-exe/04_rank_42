/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:50 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/16 15:09:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Weapon
{
	private:
		std::string	_WeaponType;
	public:
		Weapon(const std::string& stringREF);
		~Weapon();
		std::string	setType( const std::string& type);
		std::string	getType( void )	const;
};
