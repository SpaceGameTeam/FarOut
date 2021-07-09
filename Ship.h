#pragma once

#include <SFML/Graphics.hpp>
// Change this #include to FarOut.h eventually
// #include "FarOut.h"
#include "GameObject.h"
// Would like to include math.h in GameObject.h 
#include <math.h>

#ifndef SHIP
#define SHIP
class GameObject;

class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);

private:
    sf::ConvexShape Body;
    float movementSpeed;

};
#endif