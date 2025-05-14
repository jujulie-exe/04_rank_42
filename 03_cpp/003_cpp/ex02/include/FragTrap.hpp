#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();	//cannon
		FragTrap(const std::string& name);
		FragTrap(FragTrap const & src);	//Cannon
//		void	highFiveGuys( void );
	void highFivesGuys(void);
		FragTrap& operator=(FragTrap const & rsh);	//Cannon
		virtual ~FragTrap();	//Cannon
	private:
};
#endif // FRAGTRAP_H

