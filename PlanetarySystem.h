// Planetary System class


#ifndef PLSYS 
#define PLSYS
#include "GameObject.h"
#include <math.h>

class Star : public GameObject {
    public:
        Star();
        Star(int size, sf::Color outline, int outlineWidth, sf::Color fill, sf::Vector2f position);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void update(sf::Time dt);

    private:
        sf::CircleShape mass;
        sf::CircleShape hitbox;
        int radius;
};


class Planet : public GameObject {
    public:
        // Could add to these parameters texture, rings, moons
        Planet(int radius, int orbitDistance, sf::Color color, float movementFactor);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void update(sf::Time dt, sf::Vector2f systemCenter);
        void update(sf::Time dt);
        void move(sf::Time dt);

    private:
        sf::CircleShape mass;
        sf::CircleShape hitbox;
        int orbitDistance;
        float orbitAngle;
        sf::Vector2f movement;
        float movementSpeed;
        GameObject* star;
        sf::Vector2f center;
        float angleChange;
};


class PlanetarySystem : public GameObject {
    public: 
        PlanetarySystem(sf::Vector2f position, GameObject** systemObjects, int numObj);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void update(sf::Time dt);
    
    private:
        GameObject** gravityBoundObjects;
        int numObjects;
};


#endif