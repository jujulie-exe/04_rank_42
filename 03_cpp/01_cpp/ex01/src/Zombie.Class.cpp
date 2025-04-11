/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:23:31 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/11 17:08:36 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.Class.hpp"

Zombie::Zombie(const std::string& pname) 
	: _sound( "BraiiiiiiinnnzzzZ..."), _name (pname) {
}

Zombie::Zombie() 
	: _sound( "BraiiiiiiinnnzzzZ..."), _name ("") {
}

std::string	Zombie::get_name( void ) const
{
	return _name;
}

std::string	Zombie::get_sound( void ) const
{
	return _sound;
}


void	Zombie::set_name( std::string name)
{
	this->_name = name;
}

void	Zombie::announce( void ) const
{
	std::cout << get_name() <<  ": " << get_sound() << std::endl;
}


Zombie::~Zombie( void )
{
	std::cout << get_name() << ": Destrutcion" << std::endl;
	return ;
}
