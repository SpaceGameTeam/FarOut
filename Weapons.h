// Weapon related classes

#ifndef WEAPONS
#define WEAPONS

#include "FarOut/FarOut.h"



class Projectile : public GameObject {
public:
	Projectile();
	Projectile(unsigned int newMoveSpeed, sf::Time newLifetime);
	
	bool isAlive();
	virtual Projectile* newProjectile() = 0;

private:
	unsigned int moveSpeed;
	sf::Time lifetime;
	bool alive;
};



class Weapon : public GameObject {
public:
	Weapon(unsigned int newFireRate, std::shared_ptr<Projectile> newProjectileType);

private:
	unsigned int fireRate;
	std::shared_ptr<Projectile> projectileType;
	std::vector<Projectile*> liveProjectiles;
	std::vector<Projectile*>::iterator iter;
};

#endif // WEAPONS
