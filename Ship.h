#pragma once

// Change this #include to FarOut.h eventually
// #include "FarOut.h"
// Would like to include math.h in SystemClass.h 
// #include <math.h>

// #ifndef SHIP
// #define SHIP
#include "GameObject.h"

class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);
    void move(sf::Time dt);

private:
    sf::ConvexShape Body;
    float movementSpeed;
    sf::Vector2f movement;

};
// #endif