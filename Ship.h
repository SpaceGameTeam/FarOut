// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef SHIP
#define SHIP
#include "GameObject.h"
#include <math.h>


const float SPEED = 363.0;

class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);
    //void move(sf::Time dt);

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
    sf::Vector2f movement;
    sf::ConvexShape hitbox;
    bool accelerating;

};
#endif