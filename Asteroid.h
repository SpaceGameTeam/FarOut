#pragma once
// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef ASTD
#define ASTD
#include "GameObject.h"
#include <math.h>

class Asteroid : public GameObject {
public:
    Asteroid();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    void update(sf::Time dt);
    void move(sf::Time dt);
    void setHitboxPoints();
   
    // prototype collision methods
    float getRadius();
    void setPossibleCollision(bool possible);
    void setCollision(bool was_collision);

private:

    //in future: add argument to load different shape asteroids
    void setMercuryPoints();
    sf::ConvexShape Body;
    sf::ConvexShape hitbox;
    float movementSpeed;
    sf::Vector2f movement;

    float radius = 30;
    sf::CircleShape hitradius;
    bool possible_collision;
    bool collision;
    
};
#endif