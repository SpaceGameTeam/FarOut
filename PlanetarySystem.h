// Planet and Star classes

#ifndef PLSYS 
#define PLSYS
#include "FarOut/FarOut.h"
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
        Planet(int radius, int orbitDistance, sf::Color color, float movementFactor);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void update(sf::Time dt, sf::Vector2f systemCenter);
        void update(sf::Time dt);

    private:
        sf::CircleShape mass;
        sf::CircleShape hitbox;
        int orbitDistance;
        float orbitAngle;
        float angleChange;
};
#endif