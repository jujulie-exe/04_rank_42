#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"
 
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();	//cannon
		ScavTrap(const std::string& name);
		ScavTrap(ScavTrap const & src);	//Cannon
		
		void	attack(const std::string& target);
		void	guardGate();

		ScavTrap& operator=(ScavTrap const & rsh);	//Cannon
		
		virtual ~ScavTrap();	//Cannon
	private:
};
#endif // SCAVTRAP_H

