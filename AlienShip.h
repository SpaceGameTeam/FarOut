// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef ALIENSHIP
#define ALIENSHIP
#include "GameObject.h"
#include <math.h>


const int NUMPOINTS = 30;
const sf::Vector2f DOMERADIUS(50.f, 20.f);


// Ellipse class modeled after https://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
class EllipseShape : public sf:: Shape {
    public :
        explicit EllipseShape(const sf::Vector2f& radius);
        void setRadius(const sf::Vector2f& radius);
        const sf::Vector2f& getRadius() const;
        virtual std::size_t getPointCount() const;
        virtual sf::Vector2f getPoint(std::size_t index) const;

    private :
        sf::Vector2f m_radius;
        int pointCount;
};



class AlienShip : public GameObject {
public:
	AlienShip();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt, sf::Vector2f shipPosition);
	void update(sf::Time dt);

private:
    float movementSpeed;
    float distanceFromShip;
    sf::Vector2f movement;
    EllipseShape dome;
	sf::VertexArray saucer; 
    sf::RectangleShape midline;
    sf::ConvexShape hitbox;

    void setAlienShipPoints(sf::ConvexShape * shape);
    void setSaucerPoints(sf::VertexArray * shape);

};
#endif