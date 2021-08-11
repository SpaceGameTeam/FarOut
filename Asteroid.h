#pragma once
// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef ASTD
#define ASTD
#include "FarOut/FarOut.h"
#include <math.h>

class Asteroid : public GameObject {
public:
    Asteroid();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    void update(sf::Time dt);
    //void move(sf::Time dt);

private:

    //in future: add argument to load different shape asteroids
    void setMercuryPoints();
    sf::ConvexShape Body;
    float movementSpeed;
    sf::Vector2f movement;
    
};
#endif