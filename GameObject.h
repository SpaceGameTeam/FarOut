#pragma once

#include <SFML/Graphics.hpp>
#include "SystemClass.h"


class GameObject {
public:
	GameObject();

	virtual void update(sf::Time dt) = 0;

};
