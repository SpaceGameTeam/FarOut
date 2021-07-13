// Change this #include to FarOut.h eventually
// #include "FarOut.h"

#ifndef ALIENSHIP
#define ALIENSHIP
#include "GameObject.h"
#include <math.h>


const int NUMPOINTS = 30;


// Ellipse class modeled after https://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
class EllipseShape : public sf:: Shape {
    public :
        explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0));
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
	void update(sf::Time dt);
    void move(sf::Time dt);

private:
    void setAlienShipPoints(sf::ConvexShape * shape);
    sf::ConvexShape body;
    EllipseShape dome;
    float movementSpeed;
    sf::Vector2f movement;
    sf::ConvexShape hitbox;

};
#endif