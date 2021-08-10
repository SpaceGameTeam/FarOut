#pragma once
// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef ASTD
#define ASTD
// #include "GameObject.h"
#include "FarOut.h"
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
   

    

private:

    //in future: add argument to load different shape asteroids
    void setMercuryPoints();
    sf::ConvexShape Body;
    float movementSpeed;
    sf::Vector2f movement;


    // protoype collision data
    float radius = 30;
    sf::CircleShape hitradius;
    bool possible_collision;
    sf::ConvexShape hitbox;
    int num_hitbox_points;
    sf::Vector2f* hitbox_points;
   
};
#endif