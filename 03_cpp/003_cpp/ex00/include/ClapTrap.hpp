#ifndef CLAPTRAP_H
#define CLAPTRAP_H
 
class ClapTrap
{
	public:
		// COSTRUTTORI
		ClapTrap();	//cannon
		ClapTrap(const std::string& name);
		ClapTrap(ClapTrap const & src);	//Cannon

		// OPERATOR
		ClapTrap& operator=(ClapTrap const & rsh);	//Cannon

		// FUNZIONI
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		// DECOSTRUTTORI
		virtual ~ClapTrap()	//Cannon

	private:
			const std::string	_name;
			int					_healthPoint;
			int					_AttackPoint;
			int					_Stamina;
};
#endif // CLAPTRAP_H

