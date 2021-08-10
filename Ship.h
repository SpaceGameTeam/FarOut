// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef SHIP
#define SHIP
// #include "GameObject.h"
#include "FarOut.h"
#include <math.h>


const float SPEED = 363.0;

class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);
    //void move(sf::Time dt);

    // prototype collision methods
    float getRadius();
    void setPossibleCollision(bool possible);
    


private:
    void setMercuryPoints(sf::ConvexShape * shape);
    void setBlueShipPoints(sf::ConvexShape * shape);
    // sf::ConvexShape body;
	sf::VertexArray body; 
	sf::VertexArray thruster1; 
	sf::VertexArray thruster2; 
    sf::VertexArray flame1;
    sf::VertexArray flame2;
    float movementSpeed;
    bool accelerating;
    sf::Vector2f movement;

    // prototype collision data   
    float radius = 100.0;
    sf::CircleShape hitradius;
    bool possible_collision;
    int num_hitbox_points;
    sf::Vector2f* hitbox_points;
    sf::ConvexShape hitbox;
   

};
#endif