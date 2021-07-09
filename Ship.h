// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef SHIP
#define SHIP
#include "GameObject.h"

class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);
    void move(sf::Time dt);

private:
    void setMercuryPoints();
    sf::ConvexShape Body;
    float movementSpeed;
    sf::Vector2f movement;

};
#endif