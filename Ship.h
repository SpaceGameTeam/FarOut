#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Ship : public GameObject {
public:
	Ship();

private:
    sf::ConvexShape Body;

};