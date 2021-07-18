// Solar System class


#ifndef SOLARSYS 
#define SOLARSYS
#include "GameObject.h"
#include <math.h>

class Sun : public GameObject {
    public:
        Sun();
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
        Planet(int radius, int orbitDistance, sf::Color color, Sun* systemCenter);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void update(sf::Time dt);
        void move(sf::Time dt);

    private:
        sf::CircleShape mass;
        sf::CircleShape hitbox;
        int orbitDistance;
        float orbitAngle;
        sf::Vector2f movement;
        Sun* sun;
};





#endif