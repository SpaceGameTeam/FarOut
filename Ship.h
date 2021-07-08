#pragma once

#include <SFML/Graphics.hpp>
// Change this #include to FarOut.h eventually
#include "GameObject.h"


class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:
    sf::ConvexShape Body;

};