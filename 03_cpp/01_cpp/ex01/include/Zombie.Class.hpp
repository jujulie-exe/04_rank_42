/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:11:59 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/02 15:54:44 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP
#include <iomanip>
#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie();	//costruttere vuoto
	

		//void		randomChump( std::string name );
		std::string	get_name( void ) const;
		std::string	get_sound( void ) const;
		void		announce( void ) const;
		void		set_name( std::string name );

		~Zombie( void );
	private: 
		Zombie(const std::string& _name); //costruttore con parametri privato
					    //
		std::string	_sound;
		std::string	_name;
};

		void		randomChump( std::string name );
		Zombie*		newZombie(std::string name);
		Zombie*		zombieHorde(size_t i, std::string name);
#endif
