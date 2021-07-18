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

};





#endif